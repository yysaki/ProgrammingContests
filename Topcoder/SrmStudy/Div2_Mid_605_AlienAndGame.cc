// give up 1:23:54
// 参考 http://apps.topcoder.com/wiki/display/tc/SRM+605 1:52:12

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

class AlienAndGame{
public:
  int getNumber(vector <string> board){
    const int w = board.size(), h = board[0].size();
    for (int l = std::min(w, h); l >= 2; l--) {
      for (int i = 0; i + l <= w; i++) {
        for (int j = 0; j + l <= h; j++) {
          bool good = true;
          for (int x = i; x < i + l; x++) {
            bool isWhite = true, isBlack = true;
            for (int y = j; y < j + l; y++) {
              isWhite &= (board[x][y] == 'W');
              isBlack &= (board[x][y] == 'B');
            }
            good &= ( isWhite != isBlack );
          }
          if(good) return l*l;
        }
      }
    }
    return 1;
  }

  /* failed to finish
  vector<string> b;
  int getWidth(int i, int jj){
    int ans = 0;
    const char color = b[i][jj];
    for (int j = jj; j < (int)b[0].size(); j++) {
      ++ans;
      if(b[i][j] != color) break;
    }
    return ans;
  }

  int getNumber(vector <string> board){
    b = board;

    int res = 1;
    for (int i = 0; i < (int)b.size(); i++) {
      for (int j = 0; j < (int)b[0].size(); j++) {
        int width = b.size();
        for(int k = 0; k + i < (int)b.size(); k++) {
          width = std::min(width, getWidth(i+k, j));
          if(width <= k+1) break;
          if(k + j == (int)b[0].size()){
            width = k -1; break;
          }
        }
        std::cout << width * width << " ";

        res = std::max(res, width * width);
      }
      std::cout << std::endl;
    }


    return res;
  }
  */ 
};

