#include <stdio.h>
#include <stdlib.h>

#define ATTACK(x, y)  printf("%s に %d ポイントのダメージを与えた！！\n", x, y)


int sort(int* a, int i){
}  

int main() {
  int array[5] = {1, 5, 3, 2, 4};
  int i;
  for(i = 0; i < 5; ++i){
    printf("%d\n", array[i]);
  }
  sort(array, 3); /* => {1, 3, 5, 2, 4} */
 
  for(i = 0; i < 5; ++i){
    printf("%d\n", array[i]);
  }

}
