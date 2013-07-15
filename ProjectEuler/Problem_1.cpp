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
  int count = 0;
  for (int i = 1; i < 1000; i++) {
    if(i%3 == 0 || i%5 == 0){
      count += i;
    }
  }

  cout << count << endl;
  return 0;
}

