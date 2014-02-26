// 方針ミスで間に合わず

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

class TheMatrix{
public:

  int H, W;
  vector<string> b;

  bool isChess(int x1, int y1, int x2, int y2){
    const char color = b[y1][x1];
    for (int i = x1; i <= x2; i++) {
      for (int j = y1; j <= y2; j++) {
        if(!(std::abs(b[j][i] - color) == (j - y1 + i -x1) % 2)){
          return false;
        }
      }
    }
    return true;
  }

  int MaxArea(vector <string> board){
    H = board.size();
    W = board[0].size();
    b = board;
    int ans = 0;

    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        for (int j = y; j < H; j++) {
          for (int i = x; i < W; i++) {
            if(isChess(x,y,i,j)){
              ans = std::max(ans, (i-x+1) * (j-y+1));
            }
          }
        }
      }
    }

    return ans;
  }
};

