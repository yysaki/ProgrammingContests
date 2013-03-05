/*
 * SRM 529 div 2 Easy Score 216.x
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

class PairingPawns {
	public: int savedPawnCount(vector<int> start) {
		int ret = 0;
		vector<int>::reverse_iterator it;
		for(it=start.rbegin();(it+1)!=start.rend();it++){
			ret = (ret+(*it))/2;
		}
		ret += start[0];
		return ret;
	}

};
