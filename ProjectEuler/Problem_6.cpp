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

int sumOfTheSquares(int arg){
  int ans = 0;
  for (int i = 1; i <= arg; i++) {
    ans += i*i;
  }
  return ans;
}

int squareOfTheSum(int arg){
  int sum = 0;
  for (int i = 1; i <= arg; i++) {
    sum += i;
  }
  return sum * sum;
}


int main(){
  const int NUM = 100;
  cout << squareOfTheSum(NUM) - sumOfTheSquares(NUM) << endl;

  return 0;
}

