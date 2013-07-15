#include <algorithm>
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
using namespace std;

int main(){
  long long num = 600851475143;
  vector<long long> primes;
  long long largestPrime = 0;

  for (long long i = 2; i <= num; i++) {
    bool isPrime = true;
    for(vector<long long>::iterator it = primes.begin(); it != primes.end(); it++){
      if(i % *it == 0){
        isPrime = false;
      }
    }
    if(isPrime){
      primes.push_back(i);
      if(num % i == 0){
        largestPrime = i;
        while(num % i == 0){
          num /= i;
        }
      }
    }
  }
  
  cout << largestPrime << endl;

  return 0;
}

