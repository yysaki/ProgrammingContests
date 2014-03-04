#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
using namespace std;

const int MAX_N = 350;
int n;
int cows[MAX_N][MAX_N];

int solve(){
  int dp[MAX_N+1][MAX_N+1];
  memset(dp, 0, sizeof(dp));

  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + cows[i][j];
    }
  }
  
  return dp[0][0];
}

int main(){
  memset(cows, 0, sizeof(cows));

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> cows[i][j]; 
    }
  }
  
  cout << solve() << endl;
  return 0;
}

