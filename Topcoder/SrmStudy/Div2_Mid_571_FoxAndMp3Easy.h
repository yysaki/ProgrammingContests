/**
 * Topcoder SRM 571 Div 2 Middle
 */
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
#include <cstdlib>
using namespace std;

class FoxAndMp3Easy {

public: 
  vector<string> playList(int n) {
    vector<string> vec;
    for(int i = 1; i <= n; i++){
      ostringstream os;
      os << i << ".mp3";
      vec.push_back(os.str());
    }

    sort(vec.begin(), vec.end());
    vector<string> ret;
    for(int i = 0; i < min((int)vec.size(), 50); i++){
      ret.push_back(vec[i]);
    }

    return ret;
  }

};
