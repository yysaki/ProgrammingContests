
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

class FoxAndGomoku
{
public:
	string win(vector <string> board) {
    const int N = (int)board.size();
    const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    const int dy[8] = {0, 0, 1, -1, 1, -1 ,1, -1};

    for(int y = 0; y < N; ++y){
      for(int x = 0; x < N; ++x){
        for(int k = 0; k < 8; ++k){
          const int aim_x = x + dx[k] * 4;
          const int aim_y = y + dy[k] * 4;
          if(0 <= aim_x && aim_x < N && 0 <= aim_y && aim_y < N){
            for(int i = 0; i < 5; ++i){
              const int next_x = x + dx[k] * i;
              const int next_y = y + dy[k] * i;
              if(board[next_x][next_y] == 'o'){
                if(i == 4){
                  return "found";
                }
              }else{
                break;
              }
            }
          }
        }
      }
    }

		return "not found";
	}
};

