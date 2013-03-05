#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class GogoXCake {
private:
	string toString(vector<string> dst){
		stringstream ss;
		for(int i=0;i<(int)(dst.size());i++){
			ss << dst[i] << endl;
		}
		return ss.str();
	}
public:
	string solve(vector<string> cake, vector<string> cutter) {
		const int h = cake.size(), w = cake[0].size();
		const int ch = cutter.size(), cw = cutter[0].size();

		vector<string> work;
		for(int i=0;i<h;i++){
			string str;
			for(int j=0;j<w;j++){
				str += (cake[i][j]=='X') ? '.' : 'X';
			}
			work.push_back(str);
		}

		for(int i=0;i<h-ch+1;i++){
			for(int j=0;j<w-cw+1;j++){
				bool canCut = true;
				for(int k=0;k<ch;k++){
					for(int m=0;m<cw;m++){
						if(cutter[k][m]=='.' && work[i+k][j+m]=='.'){
							canCut = false;
							break;
						}
					}
					if(!canCut){ break; }
				}

				if(canCut){
					for(int k=0;k<ch;k++){
						for(int m=0;m<cw;m++){
							if(cutter[k][m]=='.'){
								work[i+k][j+m] = '.';
							}
						}
					}
				}
			}
		}

		for(int i=0;i<(int)(work.size());i++){
			if(work[i]!=string(w,'.')){ return "NO"; }
		}
		return "YES";
	}
};
