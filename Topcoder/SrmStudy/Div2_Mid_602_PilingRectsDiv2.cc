// O(2^n), n=50の全探索を書いてしまいTLE 38:04
// 参考: http://apps.topcoder.com/wiki/display/tc/SRM+602 1:04:32
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

class PilingRectsDiv2{
public:
  int getmax(vector <int> X, vector <int> Y, int limit){
    int mx = -1;
    for (int w = 1; w <= limit && limit / w <= limit; w++) {
      int h = (limit + w - 1) / w;
      int r = 0;
      for (int i = 0; i < (int)X.size(); i++) {
        if((w <= X[i] && h <= Y[i]) || (w <= Y[i] && h <= X[i])){
          r++;
        }
      }
      if(r != 0){
        mx = std::max(mx, r);
      }
    }
    return mx;
  }

// mine
//  int n;
//  vector<int> x;
//  vector<int> y;
//  int limit;
//
//  int dfs(int i, int r, int minX, int minY){
//    if(i == n){
//      return (minX * minY >= limit) ? r : -1;
//    }
//
//    return std::max(dfs(i+1, r, minX, minY), 
//                    dfs(i+1, r+1, std::min(minX, x[i]), std::min(minY, y[i])));
//  }
//
//  int getmax(vector <int> X, vector <int> Y, int limit){
//    this->limit = limit;
//    const int MAX = 2 << 20;
//    n = X.size();
//    for (int i = 0; i < n; i++) {
//      if(X[i] <= Y[i]){
//        x.push_back(X[i]);
//        y.push_back(Y[i]);
//      }else{
//        x.push_back(Y[i]);
//        y.push_back(X[i]);
//      }
//    }
//
//    return dfs(0, 0, MAX, MAX);
//  }
};

