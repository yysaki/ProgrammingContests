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

typedef vector<string> vec_t;
class PikachuEasy {

	public: string check(string word) {
		vec_t sy;
		sy.push_back("pi");
		sy.push_back("ka");
		sy.push_back("chu");

		while(word.size()!=0){
			bool isFound = false;
			for(vec_t::iterator it=sy.begin();it!=sy.end();it++){
				if(word.find(*it)==0){
					isFound = true;
					word = word.substr((*it).size(), word.size()-(*it).size());
				}
			}
			if(!isFound) return "NO";
		}

		return "YES";
	}

};
