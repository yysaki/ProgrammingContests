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
  int ans = 0;
  for (int i = 1;; i++) {
    bool isDivisible = true;
    for (int j = 1; j < 20; j++) {
      if(i%j!=0){
        isDivisible = false;
        break;
      }
    }

    if(isDivisible){
      ans = i;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
