/**
 * SRM 567 Div2 easy
 * ëSíTçı
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
using namespace std;

class NinjaTurtles {

public:
  int countOpponents(int P, int K) {
    int max = 10000000;
    int ans = -1;
    for(int i = 1;i < max; i++){
      if(P==i/K + i/K + i/K + i/3){
        ans = i;
        break;
      }
    }
    return ans;
  }

};
