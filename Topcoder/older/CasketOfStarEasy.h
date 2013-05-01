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

class CasketOfStarEasy {

public:
	int maxEnergy(vector<int> weight) {
		const int N = weight.size();
		int ans = 0;
		// 1’Ê‚è, æ“ª‚©‚ç
		int tmp = 0;
		for(int i=2;i<N-j;i++){ // width‚Ì‘‰Á
			tmp += weight[0] * weight[j+i];
		}
		if(ans<tmp) ans = tmp;
		cout << ans << endl;
		return ans;
	}

};
