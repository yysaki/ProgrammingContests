
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class GooseInZooDivTwo {
  int H, W, D;
  set< vector<string> > dict;

  bool isEnd(vector<string> f){
    for (int y = 0; y < H; y++){
      for (int x = 0; x < W; x++){
        if(f[y][x]=='v'){
          return false;
        }
      }
    }
    return true;
  }

  vector<string> dfs2(vector<string> f, int x, int y, char b){
    for(int j = 0; j < H; j++){
      for (int i = 0; i < W; i++) {
        if(abs(x-i) + abs(y-j) <= D){
          f[j][i] = b;
          f = dfs2(f, i, j, b);
        }
      }
    }
    return f;
  }

  void dfs(vector<string> f){
    int i, j;
    if(isEnd(f)){
      dict.insert(f);
      return;
    }
    
    int x, y;
    for (j = 0; j < H; j++){
      for (i = 0; i < W; i++){
        if(f[j][i]=='v'){
          x = i;
          y = j;
          break;
        }
      }
    }

    const char bird[] = {'g', 'd'};
    for(int b = 0; b < 2; b++){
      dfs(dfs2(f, x, y, bird[b]));
    }
  }

public:
	int count(vector <string> field, int dist) {
    dict.clear();
    H = field.size();
    W = field[0].size();
    D = dist;

    bool isEmpty = true;
    for (int y = 0; y < H; y++){
      for (int x = 0; x < W; x++){
        if(field[y][x]=='v'){
          isEmpty = false; 
        }
      }
    }
    if(isEmpty) return 0;

    dfs(field);

		return dict.size();
	}
};

