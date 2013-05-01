// System> yysaki has submitted the 500-point problem for 184.86 points
// 1h
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class MagicDiamonds {
	public:
	bool isPrime(long long n){
		if(n<2){
			return false;
		}else if(n==2){
			return true;
		}else if(n%2==0){
			return false;
		}else{
			for(int i=3;i<sqrt(n);i+=2){
				if(n%i==0){
					return false;
				}
			}
			return true;
		}
	}
	long long minimalTransfer(long long n) {
		if(n==3){
			return 3LL;
		}
		return (isPrime(n)) ? 2LL : 1LL;
	}
};
