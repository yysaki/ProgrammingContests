/**
 * SRM Div 2 Mid 573 for study
 * 自力だと最後のテストがLTE
 * 1:22:00
 *
 * greedyで解き直し
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

class TeamContestEasy
{
public:
	int worstRank(vector <int> strength) {
    vector<int> s(strength);
    const int border = s[0] + s[1] + s[2] - min(s[0], min(s[1], s[2]));

    s.erase(s.begin(), s.begin() + 3);
    sort(s.begin(), s.end());

    int count = 0;
    bool used[50] = {};
    
    for (int i = 0; i < (int)s.size(); i++) {
      if(!used[i]){
        for (int j = 0; j < (int)s.size(); j++) {
          if(i!=j && !used[j]){
            if(s[i] + s[j] > border){
              used[i] = used[j] = true;
              count++;
              for (int k = 0; k < (int)s.size(); k++) {
                if(used[k]){ continue; }
                used[k] = true;
                break;
              }

              break;
            }
          }

        }
      }
    }

    return 1 + count;
  }
};

//class TeamContestEasy
//{
//  vector<int> s;
//  int myRank, N;  
//
//  int dfs(vector<bool> flags, int rank, int atLeast){
//    bool isEnd = true;
//    for (int i = atLeast; i < (int)flags.size(); i++) {
//      if(flags[i]){
//        isEnd = false;
//      }
//    }
//    if(isEnd){
//      return rank;
//    }
//
//    int ans = rank;
//    for (int i = atLeast; i < (int)s.size(); i++) {
//      if(flags[i]){
//        for (int j = i + 1; j < (int)s.size(); j++) {
//          if(flags[j] && s[i] + s[j] > myRank){
//            flags[i] = flags[j] = false;
//            ans = max(ans, dfs(flags, rank + 1, i));
//            flags[i] = flags[j] = true;
//          }
//        }
//      }
//    }
//
//    return ans;
//  }
//
//  void dump(vector<int> arg){
//    if(!arg.empty()){
//      vector<int>::iterator it=arg.begin();
//      cout << *it;
//      for(it++; it!=arg.end(); it++){
//        cout << ", " <<  *it;
//      }
//      cout << endl;
//    }
//  }
//public:
//	int worstRank(vector <int> strength) {
//    s = strength;
//    myRank = s[0] + s[1] + s[2] - min(s[0], min(s[1], s[2]));
//    N = s.size() / 3;
//
//    if(N==1) return 1;
//
//
//    s.erase(s.begin(), s.begin()+3);
//    sort(s.begin(), s.end());
//    s.erase(s.begin(), s.begin() + N * 1/3 + 1);
//
//    vector<bool> flags;
//    for (int i = 0; i < (int)s.size(); i++) {
//      flags.push_back(true);
//    }
//    dump(s);
//
//		return dfs(flags, 1, 0);
//	}
//};
//
