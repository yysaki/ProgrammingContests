/**
 * Topcoder SRM 571 Div 2 Easy
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

class FoxAndGame {

public:
  int countStars(vector<string> result) {
    int count = 0;
    for(int i = 0; i < (int)result.size(); i++){
      for(int j = 0; j < (int)result[i].size(); j++){
        if(result[i][j] == 'o'){
          count++;
        }
      }
    }

    return count;
  }

};
