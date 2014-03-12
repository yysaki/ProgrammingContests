
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

class EmoticonsDiv2{
public:
  map<int, int> getPrimes(int arg){
    int divided = arg;
    map<int, int> primes;
    for (int i = 2; i * i <= divided; i++) {
      if(divided % i == 0){
        int count = 0;
        while(divided % i == 0){
          divided /= i;
          count++;
        }
        primes[i] = count;
      }
    }

    if(divided != 1){
      primes[divided] = 1;
    }

    return primes;
  }

  int printSmiles(int smiles){
    map<int, int> primes = getPrimes(smiles);

    int res = 0;
    for(map<int, int>::const_iterator it = primes.begin(); it != primes.end(); ++it){
      res += it->first * it->second;
    }

    return res;
  }
};

