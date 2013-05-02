/**
 * SRM 574 div 2 Mid for study
 * BFS
 * 1:11:27
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

#define FOREACH(a,b,c) for(a::iterator b=(c).begin();(b)!=(c).end();(b)++)

class TheNumberGameDiv2
{
  bool equals(vector<char> lhs, vector<char> rhs){
    if(lhs.size() != rhs.size()) return false;

    for (int i = 0; i < (int)lhs.size(); i++) {
      if(lhs[i] != rhs[i]) return false;
    }

    return true;
  }

  void dump(vector<char> arg){
    FOREACH(vector<char>, it, arg){
      cout << *it;
    }
    cout << endl;
    
  }

public:
	int minimumMoves(int A, int B) {
    vector<char> Astr, Bstr;
    for(; A!=0; A/=10){ Astr.push_back('0' + A % 10); }
    reverse(ALL(Astr));

    for(; B!=0; B/=10){ Bstr.push_back('0' + B % 10); }
    reverse(ALL(Bstr));

    vector< vector<char> > dictionary;
    queue< pair<vector<char>, int> > que;
    que.push(make_pair(Astr, 0));
    dictionary.push_back(Astr);

    while(!que.empty()){
      const vector<char> q = que.front().first;
      const int num = que.front().second;
      que.pop();
      
      if(equals(q, Bstr)){ return num; }
      if((int)q.size() <= 1){ continue; }

      vector<char> rev = q;
      reverse(ALL(rev));
      if(find(ALL(dictionary), rev) == dictionary.end()){
        que.push(make_pair(rev, num+1));
        dictionary.push_back(rev);
      }

      vector<char> div;
      for (int i = 0; i < (int)q.size()-1; i++) { div.push_back(q[i]); }

      if(find(ALL(dictionary), div) == dictionary.end()){
        que.push(make_pair(div, num+1));
        dictionary.push_back(div);
      }

    }
    
		return -1;
	}
};

