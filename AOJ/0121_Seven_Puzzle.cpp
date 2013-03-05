/*
 * AOJ 0121 seven puzzle
 * 蟻本幅優先探索例題
 * パズルデータをstringに圧縮
 * 先に最終状態から全状態のステップ数を先に求めてからgetlineを回す
 *
 * ### memo
 * * gccではgetline(cin, std)の時文末の\r\nの内\rを残してしまうことがある
 * * string中の文字入れ替えにswapが使える
 * * std::mapは、挿入にstd::pair、探索にfind()、key取得にoperator[]が使える
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <limits>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef pair<string, int> P;
const int N = 8;

int d[4] = {1, -1, 4, -4};

map<string, int> ans;

void solve(){
  queue<P> que;
  ans.insert(make_pair("01234567", 0));
  que.push(make_pair("01234567", 0));

  while(!que.empty()){
    string s = que.front().first;
    int pos = s.find('0');
    int cost = que.front().second;
    que.pop();

    for(int i = 0; i < 4; i++){
      int nPos = pos + d[i];
      if(0<=nPos && nPos<N && !(d[i]==1 && nPos==4) && !(d[i]==-1 && nPos==3)){
        string nS = s;
        swap(nS[pos], nS[nPos]);

        if(ans.find(nS)==ans.end()){
          ans.insert(make_pair(nS, cost+1));
          que.push(make_pair(nS, cost+1));
        }
      }
    }
  }
}
int main(){
  solve();

  string buf;
  while(getline(cin, buf)){
    string str = "";
    for(int i=0; i < (int)buf.size(); i++){
      if(buf[i]!=' ' && buf[i]!='\r'){
        str += buf[i];
      }
    }
    if(ans.find(str)==ans.end()){
      cout << str.size() << endl;
    }
    cout << ans[str] << endl;
  }

  return 0;
}
