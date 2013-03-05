// Às‚ªŠÔ“à‚ÉI‚í‚ç‚È‚¢À‘•
// ‰ğŒó•â‚ğ•À‚×‚½”—ñ‚ğ’²‚×‚é‚Æ@{1,2,3,5,7,10,13,17,21,...}
// a(n+1) = a(n) + floor(n/2)+1, a(0) = 1

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

class MagicCandy {
private:
	//	typedef vector<int> vec_t;
public:
	//	int whichOne(int n) {
	//		vec_t s;
	//		for(int i=1;i*i<=n;i++){
	//			s.push_back(i*i);
	//		}
	//		vec_t c;
	//		for(int j=1;j<=n;j++){
	//			c.push_back(j);
	//		}
	//		while(c.size()!=1){
	//			for(int i=0;i<c.size();i++){
	//				cout << c[i] << " ";
	//			}
	//			cout << endl;
	//
	//			for(int i=0;i<s.size();i++){
	//				if(s[i]<=c.size()){
	//					c[s[i]-1] = -1;
	//				}
	//			}
	//			vec_t::iterator end_it = remove(c.begin(), c.end(), -1);
	//			c.erase(end_it, c.end());
	//		}
	//		return c[0];
	//	}
	int whichOne(int n) {
		int ptr = 1;
		int prev = ptr;

		for(int i=0;true;i++){
			prev = ptr;
			ptr += i/2+1;

			if(ptr>n) break;
		}
		return prev;
	}

};
