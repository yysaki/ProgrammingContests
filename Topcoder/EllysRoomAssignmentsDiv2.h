/**
 * SRM 577 div2 Mid
 * answer fixed
 * 抜けていた条件: Ellyが1位の時1.0を返す
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

class EllysRoomAssignmentsDiv2 {

public: 
  double getProbability(vector<string> ratings) {
    stringstream ss;
    vector<string>::iterator it;
    for(it = ratings.begin(); it != ratings.end(); it++){
      ss << *it;
    }
    vector<int> vec;
    while(!ss.eof()){
      int x;
      ss >> x;
      vec.push_back(x);
    }

    const int N = vec.size();
    const int R = (N%20==0) ? N/20 : N/20 + 1;

    const int elly_rate = vec[0];
    sort(vec.rbegin(), vec.rend());

    int elly_rank = 0:
      for(int i = 0; i < N; i++){
        if(elly_rate == vec[i]){
          elly_rank = i+1;
          break;
        }
      }

    return (elly_rank == 1) ? 1.0 
      : (elly_rank <= R)    ? 0.0
      :                       1.0 / (double)R;
  }

};
