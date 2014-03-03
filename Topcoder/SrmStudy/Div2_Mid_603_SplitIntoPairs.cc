// OK ゼロの処理はいらなかったようだ 0:38:49

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

class SplitIntoPairs{
public:
  int makepairs(vector <int> A, int X){
    vector<int> plus, zero, minus;
    for (int i = 0; i < (int)A.size(); i++) {
      if(A[i] > 0){
        plus.push_back(A[i]);
      }else if(A[i] == 0){
        zero.push_back(A[i]);
      }else{
        minus.push_back(A[i]);
      }
    }
    std::sort(plus.begin(), plus.end());
    std::sort(minus.rbegin(), minus.rend());

    int res = (plus.size() / 2) + (minus.size() / 2);

    if((zero.size() % 2) == 0){
      res += zero.size() / 2;
      if((plus.size() % 2) == 1){ // implies (minus.size() % 2) == 1
        long long mul = plus[0] * minus[0];
        if(mul >= X){
          cout << " mul >= x" << endl;
          res += 1;
        }else if(zero.size() != 0){
          res += 1;
        }else{
          cout << " mul < x" << endl;
        }
      }
    }else{ // if((zero.size() % 2) == 1){
      res += (zero.size() / 2) + 1;
    }

    return res;
  }
};

