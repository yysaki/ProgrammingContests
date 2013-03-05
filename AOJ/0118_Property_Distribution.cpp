/**
 * ‹a–{ •—Dæ’Tõ—á‘è
 * vector<string> area => Memory Limit Exceeded
 * string area[100]    => Time Limit Exceeded
 * int area[100][100]  => OK!
 */

#include <iostream>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int H; int W;
char area[100][100];

void move(int x, int y, char fruit){
  int xd, yd;
  area[x][y] = '_';
  for(int i=0; i<4; i++){
    xd = x + dx[i];
    yd = y + dy[i];
    if(0<=xd && xd<H && 0<=yd && yd<W){
      if(area[xd][yd]==fruit){
        move(xd,yd,fruit);
      }
    }
  }
}

int solve(){
  int ans = 0;

  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      if(area[i][j]!='_'){
        ans++;
        move(i,j,area[i][j]);
      }
    }
  }

  return ans;
}

int main(){
  cin >> H >> W;
  while(H + W > 0){
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        cin >> area[i][j];
      }
    }

    cout << solve() << endl;
    cin >> H >> W;
  }

  return 0;
}
