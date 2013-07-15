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
  int an = 1, an_1 = 1, an_2 = 0;
  int sum = 0;
  while(an < 4000000){
    an = an_1 + an_2;
    if(an%2 == 0){
      sum += an;
    }
    an_2 = an_1;
    an_1 = an;
  }
  cout << sum << endl;

  return 0;
}

