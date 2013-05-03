/**
 * SRM Div 2 Mid 577 for study
 * http://community.topcoder.com/stat?c=problem_solution&rm=317300&rd=15498&pm=12545&cr=22864978 を参考に解き直し
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

class ij{
public: 
  int i, j;
  ij(int i, int j) : i(i), j(j) {}
  bool check(const ij& rhs, int dist) const {
    return (abs(i - rhs.i) + abs(j - rhs.j) <= dist);
  }
};

class GooseInZooDivTwo {
public:
  int count(vector <string> field, int dist) {
    const int H = field.size();
    const int W = field[0].size();

    int vec[51][51];

    int count = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if(field[i][j] == 'v'){
          vec[i][j] = 0;
          count++;
        }else{
          vec[i][j] = -1;
        }
      }
    }

    int group = 0;
    queue<ij> que;

    while(count>0){
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
          if(vec[i][j] == 0 && que.size() == 0){
            que.push(ij(i, j));
            group++;
            vec[i][j] = group;
            count--;

            cout << "vec[" << i << "][" << j << "] = " << group << endl;
            break;
          }
        }
      }

      while(que.size()>0){
        const ij t = que.front();
        que.pop();

        const int imin = max(t.i - dist, 0);
        const int imax = min(t.i + dist, H - 1);
        const int jmin = max(t.j - dist, 0);
        const int jmax = min(t.j + dist, W - 1);

        for (int i = imin; i <= imax; i++) {
          for (int j = jmin; j <= jmax; j++) {
            const ij tt(i, j);
            if(vec[i][j] == 0 && t.check(tt, dist)){
              que.push(tt);
              vec[i][j] = group;
              count--;
            }
          }
        }
      }
    }

    //dump
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if(vec[i][j]>=0){
          cout << setw(3) << vec[i][j];
        }else{
          cout << setw(3) << "___";
        }
      }
      cout << endl;
    }
    cout << group << endl;

    long long ret = 1;
    for (int i = 0; i < group; i++) {
      ret *= 2;
      ret %= 1000000007;
    }
    if(ret == 0){
      ret = 1000000007 - 1;
    }else{
      ret--;
    }

    return ret;
  }
};

