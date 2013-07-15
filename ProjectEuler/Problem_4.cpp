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

bool isPalindrome(int num){
  std::ostringstream ss;
  ss << num;
  const string str = ss.str();

  for (int i = 0; i < (int)str.size() / 2; i++) {
    if(str[i] != str[(int)str.size()-i-1]){
      return false;
    }
  }

  return true;
}

int main(){
  int ans = -1;
  for (int i = 100; i < 1000; i++) {
    for (int j = 100; j < 1000; j++) {
      if(isPalindrome(i*j)){
        ans = std::max(ans, i*j);
      }
    }
  } 

  cout << ans << endl;
  return 0;
}
