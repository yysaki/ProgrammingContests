
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
#include <cstring>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class InterestingNumber{
public:
  string isInteresting(string x){
    int check[10];
    memset(check, 0, sizeof(check));
    for (int i = 0; i < (int)x.size(); i++) {
      check[x[i]-'0']++;
    }
    for (int i = 0; i < 10; i++) {
      if(check[i] != 0 && check[i] != 2) return "Not interesting";
    }

    for (int i = 0; i < (int)x.size(); i++) {
      int num = x[i] - '0';
      bool isInteresting = false;
      if(0<= i - (num + 1) && x[i - (num + 1)] == x[i]) isInteresting |= true;
      if(i + (num + 1) < x.size() && x[i + (num + 1)] == x[i]) isInteresting |= true;
      if(!isInteresting) return "Not interesting";
    }
    return "Interesting";
  }
};

