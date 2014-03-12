#include <iostream>

using namespace std;

class LeftAndRightHandedDiv2{
public:
  int count(string S){
    const int n = S.size();
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
      if(S[i] == 'R' && S[i+1] == 'L'){
        res++;
      }
    }
    return res;
  }
};

