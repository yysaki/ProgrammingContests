/**
 * AOJ 0033 Ball
 * ‹a–{ •—Dæ’Tõ—á‘è
 * greedy
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

const int N = 10;

string solve(int balls[10]){
  int b = 0, c = 0;
  for(int i = 0; i < 10; i++){
    if(balls[i] < min(b,c)) return "NO";
    if(max(b,c) < balls[i]){
      if(max(b,c) == b){
        b = balls[i];
      }else{ // max(b,c) == c
        c = balls[i];
      }
    }else{ // if( min(b,c) < balls[i] && balls[i] < max(b,c) )
      if(min(b,c) == b){
        b = balls[i];
      }else{ // max(b,c) == c
        c = balls[i];
      }
    }

  }

  return "YES";
}

int main(){
  int questions;
  cin >> questions;
  int balls[N];
  for(int question = 0; question < questions; question++){
    for(int i = 0; i < N; i++){
      cin >> balls[i];
    }

    cout << solve(balls) << endl;
  }
}
