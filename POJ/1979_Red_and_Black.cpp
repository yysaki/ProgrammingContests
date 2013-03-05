#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int w,h;
vector< vector<char> > a;
int ans = 0;

string to_s(){
  stringstream ss;

  for(int j=0;j<h;j++){
    for(int i=0;i<w;i++){
      ss << a[i][j];
    }
    ss << endl;
  }

  return ss.str();
}

bool canMove(int x, int y){
  return (0<=x&&x<=w-1 && 0<=y&&y<=h-1 && a[x][y]=='.');
}

// search Up Down Left Right
void search(int x, int y){
  ans++;
  a[x][y] = '*'; 
  if(canMove(x-1,y)){ search(x-1,y); }
  if(canMove(x+1,y)){ search(x+1,y); }
  if(canMove(x,y-1)){ search(x,y-1); }
  if(canMove(x,y+1)){ search(x,y+1); }
}

void solve(){
  ans = 0;
  int x = 0, y = 0;

  for(int j=0;j<h;j++){
    for(int i=0;i<w;i++){
      if(a[i][j]=='@'){
        x = i; y = j;
      }
    }
  }

  search(x,y);
}

int main(){
  cin >> w;
  cin >> h;

  while(w!=0 && h!=0){
    a.reserve(w);
    for(int i=0;i<w;i++){
      a[i].reserve(h);
    }

    for(int j=0;j<h;j++){
      for(int i=0;i<w;i++){
        cin >> a[i][j];
      }
    }

    solve();
    cout << ans << endl;

    cin >> w;
    cin >> h;
  }

  return 0;
}

