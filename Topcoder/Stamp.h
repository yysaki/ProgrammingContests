//// SRM 558 div2 mid 完全降参
// 動的計画法、ビット演算
// http://apps.topcoder.com/wiki/display/tc/SRM+558

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
class Stamp {

public:
  int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
    const int INF = 1<<20;
    int N = desiredColor.size();
    int cost[N+1];
    int a[N];
    for(int i=0;i<N;i++){
      switch(desiredColor[i]){
        case '*': a[i] = 7; break; // 1<<0 + 1<<1+ 1<<2
        case 'R': a[i] = 1; break; // 1<<0
        case 'G': a[i] = 2; break; //        1<<1
        case 'B': a[i] = 4; break; //              1<<2
      }
    }
    int res = INF;
    for(int len=1;len<=N;len++){
      cost[0] = 0;
      // dp
      for(int i=1;i<=N;i++) cost[i] = INF;

      for(int i=0;i<N;i++){
        int color = 7;
        for(int j=i;j<N;j++){
          color &= a[j];
          if(!color) break; // same color is nothing
          int seg = j - i + 1;
          if(seg < len) continue;

          cost[j+1] = min(cost[j+1], cost[i] + ((seg + len -1) / len) * pushCost);
        }
      }
      res = min(res, cost[N] + stampCost * len);
      // print
      cout << "len:" << len << " => cost:{" << cost[0];
      for(int i=1;i<=N;i++) cout << ", " << cost[i];
      cout << "}" << endl;
    }
    return res;
  }
};


//
//
//class Stamp {
//
//public:
//  int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
//    const int INF = 1<<20;
//    const int N = desiredColor.length();
//    int ret = INF;
//
//    // print cells
//    for(int x=0;x<N;x++){
//      cout << desiredColor[x];
//    }
//    cout << endl;
//
//    // main loop
//    for(int len=1;len<N;len++){
//      // fill '.' which means uncolored on cells
//      vector<char> cells;
//      for(int i=0;i<N;i++){
//        cells.push_back('.');
//      }
//
//      int cnt = 0;
//      // check left to right
//      for(int i=0;i<N-len+1;i++){
//        if(cells[i]=='.'){
//          char decided = '*';
//          for(int j=i;j<i+len;j++) if(desiredColor[j]!='*'){
//            decided = desiredColor[j];
//          }
//
//          if(decided!='*'){
//            bool isSame = true;
//            for(int j=i;j<i+len;j++){
//              if(desiredColor[j]!=decided && desiredColor[j]!='*'){
//                isSame = false;
//              }
//            }
//            if(isSame){
//              for(int x=i;x<i+len;x++) cells[x] = decided;
//              cnt++;
//              continue;
//            }
//          }else{
//            for(int x=i;x<i+len;x++) cells[x] = '*';
//            cnt++;
//          }
//        }
//      }
//
//      // check dup from right 2 left
//      for(int i=N-1;i>=len-1;i--) if(cells[i]=='.'){
//        char decided = desiredColor[i];
//
//        bool isStampable = true;
//        for(int j=i;j>i-len;j--){
//          if(!(cells[j]==decided || cells[j]=='.' || cells[j]=='*')){
//            isStampable = false;
//          }
//        }
//        if(isStampable){
//          for(int x=i;x>i-len+1;x--) cells[x] = decided;
//          cnt++;
//        }
//      }
//
//      // compare ret
//      bool isFilled = true;
//      for(int i=0;i<N;i++) if(cells[i]=='.'){
//        isFilled = false;
//      }
//      if(isFilled){
//        ret = min(ret, len*stampCost + cnt*pushCost);
//      }
//      // print cells
//      for(int x=0;x<N;x++){
//        cout << cells[x];
//      }
//      cout << "  <= len:" << len << ", ret:" << ret << endl;
//    }
//
//    return ret;
//  }
//
//};
