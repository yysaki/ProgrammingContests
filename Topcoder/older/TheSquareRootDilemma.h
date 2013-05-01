/**
 * SRM 567 Div2 mid
 * 77777*77777回のループが間に合わないと思い、難しいことをやろうとして袋小路入り
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
using namespace std;

class TheSquareRootDilemma {

public:
  int countPairs(int N, int M) {
    int count = 0;
    vector<int> squares;
    for(int i=1;(i*i)<=10000000;i++){
      squares.push_back(i*i);
    }
    for(int i=1;i<=N;i++){
      for(int j=1;j<=M;j++){
        for(int idx=0;idx<(int)squares.size();idx++){
          if(i*j==squares[idx]) count++;
        }
      }
    }

    return count;
  }
};

//#include <algorithm>
//#include <iostream>
//#include <sstream>
//#include <limits>
//#include <map>
//#include <numeric>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <set>
//using namespace std;
//
//class TheSquareRootDilemma {
//
//public:
//  int countPairs(int N, int M) {
//    const int max = 77777;
//    vector<int> squares;
//    for(int i = 1; i*i <= max; i++){
//      squares.push_back(i*i);
//    }
//
//    int count = 0;
//    // a==b case
//    for(int i=1;i<=min(N,M);i++){
//      count++;
//    }
//
//    // a= sqrt(x)*squares[idx], b= sqrt(x) case
//    // a= sqrt(x), b= sqrt(x)*squares[idx] case
//    for(int sqrtx = 1; sqrtx <= max; sqrtx++){
//      for(int idxa = 0; idxa < (int)squares.size(); idxa++)
//      for(int idxb = 0; idxb < (int)squares.size(); idxb++){
//        int a = sqrtx * squares[idxa];
//        int b = sqrtx * squares[idxb];
//        if(a!=b){
//          if(a<=N && b<=M){ count++; }
//          if(b<=N && a<=M){ count++;}
//        }
//      }
//    }
//
//    return count;
//  }
//
//};
