#include <algorithm>
#include <bitset>
#include <iostream>
#include <sstream>
#include <limits>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <boost/tuple/tuple.hpp>
#include <cstdlib>
#include <cmath>
using namespace std;

const int PRIME_MAX = 100000;

vector<int> sieve(){
  bitset<PRIME_MAX> flags;
  flags.reset();
  flags.set(1);
  for(int i = 0; i < PRIME_MAX; i += 2){
    flags.set(i);
  }

  vector<int> ret;
  ret.push_back(2);

  for(long long i = 3; i < PRIME_MAX; i += 2){
    if(!flags[i]){
      ret.push_back(i);
      for (long long j = i; j < PRIME_MAX; j += i) {
        flags.set(j);
      }
    }
  }

  return ret;
}

long long highlyDivisibleTriangularNumber(){
  const vector<int> primes = sieve();
  long long triangleNumber = 0;

  for (long long i = 1;; i++) {
    triangleNumber += i;
    cout << i << ": " << triangleNumber << " => ";
    vector<int> counts;
    for(vector<int>::const_iterator it = primes.begin(); it!=primes.end(); it++){
      if(*it > sqrt(triangleNumber)){
        break;
      }
      int count = 0;
      for(long long product = *it; product <= triangleNumber; product *= *it){
        if(triangleNumber % product == 0){
          count++;
        }else{
          break;
        }
      }
      counts.push_back(count);
    }

    int ans = 1;
    for(vector<int>::iterator it = counts.begin(); it!=counts.end(); it++){
      ans *= *it + 1;
    }
    cout << ans << endl;

    if(ans > 500) break;
  }

  return triangleNumber;
}

int main(){
  cout << highlyDivisibleTriangularNumber() << endl;
  return 0;
}
