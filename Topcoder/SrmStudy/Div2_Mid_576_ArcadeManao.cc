/**
 * SRM 576 div 2 Mid for study
 * dfs
 */
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

class ArcadeManao
{
  vector<string> l;
  int L, N, M;
public:

  void dfs(int x, int y){
    l[x][y] = 'o';
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
      const int yd = y + dy[i];
      if(0 <= yd && yd < M){
        for (int j = 1; j <= L; j++){
          const int xd = x + dx[i] * j;
          if(0 <= xd && xd < N && l[xd][yd] == 'X'){
            dfs(xd, yd);
          }
        } 
      }
    }
  }


  int shortestLadder(vector <string> level, int coinRow, int coinColumn)
  {
    N = level.size();
    M = level[0].size();

    for(L = 0; L <= N; L++){
      l = level;
      dfs(N-1, M-1);
      if(l[coinRow-1][coinColumn-1]=='o'){
        return L;
      }
    }

    return -1;
  }
};

