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

class MagicStonesStore {

	public: string ableToDivide(int n) {
		bool primes[2*n+1];
		for(int i=0;i<2*n+1;i++){
			primes[i] = true;
		}
		primes[0] = false;
		primes[1] = false;
		for(int i=2;i<n+1;i++){
			if(primes[i]){
				for(int j=i+1;j<2*n+1;j++){
					if(j%i==0){
						primes[j] = false;
					}
				}
			}
		}
		for(int i=0;i<2*n+1;i++){
			if(primes[i]&&primes[2*n-i]){
				return "YES";
			}
		}

		return "NO";
	}

};
