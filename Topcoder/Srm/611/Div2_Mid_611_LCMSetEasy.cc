// gcd()にバグがおり撃墜される

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

class LCMSetEasy{
public:
  vector<int> s;
  int x;

  long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
  }

  long long lcm(long long a, long long b){
    return (a * b) / gcd(a, b);
  }

  bool dfs(int i, long long num){
    if(num == x) return true;
    if(num > x) return false;
    if(i == (int)s.size()) return false;

    return dfs(i + 1, lcm(num, s[i])) || dfs(i + 1, num);
  }

  string include(vector <int> S, int x){
    s = S;
    this->x = x;
    return dfs(0, 1) ? "Possible" : "Impossible";
  }
};

