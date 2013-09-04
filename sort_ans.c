#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) x = x + y; y = x - y; x = x - y;
#define ORDER(x, y) if(x > y){ SWAP(x, y); }

#define J(i) (((i>>8)-1) / ((i&255)+1))
#define K(i) (((i>>8)-1) % ((i&255)+1))

int sort(int* a, int i){
  for(i = (i*i*256) + (i-1); i >= 256; i = i - 256){
    ORDER(a[J(i)], a[K(i)]);
  }
}
