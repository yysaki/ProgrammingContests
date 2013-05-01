/**
 * SRM 560 Div2 Mid
  * 　貪欲法, 30分でクリア！
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class TomekPhone {

  public: int minKeystrokes(vector<int> frequencies, vector<int> keySizes) {
    const int F = frequencies.size();
    const int K = keySizes.size();

    int maxI = 0;
    for(int i=0;i<K;i++) if(maxI<keySizes[i]){
      maxI = keySizes[i];
    }
    if(accumulate(keySizes.begin(),keySizes.end(),0) < F) return -1;

    sort(frequencies.begin(), frequencies.end());

    int ans = 0;
    for(int i=0;i<maxI;i++){
      for(int j=0;j<K;j++){
        if(keySizes[j]>0){
          keySizes[j]--;
          ans += frequencies[frequencies.size()-1] * (i+1);
          frequencies.pop_back();
        }
        if(frequencies.size()==0) break;
      }
      if(frequencies.size()==0) break;
    }

    return ans;
  }

};
