/*イテレータからindexを取得した*/
/*グラフ理論、DPの例題*/

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

class P8XGraphBuilder {
private:
	static const int I = 51;
	static const int J = 101;

	void dump(int dp[I][J], const int dp_first, const int dp_second, const vector<int> scores){
		cout << "scores: { ";
		for(vector<int>::const_iterator it=scores.begin();it!=scores.end();it++){
			cout << *it << " ";
		}
		cout << "}" << endl;

		cout << "dp[i][j]: " << endl;
		for(int i=0;i<dp_first;i++){
			for(int j=0;j<dp_second;j++){
				cout << setw(2);
				if(dp[i][j]==-1){
					cout << '-';
				}else{
					cout << dp[i][j];
				}
				cout << " ";
			}
			cout << endl;
		}
	}
public:
	int solve(vector<int> scores) {
		int N = (int)scores.size();
		int nodeNum = N+1;
		int maxDegree = 2*N;
		int dp[I][J];
		for(int i=0;i<nodeNum+1;i++){
			for(int j=0;j<maxDegree+1;j++){
				dp[i][j] = -1;
			}
		}

		dp[0][0] = 0;

		for(int i=0;i<nodeNum+1;i++){
			for(int j=0;j<maxDegree+1;j++){
				if(dp[i][j]>=0){
					for(int k=1;k<N+1&&j+k<=maxDegree;k++){
						dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j] + scores[k-1]);
					}
				}
			}
		}

		dump(dp, nodeNum+1, maxDegree+1, scores);

		return dp[nodeNum][maxDegree];
	}

};
