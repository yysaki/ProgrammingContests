// give up
// subsequene(部分列)の判定: two-pointers問題
// ref: http://apps.topcoder.com/wiki/display/tc/SRM+597

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

class LittleElephantAndString{
public:
  bool subSequence(const string& P, const string& Q){
    int i = 0;
    for (int j = 0; j < (int)P.size(); j++) {
      while(i < (int)Q.size() && Q[i] != P[j]){
        i++;
      }

      if(i >= (int)Q.size()){
        return false;
      }else{
        i++;
      }
    }

    return true;
  }

  int getNumber(string A, string B){
    if(multiset<char>(A.begin(), A.end()) != multiset<char>(B.begin(), B.end())){
      return -1;
    }

    const int n = A.size();

    for (int i = 0; i < n; i++) {
      cout << B.substr(i) << endl;
      if(subSequence(B.substr(i), A)){
        return i;
      }
    }

    return n;
  }

//  mine
//  int getNumber(string A, string B){
//    const int n = A.size();
//    {
//      string sortedA = A, sortedB = B;
//      sort(sortedA.begin(), sortedA.end());
//      sort(sortedB.begin(), sortedB.end());
//      if(sortedA != sortedB) return -1;
//    }
//
//    // たかだかn-1回の変形でAからBを作れる
//
//    return int();
//  }
};

