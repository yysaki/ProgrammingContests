/*
 * AOJ 0121 seven puzzle
 * �a�{���D��T�����
 * �p�Y���f�[�^��string�Ɉ��k
 * ��ɍŏI��Ԃ���S��Ԃ̃X�e�b�v�����ɋ��߂Ă���getline����
 *
 * ### memo
 * * gcc�ł�getline(cin, std)�̎�������\r\n�̓�\r���c���Ă��܂����Ƃ�����
 * * string���̕�������ւ���swap���g����
 * * std::map�́A�}����std::pair�A�T����find()�Akey�擾��operator[]���g����
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
