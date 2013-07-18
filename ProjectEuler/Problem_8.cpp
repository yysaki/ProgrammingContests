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
#include <fstream>
using namespace std;

int main(){
  ifstream ifs("Problem_8.txt");
  int max = 0;
  char a1, a2, a3, a4, a5;
  a1 = a2 = a3 = a4 = a5 = '0';
  string buf = "";

  while(ifs >> buf){
    for(string::iterator it = buf.begin(); it != buf.end(); it++){
      a5 = a4;
      a4 = a3;
      a3 = a2;
      a2 = a1;
      a1 = *it;
      max = std::max(max, (a1-'0') * (a2-'0') * (a3-'0') * (a4-'0') * (a5-'0'));
    }
  }

  cout << max << endl;
  return 0;
}
