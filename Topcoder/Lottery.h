// http://topcoder.g.hatena.ne.jp/caligue/20090813/1250145753
// ê…ÇµÇ¢Ç∆Ç±ÇÎÇ‹Ç≈çsÇ¡ÇΩ
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

bool compValidTicketsNum(const pair<string,long long>& a, const pair<string,long long>& b){
	if(a.second < b.second){
		return true;
	}else if(a.second > b.second){
		return false;
	}else{
		return a.first < b.first;
	}
}
class Lottery {
public:
	vector<string> sortByOdds(vector<string> rules){
		const int size = rules.size();
		vector<string> result(size);

		vector <pair<string,long long> > name(size);
		vector <int> choices(size), blanks(size);
		for(int i=0;i<size;++i){
			int p = find(rules[i].begin(),rules[i].end(),':') - rules[i].begin();
			name[i].first = rules[i].substr(0,p);
			istringstream iss(rules[i].substr(p+1));
			int choices, blanks;
			string sorted, unique;
			iss >> choices >> blanks >> sorted >> unique;
			if(sorted == "F" && unique == "F"){
				name[i].second = power(choices, blanks);
			}else if(sorted=="T" && unique=="T"){
				name[i].second = combination(choices+blanks-1, blanks);
			}else if(sorted=="F" && unique=="T"){
				name[i].second = combination(choices, blanks) * factorial(blanks);
			}else if(sorted=="T" && unique=="T"){
				name[i].second = combination(choices, blanks);
			}
		}
		stable_sort(name.begin(), name.end(), compValidTicketsNum);
		for(int i=0;i<size;i++){
			result[i] = name[i].first;
		}

		return result;
	}
private:
	long long power(const long long x, long long y){
		long long ret = 1;
		while(y-- >0){ ret *= x; }
		return ret;
	}

	long long factorial(long long x){
		long long ret = 1;
		while(x>0){
			ret *= x;
			x--;
		}
		return ret;
	}

	long long combination(long long x, long long y){
		long long ret = 1;
		for(int i=0;i<y;i++){
			ret *= x;
			x--;
		}
		while(y>1){
			ret /= y;
			y--;
		}
		return ret;
	}
};
