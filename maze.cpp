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

int solve(maze_t maze){
//  for(maze_t::const_iterator it = maze.begin(); it != maze.end(); ++it){
//    cout << "(" << it->first.from.x << ", " << it->first.from.y << 
//      ") -> (" << it->first.to.x << ", " << it->first.to.y <<
//      ") = " << it->second << endl;
//  }

  return 0;
}

int main(){
  int W, H;
  int count = 0;
  cin >> W >> H;
  while(W > 0 && H > 0){
    maze_t maze;
    for(int i = 0; i < W+2; ++i){
       maze[M(P(i,0), P(i,1))] = true;
       maze[M(P(i,1), P(i,0))] = true;
       maze[M(P(i,H), P(i,H+1))] = true;
       maze[M(P(i,H+1), P(i,H))] = true;
    }
    for(int j = 0; j < H+2; ++j){
       maze[M(P(0,j), P(1,j))] = true;
       maze[M(P(1,j), P(0,j))] = true;
       maze[M(P(W,j), P(W+1,j))] = true;
       maze[M(P(W+1,j), P(W,j))] = true;
    }

    for(int j = 1; j < H+1; ++j){
      for(int i = 1; i < W+1-1; ++i){
        int flag;
        cin >> flag;
        if(flag){
          maze[M(P(i,j), P(i+1,j))] = true;
          maze[M(P(i+1,j), P(i,j))] = true;
        }
      }
      if(j != H){
        for(int i = 1; i < W+1; ++i){
          int flag;
          cin >> flag;
          if(flag){
            maze[M(P(i,j), P(i,j+1))] = true;
            maze[M(P(i,j+1), P(i,j))] = true;
          }
        }
      }
    }

    cout << "--------" << endl;
    cout << solve(maze) << endl;

    cin >> W >> H;
  }

  return 0;
}
