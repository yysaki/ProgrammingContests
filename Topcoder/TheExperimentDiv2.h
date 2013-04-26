/**
 * SRM 576 div2 easy
 * Practice for exercise
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

class TheExperimentDiv2 {

public: 
	vector<int> determineHumidity(vector<int> intensity, int L, vector<int> leftEnd) {
	  const int iLen = intensity.size();
	  const int lLen = leftEnd.size();
	  vector<int> ret(lLen);
	  for(int i=0; i< lLen; i++) ret[i] = 0;

	  for(int i=0; i < iLen; i++){
	    for(int l=0; l < lLen; l++){
	      if(leftEnd[l] <= i && i < leftEnd[l] + L){
	        ret[l] += intensity[i];
	        break;
	      }
	    }
	  }
		return ret;
	}

};
