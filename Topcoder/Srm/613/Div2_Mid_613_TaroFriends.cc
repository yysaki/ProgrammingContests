// Failed System Test
// ref http://community.topcoder.com/stat?c=problem_solution&rm=321057&rd=15846&pm=13005&cr=23306901

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

class TaroFriends{
public:
  int getNumber(vector <int> coordinates, int X){
    vector<int> c = coordinates;
    const int n = c.size();
    if(n == 1) return 0;

    int res = 1 << 30;
    const int dx[4] = {1, 1, -1, -1};
    const int dy[4] = {1, -1, 1, -1};
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = 0; k < 4; k++) {
          const int left = min(c[i] + X * dx[k], c[j] + X * dy[k]);
          const int right = max(c[i] + X * dx[k], c[j] + X * dy[k]);
          bool ok = true;
          for (int l = 0; l < n; l++) {
            if(l != i && l != j){
              if((left <= c[l] + X && c[l] + X <= right) ||
                 (left <= c[l] - X && c[l] - X <= right)){
                continue;
              }else{
                ok = false;
              }
            }
          }
          if(ok){
            res = min(res, right - left);
          }
        }
      }
    }

    return res;
  }
};

