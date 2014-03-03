// 22:32

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

class WinterAndCandies{
public:
  // mine
  int getNumber(vector <int> type){
    vector<int> t = type;
    std::sort(t.rbegin(), t.rend());
    const int ub = t[0];
    int type_nums[ub];
    std::memset(type_nums, 0, sizeof(type_nums));
    for (int i = 0; i < (int)t.size(); i++) {
      type_nums[t[i] - 1]++;
    }

    int res = 0;
    for (int i = 0; i < ub; i++) {
      int mul = 1;
      for (int j = 0; j <= i; j++) {
        mul *= type_nums[j];
      }
      res += mul;
    }

    return res;
  }

//  //answer
//  int getNumber(vector <int> type){
//    map<int, int> cnt;
//    for (int i = 0; i < (int)type.size(); i++) {
//      cnt[type[i]++];
//    }
//    int p = 1;
//    int res = 0;
//    // map<int, int>のデフォルト値が0なのでこれだと常に0では？
//    for (int k = 0; k < (int)type.size(); k++) {
//      p *= cnt[k];
//      res += p;
//    }
//    return res;
//  }
};

