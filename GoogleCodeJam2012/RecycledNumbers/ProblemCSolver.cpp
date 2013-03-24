#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/tokenizer.hpp>

#include <iomanip>
#include <fstream>

#include "ProblemCSolver.h"

using namespace std;
typedef vector<int> vec_t;
typedef vec_t::iterator iterator_t;

ProblemCSolver::ProblemCSolver(const char* in, const char* out) : ifs(in), inputFile(in), outputFile(out) {
  if(!ifs.is_open()){
    cout << inputFile << " is not found" << endl;
    assert(0);
  }
  ifs >> TNum;
}

ProblemCSolver::~ProblemCSolver(){
  ifs.close();
}

bool ProblemCSolver::solve(){
  for(int test=0;test<TNum;test++){
    cout << "====loop " << test+1 << "====" << endl;
    int A, B; int ans = 0; // reset
    inputLine(&A, &B);

//    cout << "A: " << A << ", B: " << B << endl;
    vector<int> check; // èdï°
    for(int i=A;i<=B;i++){
      check.clear();
      for (int j=1; j<getDigits(B); j++) {
        if(isRecyclable(A,B,i,j)){
          int m = recycle(i,j);
          bool isDuplicated = false;
          for(iterator_t it=check.begin();it!=check.end();it++){
            if(m==(*it)) isDuplicated = true;
          }
          if(!isDuplicated){
            ans++;
            check.push_back(m);
          }
        }
      }
    }

    answers.push_back(ans);
    cout << "====ans: " << ans << "====" << endl;
  }

  return true;
}

bool ProblemCSolver::isRecyclable(int A, int B, int n, int d) const{
  if(n<A || B<n){
    return false;
  }

  // test leading zeros
  int tmp = n;
  for(int i=0;i<d-1;i++){
    tmp /= 10;
  }
  if(tmp%10==0){
    return false;
  }

  int m = recycle(n,d);

  // judge m
  if(m<A || B<m || n>=m){
    return false;
  }
//  cout << "(" << n << "," << m << ")" << endl;
  return true;
}
int ProblemCSolver::recycle(int n, int d) const{
  // recycle
  stringstream ss;
  ss << n;
  string str = ss.str();
  int len = (int)str.size();
  //  cout << str << ", substr:" << str.substr(len-d, len) << endl;
  str = str.substr(len-d, len) + str.substr(0, len-d);
  return atoi(str.c_str());
}
bool ProblemCSolver::inputLine(int* A, int* B){
  cout << "---inputLine" << endl;
  if(!ifs.is_open()){
    cout << inputFile << " is not found" << endl;
    assert(0);
  }

  ifs >> *A >> *B;
  return true;
}

bool ProblemCSolver::output() const {
  cout << "---output" << endl;
  std::ofstream ofs(outputFile);
  dump(ofs);
  return true;
}

std::ostream& ProblemCSolver::dump(std::ostream& s) const{
  cout << "---dump" << endl;
  stringstream ss;
  for (int i=0;i<(int)answers.size();i++) {
    ss << "Case #" << i+1 << ": " << answers[i] << endl;
  }
  s << ss.str();
  return s;
}

int ProblemCSolver::getDigits(int x) const{
  //  cout << "getDigit(" << x << "): ";
  int ans = 1;
  while(x>=10){
    x /= 10;
    ans++;
  }
  //  cout << ans << endl;
  return ans;
}

std::ostream& operator<<(std::ostream& s, const ProblemCSolver& sol){
  return sol.dump(s);
}
