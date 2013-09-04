#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) x = x + y; y = x - y; x = x - y;

#define J(i) ((i >> 8 ) - 1) / ((i & 255) + 1)
#define K(i) ((i >> 8 ) - 1) % ((i & 255) + 1)

int sort(int* a, int i){
  for(i = ((i * i) << 8) + i - 1; i >= (1 << 8); i = i - (1 << 8)){
    if(a[J(i)] > a[K(i)]){ SWAP(a[J(i)], a[K(i)]); }
  }
}

