// "‹ó‚«—Ìˆæ‚ðì‚Á‚Ä‚Í‚¢‚¯‚È‚¢"ƒ‹[ƒ‹‚ðŒ©“¦‚µ
// System> yysaki has submitted the 250-point problem for 128.57 points
// http://topcoder.g.hatena.ne.jp/say_hello_to_okaoka/20111118
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

class ShippingCubes {
//	int maxSize(int x){
//		if(x<3){
//			return 0;
//		}else if(x%3==0){
//			return (x/3)*(x/3)*(x/3);
//		}else if(x%3==1){
//			return (x/3)*(x/3)*(x/3+1);
//		}
//		else{
//			return (x/3)*(x/3+1)*(x/3+1);
//		}
//	}
//	public: int minimalCost(int N) {
//		for(int i=3;i<=200;i++){
//			cout << "i:" << i << " ms:" << maxSize(i) << endl;
//			if(maxSize(i)>=N) return i;
//		}
//		return -1;
//	}
public:
	int minimalCost(int N) {
		int ans = numeric_limits<int>::max();
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				for(int k=1;k<=N;k++){
					if(i*j*k==N){
						ans = min(ans, i+j+k);
					}
				}
			}
		}
		return ans;
	}
};
