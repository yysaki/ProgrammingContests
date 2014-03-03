// OK 37:44

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

class ORSolitaireDiv2{
public:
  int getMinimum(vector <int> numbers, int goal){
    const int N = 30;
    int flags[N];
    std::memset(flags, -1, sizeof(flags));

    vector<bool> tmp;
    int div = goal;
    while(div>0){
      tmp.push_back(div % 2 == 1 ? true : false);
      div /= 2;
    }
    for (int i = 0; i < (int)tmp.size(); i++) {
      if(tmp[tmp.size()-i-1]) flags[tmp.size()-i-1]++;
    }

    for (int j = 0; j < (int)numbers.size(); j++) {
      if((goal | numbers[j]) != goal) continue;

      tmp = vector<bool>();
      div = numbers[j];
      while(div>0){
        tmp.push_back(div % 2 == 1 ? true : false);
        div /= 2;
      }
      for (int i = 0; i < (int)tmp.size(); i++) {
        if(tmp[tmp.size()-i-1]) flags[tmp.size()-i-1]++;
      }
    }

    int mn = 2 << 20;
    for (int i = 0; i < N; i++) {
      if(flags[i] != -1) mn = std::min(mn, flags[i]);
    }

    return mn;
  }
};

