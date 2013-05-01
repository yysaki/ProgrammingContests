/**
 * SRM 575 div 2 Mid for study
 * dp 漸化式
 * 35 min.
 */
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class TheNumberGameDivTwo
{
public:
	string find(int n){
    string Names[] = {"John", "Brus"};
    int dp[n+1];
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; i++) dp[i] = -1;

    for (int i = 4; i <= n; i++) {
      for (int j = 2; j <= n-1 ; j++) {
        if(i % j == 0 && dp[i - j] == 1){
          dp[i] = 0;
        }
      }

      if (dp[i]==-1) dp[i] = 1;
    }

		return Names[dp[n]];
	}
};

