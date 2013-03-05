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

int w, h;
int board[20][20];

const int INF = 1<<20;
const pair<int, int> dirs[4] = { make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1) };

void printBoard(int x=-1, int y=-1, vector<int> hi = vector<int>()){
  if((int)hi.size()>0){
    cout << "history: ";
    for(int i = 0; i < (int)hi.size();i++){
      if(hi[i]==0) cout << 'L';
      if(hi[i]==1) cout << 'R';
      if(hi[i]==2) cout << 'D';
      if(hi[i]==3) cout << 'U';
    }
    cout << endl;
  }
  for(int j=0;j<h;j++){
    for(int i=0;i<w;i++){
      if(i==x && j==y){
        cout << '*';
      }else{
        if(board[i][j]==0) cout << '_';
        if(board[i][j]==1) cout << '#';
        if(board[i][j]==2) cout << 'S';
        if(board[i][j]==3) cout << 'G';
      }
    }
    cout << endl;
  }
  cout << endl;
}

int dfs(int idx, int x, int y){
  if(idx==10) return INF;
  int ans = INF;
  // 4方向探索
  for(int d=0;d<4;d++){
    // ゴール、衝突、場外まで移動
    for(int i=1;;i++){
      const int nextX = x + i * dirs[d].first, nextY = y + i * dirs[d].second;
      // 場外
      if( !(0 <= nextX && nextX < w && 0 <= nextY && nextY < h) ) break;

      const int next = board[nextX][nextY];

     // 助走が必要
      if(i==1&&next==1) break;
      // Goal
      else if(next==3) return idx + 1;
      // 衝突
      else if(next==1){
        board[nextX][nextY] = 0;
        ans = min(ans, dfs(idx + 1, nextX - dirs[d].first, nextY - dirs[d].second));
        board[nextX][nextY] = 1;

        break;
      }
    }
  }

  return ans;
}

int solve(){
  int x = -1, y = -1;
  for(int j = 0; j < h; j++){
    for(int i = 0; i < w; i++){
      if(board[i][j]==2){
        x = i; y = j;
        break;
      }
    }
    if(x != -1 && y != -1) break;
  }

  int ans = dfs(0, x, y);

  return (ans!=INF) ? ans : -1;
}

int main(){
  int i=1;
  cin >> w >> h;
  while(!(w==0 && h==0)){
    for(int j=0;j<h;j++){
      for(int i=0;i<w;i++){
        cin >> board[i][j];
      }
    }

    cout << solve() << endl;

    cin >> w >> h;
  }

  return 0;
}
