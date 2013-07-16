#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int main(){
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

  cout << primes[10001-1] << endl;

  return 0;
}
