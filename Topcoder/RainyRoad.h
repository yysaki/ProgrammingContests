// –â‘èŒë“Ç No‚Íroad[0][i]==road[1][i]=='W'‚Ìê‡‚Ì‚İ
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

class RainyRoad{
public:
  string isReachable(vector<string> road){
    cout << "road[0]: " << road[0] << endl;
    cout << "road[1]: " << road[1] << endl;
    int N = road[0].size();
    for(int i=0;i<N;i++){
      if(road[0][i]=='W'){
        cout << "[1]["<< i << "]:" << road[1][i] <<  endl;
        cout << "[1]["<< min(N,i+1) << "]:" << road[1][min(N,i+1)] <<  endl;
        if(road[1][i]=='W'){
          return "No";
//        }else if(road[1][max(0,i-1)]=='W'){
//          return "No";
//        }else if(road[1][min(N,i+1)]=='W'){
//          return "No";
        }
      }
    }
    return "Yes";
  }


};
