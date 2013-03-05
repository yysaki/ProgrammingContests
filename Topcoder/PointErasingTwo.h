#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

bool compGeq(int a, int b){
	return a<
			b;
}
class PointErasingTwo {
	public:
//	int max(int a, int b){
//		return (a>=b) ? a : b;
//	}
//	int min(int a, int b){
//		return (a<=b) ? a : b;
//	}

	int getMaximum(vector<int> y) {
		int n = y.size();
		int ans = -1;
		int xa, xb, it, count;
		for(xa=0;xa<n-1;xa++){
			for(xb=xa+1;xb<n;xb++){
				count = 0;
				for(it = xa+1;it!=xb;it++){
					if(min(y[xa],y[xb], compGeq)<y[it] && y[it]<max(y[xa],y[xb])){
						count++;
					}
				}
				if(ans<=count){
					ans = count;
				}
			}
		}

		return ans;
	}

};
