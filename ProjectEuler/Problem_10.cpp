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
#include <bitset>
using namespace std;

const int NUM = 2000000;

long long summationOfPrimes(){
  std::bitset<NUM> flags;
  flags.reset();
  flags.set(0);
  flags.set(1);

  long long ans = 0;
  int prime;
  for (int i = 2; i < NUM; i++) {
    if(!flags[i]){
      ans += i;
      prime = i;
    }

    for(int j = prime; j < NUM; j += prime){
      flags.set(j);
    }
  }

  return ans;
}

int main(){
  cout << summationOfPrimes() << endl;
  return 0;
}
