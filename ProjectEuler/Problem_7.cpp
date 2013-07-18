#include <bitset>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long n){
  if(n == 1) return false; 
  if(n < 4) return true;
  if(n % 2 == 0) return false;
  if(n < 9) return true;
  if(n % 3 == 0) return false;

  long long r = (int)std::sqrt(n);
  for (long long f = 5; f <=r; f+=6) {
    if(n % f == 0) return false;
    if(n % (f+2) == 0) return false;
  }

  return true;
}

long long ans10001stPrime(){
  long long candidate = 2;
  int count = 1;
  for (long long j = candidate + 1;; j += 2) {
    if(isPrime(j)){
      candidate = j;
      count++;
      if(count == 10001){
        break;
      }
    }
  }

  return candidate;
}


int my10001stPrime(){
  const int num = 500000;
  std::bitset<num> flags;
  flags.reset();
  flags.set(0);
  flags.set(1);
  std::vector<int> primes;
  primes.push_back(2);
  for (int i = 0; i < 10000; i++) {
    const int prime = primes[i];
    for (int j = 1; prime*j < num; j++) {
      flags.set(prime * j);
    }

    for (int j = 0;; j++) {
      if(!flags[j]){
        primes.push_back(j);
        break;
      } 
    }
  }

  return primes[10001-1];
}

int main(){
  cout << ans10001stPrime() << endl;
  //  cout << my10001stPrime() << endl;

  return 0;
}
