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
#include <utility>
#include <boost/tuple/tuple.hpp>
#include <cstdlib>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

class P {
public:
  int x, y;
  P(int x, int y) : x(x), y(y) {}
  P(const P& p) : x(p.x), y(p.y) {}
};

class M {
public:
  P from, to;
  M(P from, P to) : from(from), to(to) {}
  // dummy
  
  bool operator<(const M &rhs)  const {
    return unique_num() < rhs.unique_num();
  }
  int unique_num() const {
    return from.x * 37 + from.y * 41 + to.x * 43 + to.y * 47;
  }
};

typedef map< M, bool > maze_t;

maze_t maze;
int W, H;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

void maze_insert(P from, P to){
  maze[M(from, to)] = true;
  maze[M(to, from)] = true;
}

int solve(){
//  for(maze_t::const_iterator it = maze.begin(); it != maze.end(); ++it){
//    cout << "(" << it->first.from.x << ", " << it->first.from.y << 
//      ") -> (" << it->first.to.x << ", " << it->first.to.y <<
//      ") = " << it->second << endl;
//  }

  bool flags[W+2][H+2];
  for(int i = 0; i < W+2; ++i){
    for(int j = 0; j < H+2; ++j){
      flags[i][j] = false;
    }
  }
  
  queue<pair<P,int> > que;
  flags[1][1] = true;
  que.push(make_pair(P(1,1), 1));

  while(!que.empty()){
    const P cur = que.front().first;
    const int score = que.front().second;
    que.pop();

    if(cur.x == W && cur.y == H) return score;

    // TODO
    for(int dir = 0; dir < 4; ++dir){
      const int next_x = cur.x + dx[dir];
      const int next_y = cur.y + dy[dir];
      if(!maze[M(P(cur.x, cur.y), P(next_x, next_y))]){
        if(!flags[next_x][next_y]){
          flags[next_x][next_y] = true;
          que.push(make_pair(P(next_x, next_y), score + 1));
          cout << "(" << cur.x << ", " << cur.y << ") -> (" << next_x << ", " << next_y << ")" << endl;
        }
      }
    }
  }

  for(int i = 0; i < W+2; ++i){
    for(int j = 0; j < H+2; ++j){
      cout << flags[i][j];
    }
    cout << endl;
  }

  return 0;
}

int main(){
  int count = 0;
  cin >> W >> H;
  while(W > 0 && H > 0){
    maze = maze_t();
    for(int i = 0; i < W+2; ++i){
       maze_insert(P(i,0), P(i,1));
       maze_insert(P(i,H), P(i,H+1));
    }
    for(int j = 0; j < H+2; ++j){
       maze_insert(P(0,j), P(1,j));
       maze_insert(P(W,j), P(W+1,j));
    }

    for(int j = 1; j < H+1; ++j){
      for(int i = 1; i < W+1-1; ++i){
        int flag;
        cin >> flag;
        if(flag){
          maze_insert(P(i,j), P(i+1,j));
        }
      }
      if(j != H){
        for(int i = 1; i < W+1; ++i){
          int flag;
          cin >> flag;
          if(flag){
            maze_insert(P(i,j), P(i,j+1));
          }
        }
      }
    }

    cout << W << ", " << H << endl;

    cout << solve() << endl;
    cin >> W >> H;
  }

  return 0;
}
