// ref:http://apps.topcoder.com/wiki/display/tc/SRM+590
// 全探索 -> 深さ優先探索
// idea: '.'に接触した'o'を探索済みとし残りをカウントする

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
#include <string.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class FoxAndGo {
public:
  vector<string> B; int N;
  bool visited[21][21];

  void dfs(int x, int y){
    if(visited[x][y]) return;

    visited[x][y] = true;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    for(int r = 0; r < 4; ++r){
      const int nx = x + dx[r], ny = y + dy[r];
      if(0 <= nx && nx < N && 0 <= ny && ny < N){
        if(B[nx][ny] == 'o'){
          dfs(nx, ny);
        }
      }
    }
  }

  int scoreIt(){
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        if(B[i][j] == '.'){
          dfs(i,j);
        }
      }
    }

    int count = 0;
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        if(B[i][j] == 'o' && !visited[i][j]){
          count++;
        }
      }
    }

    return count;
  }

	int maxKill(vector <string> board) {
    B = board;
    N = (int)board.size();

    int mx = 0;
    for(int x = 0; x < N; ++x){
      for(int y = 0; y < N; ++y){
        if(B[y][x] == '.'){
          B[y][x] = 'x';
          mx = max(mx, scoreIt());
          B[y][x] = '.';
        }
      }
    }
 
		return mx; 
	}
};

