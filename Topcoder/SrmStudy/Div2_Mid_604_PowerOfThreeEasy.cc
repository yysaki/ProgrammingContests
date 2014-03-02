// Brute Forceな幅優先探索でOK 31:37
// ref: http://apps.topcoder.com/wiki/display/tc/SRM+604
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

class PowerOfThreeEasy {
public:
  int step;
  int ansx, ansy;

  int power(int k){
    int ret = 1;
    for (int i = 0; i < k; i++) {
      ret = ret * 3;
    }
    return ret;
  }

  bool dfs(int k, int x, int y){
    if(k == step + 1) return (x == ansx) && (y == ansy);

    return (dfs(k + 1, x + power(k), y) || dfs(k + 1, x, y + power(k)));
  }

  string ableToGet(int x, int y) {
    step = 0; ansx = x; ansy = y;
    if(x == 0 && y == 0) return "Possible";

    bool isReachable = false;
    int sum = 0;
    while(sum < x+y){
      sum += power(step);
      if(sum == x+y){
        isReachable = true;
        break;
      }
      step++;
    }
    if(!isReachable) return "Impossible";

    return dfs(0, 0, 0) ? "Possible" : "Impossible";
  }
};

