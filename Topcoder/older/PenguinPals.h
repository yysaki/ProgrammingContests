/**
 * SRM 566 Div2 Mid study
 * [editorial](http://apps.topcoder.com/wiki/display/tc/SRM+566#12355)
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

class PenguinPals {
public:
  int findMaximumMatching(string colors) {
    bool found = true;
    int matches = 0;
    while(found && colors.size()>=2){
      found = false;
      if(colors[0]==colors[colors.size()-1]){
        found = true;
        matches++;
        colors = colors.substr(1,colors.size()-2);
      }
      int i = 0;
      while((int)colors.size() >= i + 2){
        if(colors[i]==colors[i+1]){
          found = true;
          colors = colors.substr(0, i) + colors.substr(i+2);
          matches++;
        }else{
          i++;
        }
      }
    }
    if(colors.size() > 1){
      matches += (colors.size()-2)/2;
    }

    return matches;
  }

};
