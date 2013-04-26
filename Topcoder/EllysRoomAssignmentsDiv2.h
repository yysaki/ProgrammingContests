/**
 * SRM 577 div2 Mid
 * answered
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
    vector<string>::iterator s_it;
    for(s_it = ratings.begin(); s_it != ratings.end(); s_it++){
      ss << *s_it;
    }
    vector<int> vec;
    while(!ss.eof()){
      int x;
      ss >> x;
      vec.push_back(x);
    }

    const int N = vec.size();
    int R = (N%20==0) ? N/20 : N/20 + 1;

    int ellyRate = vec[0];
    sort(vec.rbegin(), vec.rend());

    for(int i = 0; i < N; i++){
      if(ellyRate == vec[i]){
        if(i+1<= R) return 0.0;
        break;
      }
    }

    return 1.0 / (double)R;
  }

};
