// 解けたがTLE 49:46
// 参考 http://apps.topcoder.com/wiki/display/tc/SRM+599 1:10:49

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

class BigFatInteger2{
public:
  map<int, int> primeFactorize(int arg){
    int divided = arg;
    map<int, int> prime;

    while(divided % 2 == 0){
      divided /= 2; prime[2]++;
    }

    while(divided % 3 == 0){
      divided /= 3; prime[3]++;
    }

    for (int i = 6; (i-1)*(i-1) <= divided; i += 6) {
      while(divided % (i-1) == 0){
        divided /= i-1; prime[i-1]++;
      }

      while(divided % (i+1) == 0){
        divided /= i+1; prime[i+1]++;
      }
    }

    if(divided != 1){
      prime[divided]++;
    }

    return prime;
  }

  string isDivisible(int A, int B, int C, int D){
    map<int, int> a_prime = primeFactorize(A);
    map<int, int> c_prime = primeFactorize(C);

    map<int, int>::const_iterator a_it = a_prime.begin();
    map<int, int>::const_iterator c_it = c_prime.begin();

    while(c_it != c_prime.end()){
      if(a_it == a_prime.end()){
        return "not divisible";
      }else if(a_it->first == c_it->first){
        const int x = a_it->first;
        long long ab = (long long)a_prime[x] * (long long)B;
        long long cd = (long long)c_prime[x] * (long long)D;
        if(ab < cd){
          return "not divisible";
        }
        a_it++; c_it++;
      }else if(a_it->first < c_it->first){
        a_it++;
      }else{
        return "not divisible";
      }
    }

    return "divisible";
  }
};

