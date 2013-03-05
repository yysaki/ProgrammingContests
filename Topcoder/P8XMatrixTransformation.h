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

class P8XMatrixTransformation {

	public: string solve(vector<string> original, vector<string> target) {
		int height = original.size();
		int width = original[0].size();

		if(height!=target.size()){ std::abort(); }
		if(width!=target[0].size()){ std::abort(); }

		int zero_o = 0;
		int zero_t = 0;

		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(original[i][j]=='0'){
					zero_o++;
				}
				if(target[i][j]=='0'){
					zero_t++;
				}
			}
		}

		return (zero_o==zero_t) ? "YES" : "NO";
	}

};
