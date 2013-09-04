/* usage: befunge [-debug] file */

/*
  - basically befunge-93
  - size of programs is limited to 100x100
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 1000
#define PROG_SIZE 1000

int stack[STACK_SIZE], sp;      /* assume zero initialized */
char program[PROG_SIZE][PROG_SIZE];
int pc_x, pc_y, direction;      /* right, left, down, up */

int debug;

void error(char *str)
{
    fprintf(stderr, "ERROR: %s\n", str);
    exit(1);
}

int s_push(int x)
{
    if(sp == STACK_SIZE)
        error("stack overflow");
    return stack[sp++] = x;
}

int s_pop()
{
    if(sp == 0)
        error("stack underflow");
    return stack[--sp];
}

void s_dump()
{
    int i = sp;
    while(--i)
        printf("%d ", stack[i]);
    puts("");
}

int s_empty()
{
    return sp == 0;
}

void read_progam(char *filename)
{
    int y; FILE *fp;

    if(!(fp = fopen(filename, "r")))
        error("cannot open file");

    for(y = 0;
        y < 100 && fgets(program[y], PROG_SIZE, fp);
        y++)
    if(y == 100)
        error("the program contains too many lines");

    fclose(fp);
}

void pc_next()
{
    switch(direction)
    {
      case 0:
        if((++pc_x) >= PROG_SIZE)
            pc_x = 0;
        break;
      case 1:
        if((--pc_x) < 0)
            pc_x = PROG_SIZE - 1;
        break;
      case 2:
        if((++pc_y) >= PROG_SIZE)
            pc_y = 0;
        break;
      case 3:
        if((--pc_y) < 0)
            pc_y = PROG_SIZE - 1;
        break;
    }
}

void execute()
{
    int rop, lop;

    while(1)
    {
        switch(program[pc_y][pc_x])
        {
          case '"':
            pc_next();
            while(program[pc_y][pc_x] != '"')
            {
                s_push(program[pc_y][pc_x]);
                pc_next();
            }
            break;

          case '0': case '1': case '2': case '3':
          case '4': case '5': case '6': case '7':
          case '8': case '9':
            s_push(program[pc_y][pc_x] - '0');
            break;

          case ':':
            s_push(s_push(s_pop()));
            break;

          case '\\':
            rop = s_pop(); lop = s_pop();
            s_push(rop); s_push(lop);
            break;

          case '$':
            s_pop();
            break;

          case '+':
            s_push(s_pop() + s_pop());
            break;

          case '-':
            rop = s_pop(); lop = s_pop();
            s_push(lop - rop);
            break;

          case '*':
            s_push(s_pop() * s_pop());
            break;

          case '/':
            rop = s_pop(); lop = s_pop();
            s_push(lop / rop);
            break;

          case '%':
            rop = s_pop(); lop = s_pop();
            s_push(lop % rop);
            break;

          case '!':
            s_push(!s_pop());
            break;

          case '`':
            rop = s_pop(); lop = s_pop();
            s_push(lop > rop);
            break;

          case '_':
            direction = s_pop() ? 1 : 0;
            break;

          case '|':
            direction = s_pop() ? 3 : 2;
            break;

          case '>':
            direction = 0;
            break;

          case '<':
            direction = 1;
            break;

          case 'v':
            direction = 2;
            break;

          case '^':
            direction = 3;
            break;

          case '?':
            direction = rand() % 4;
            break;

          case '#':
            pc_next();
            break;

          case '@':
            return;

          case '.':
            printf("%d ", s_pop());
            break;

          case ',':
            putchar(s_pop());
            break;

          case '&':
            scanf("%d", &rop);
            s_push(rop);
            break;

          case '~':
            s_push(getchar());
            break;

          case 'g':
            lop = s_pop();
            rop = s_pop();
            s_push(program[lop][rop]);
            break;

          case 'p':
            lop = s_pop();
            rop = s_pop();
            program[lop][rop] = s_pop();
            break;
        }

        if(debug &&
           program[pc_y][pc_x] &&
           strchr("\"1234567890:\\$+-*/%!`|_><^v?#@.,&~gp",
                   program[pc_y][pc_x]))
        {
            int i = sp;
            printf("\t%c", program[pc_y][pc_x]);
            printf(" (%2d, %2d)", pc_y, pc_x);
            printf(" stack: ");
            while(i--) printf("%d ", stack[i]);
            puts("");
        }

        pc_next();
    }
}

int main(int argc, char **argv)
{
    if(argc < 2)
        error("usage: befunge [-debug] file");

    debug = !strcmp(argv[1], "-debug");
    read_progam(argv[1 + debug]);

    execute();
    puts("");

    return 0;
}
