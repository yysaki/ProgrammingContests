
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

typedef long long ll;

class LongLongTripDiv2{
public:
  string isAble(long long D, int T, int B){
    const ll d = D, t = T, b = B;

    int l = 0;
    int r = 0;
    for (int i = 0; i <= T; i++) {
      if(d - (b * i) < 0) break;
      r = i;
    }

    int lb = -1;
    int rb = -1;
    while(l <= r && !(l == lb && r == rb)){
      const int i = (l + r) / 2;
      if(d - (b * i) == t - i) return "Possible";

      lb = l; rb = r;
      if(d - (b * i) > t - i){
        l = i + 1;
      }else{
        r = i;
      }
    }
    return "Impossible";
  }
};

