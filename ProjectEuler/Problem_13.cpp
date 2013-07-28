#include <fstream>
#include <iomanip>
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

typedef vector<long long> num_t;
typedef vector<num_t> problem_t;

std::string to_s(const num_t& arg){
  ostringstream oss;
  for(int i = 0; i < 5; i++){
    oss << setw((i==0 ? 12 : 10));
    oss << arg[i];
  }

  return oss.str();
}

std::string largeSum(){
  problem_t problem;
  ifstream ifs("Problem_13.txt");
  for (int i = 0; i < 100; i++) {
    std::string str;
    ifs >> str;
    cout << "orig: " << str << endl;
    num_t num;
    for(int j = 0; j < 5; j++) {
      istringstream iss(str.substr(j * 10, 10));
      long long element;
      iss >> element;
      cout << "num" << j << ": " << setw((j+1)*10) << element << endl;
      num.push_back(element);
    }
    problem.push_back(num);
  }

  num_t ret;
  for(int i = 0; i < 5; i++){
    ret.push_back(0);
  }

  for(problem_t::const_iterator it = problem.begin(); it != problem.end(); it++){
    //cout << " " << to_s(ret) << endl;
    //cout << "+" << to_s(*it) << endl;

    bool isMoveUp = false;
    for(int i = 4; i >= 0; i--){
      if(isMoveUp){
        ret[i] += 1;
      }

      ret[i] += (*it)[i];
      isMoveUp = (i != 0 && ret[i] >= 10000000000);
      if(isMoveUp){
        ret[i] -= 10000000000;
      }
    }

    //cout << "=" << to_s(ret) << endl << endl;
  }

  ostringstream oss;
  oss << ret[0];

  return oss.str().substr(0,10);
}

int main(){
  cout << largeSum() << endl;
  return 0;
}

