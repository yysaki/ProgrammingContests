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

int specialPythagoreanTriplet(int num){
  int ans = -1;
  for (int i = 1; i <= num; i++) {
    for (int j = i + 1; j < num - i - j; j++) {
      const int k = num - i - j;
      if(i*i + j*j == k*k){
        ans = i * j * k;
        break;
      }
    }
    if(ans!=-1) break;
  }

  return ans;
}

int main(){
  cout << specialPythagoreanTriplet(1000) << endl;

  return 0;
}
