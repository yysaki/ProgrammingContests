/*
 * 0 -> ... -> N のパスが何通りあるか
 * DAG無し
 * 2値グラフの探索問題
 * これで合ってるつもりだけど, 回答者0の問題なのでどうだろう
 */

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

class GogoXReimuHakurai {
private:
	void print(vector<string> c){
		for(int i=0;i<c.size();i++){
			for(int j=0;j<c[0].size();j++){
				if(c[i][j]=='Y'){
					cout << i << " -> " << j << endl;
				}
			}
		}
	}

public:
	int solve(vector<string> choices) {
		print(choices);

		int N = choices.size();
		int dp[N];
		for(int i=0;i<N;i++){
			dp[i] = 0;
		}

		dp[0] = 1;

		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				if(choices[i][j]=='Y'){
					dp[j] += dp[i];
				}
			}
		}

		return dp[N-1];
	}

};
