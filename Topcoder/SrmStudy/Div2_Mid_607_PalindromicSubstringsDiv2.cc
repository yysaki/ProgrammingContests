// O(n^3), n <= 5000のためTLE 24:34.21
// ref: http://apps.topcoder.com/wiki/display/tc/SRM+607 1:00:20.24

#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

class PalindromicSubstringsDiv2{
public:
  std::string S;
  char dp[5000][5000];

  // 0 <= a <= b < S.size()
  bool isPalindrome(int a, int b){
    char &res = dp[a][b];
    if(res != -1) return res;

    if(b - a <= 0){
      res = true;
      return true;
    }

    if(S[a] == S[b]){
      res = isPalindrome(a + 1, b - 1);
      return res;
    }
    
    return false;
  }

  int count(vector <string> S1, vector <string> S2){
    S = "";
    for (int i = 0; i < (int)S1.size(); i++) {
      S += S1[i];
    }
    for (int i = 0; i < (int)S2.size(); i++) {
      S += S2[i];
    }

    memset(dp, -1, sizeof(dp));

    int count = 0;
    for (int i = 0; i < (int)S.size(); i++) {
      for (int j = i; j < (int)S.size(); j++) {
        if(isPalindrome(i, j)) count++;
      }
    }

    return count;
  }
};

