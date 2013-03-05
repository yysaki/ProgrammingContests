/**
 * SRM 562 div2 mid
 * 計算は正しいと思われるがT=1000000000の時タイムアウトする
 */

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

class PastingPaintingDivTwo {

public:
  long long countColors(vector<string> clipboard, int T) {
    const int W = clipboard[0].size();
    const int H = clipboard.size();
    const int M = max(W,H);
    //    cout << "W:" << W << ", H:" << H << ", M:" << M << endl;

    long long cnt = 0;
    for(int y=0;y<=H+T;y++){
      for(int x=max(0,y-M+1); x<=(min(H+T,y+M-1)) ;x++){
        bool isBlack = false;
        for(int k = max(0, min(x-W, y-H)); k<min(T, max(x+W, y+H)); k++){
          if(0<=y-k && y-k<H && 0<=x-k && x-k<W){
            if(clipboard[y-k][x-k]=='B'){
              isBlack = true;
            }
          }
        }

        if(isBlack){
          //          cout << "y:" << y << ", x:" << x << endl;
          cnt++;
        }
      }
    }

    return cnt;
  }

};
