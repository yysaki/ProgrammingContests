#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) x = x + y; y = x - y; x = x - y;
#define ORDER(x, y) if(x > y){ SWAP(x, y); }

#define NIL -1
#define ISNIL(num) (num > 0) ? NIL : num 


int sort(int* a, long i){
  for(i = (i*i*256) + (i-1); i >= 256; i--){
    ORDER(a[J(i)], a[K(i)]);
  }
}

int main() {
  int array[5] = {1, 5, 3, 2, 4};
  int i;
  for(i = 0; i < 5; ++i){
    printf("%d", array[i]);
  }
  printf("\n");
  sort(array, 3); /* => {1, 3, 5, 2, 4} */
 
  for(i = 0; i < 5; ++i){
    printf("%d", array[i]);
  }
  printf("\n");
}
