// ref: http://apps.topcoder.com/wiki/display/tc/SRM+611

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

class ElephantDrinkingEasy{
public:
  int n;
  vector<string> sim;

  int simulate(int x0, int y0, int dx, int dy){
    int x = x0; int y = y0;

    while((0 <= x && x < n) && (0 <= y && y < n)){
      if(sim[y][x] == 'Y'){
        sim[y][x] = '#';
        return 1;
      }else if(sim[y][x] == '#'){
        break;
      }else{
        sim[y][x] = '#';
        x += dx;
        y += dy;
      }
    }

    return 0;
  }

  int maxElephants(vector <string> map){
    n = map.size();
    int mx = 0;

    for (int sub = 0; sub < 1 << (2 * n); sub++) {
      sim = map;
      int count = 0;

      for (int i = 0; i < 2 * n; i++) {
        if(sub >> i & 1){
          int x = i % n;
          int y = (i < n) ? 0 : n - 1;
          int dy = (i < n) ? 1 : -1;
          count += simulate(x, y, 0, dy);
        }
      }

      for (int i = 0; i < 2 * n; i++) {
        int x = (i < n) ? 0 : n - 1;
        int dx = (i < n) ? 1 : -1;
        int y = i % n;
        count += simulate(x, y, dx, 0);
      }
      mx = std::max(mx, count);
    }

    return mx;
  }
};

