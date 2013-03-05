/*
 * AOJ 0558 Cheese
 * ‹a–{ •—Dæ’Tõ–â‘è
 * footprints‚Ì“±“ü‚É‹ê˜J‚µ‚½
 */

#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

typedef struct {
  int x;
  int y;
  int life;
  int score;
} P;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int H, W, N;
char** field;
int** footprints;

bool isEatable(P p){
  char point = field[p.x][p.y];
  return '1' <= point && point <= '9' && p.life == (point - '0');
}

bool canPush(P p){
  if(0 <= p.x && p.x < H && 0 <= p.y && p.y < W){
    if(field[p.x][p.y]!='X'){
      if(p.life > footprints[p.x][p.y]){
        return true;
      }
    }
  }
  return false;
}

void dump(P p){
  cout << p.x << ", " << p.y << ", " << p.life << ", " << p.score << endl;
}

int bfs(P p0){
  queue<P> que;
  que.push(p0);

  P now = que.front(); que.pop();
  footprints[now.x][now.y] = max(footprints[now.x][now.y], now.life);

  while(now.life<N+1){
    for(int i = 0; i < 4; i++){
      P next = {now.x + dx[i], now.y + dy[i], now.life, now.score + 1};
      if(canPush(next)){
        if(isEatable(next)){ next.life++;}
        que.push(next);
        footprints[next.x][next.y] = next.life;
      }
    }

    now = que.front(); que.pop();
  }

  return now.score;
}

int solve(){
  P p0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(field[i][j]=='S'){
        p0 = {i,j,1,0};
        break;
      }
    }
  }

  return bfs(p0);
}

int main(){
  cin >> H >> W >> N;
  field = (char**)malloc(sizeof(char) * H * W);
  footprints = (int**)malloc(sizeof(int) * H * W);
  for(int i = 0; i < H; i++){
    field[i] = (char*)malloc(sizeof(char) * W);
    footprints[i] = (int*)calloc(W, sizeof(int));
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> field[i][j];
    }
  }

  cout << solve() << endl;

  for(int i = 0; i < H; i++){
    free(field[i]); free(footprints[i]);
  }
  free(field); free(footprints);

  return 0;
}
