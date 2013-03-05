#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class GogoXBallsAndBinsEasy {
  public: int solve(vector<int> T) {
    int N = T.size();

    vector<int> S = T;
    sort(S.begin(),S.end(), greater<int>());

    int ret = 0;
    for(int i=0;i<N;i++){
      ret += max(S[i]-T[i],0);
    }


    return ret;
  }

};
