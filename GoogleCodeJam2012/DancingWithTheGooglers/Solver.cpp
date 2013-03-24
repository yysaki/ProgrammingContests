/*
 * Solver.cpp
 *
 *  Created on: 2012/04/14
 *      Author: yysaki
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/tokenizer.hpp>

#include <iomanip>
#include <fstream>

#include "Solver.h"

using namespace std;
typedef vector<int> vec_t;
typedef vec_t::iterator iterator_t;

Solver::Solver(const char* in, const char* out) : ifs(in), inputFile(in), outputFile(out) {
  if(!ifs.is_open()){
    std::cout << inputFile << " is not found" << std::endl;
    assert(0);
  }
  ifs >> TNum;
}

Solver::~Solver(){
  ifs.close();
}

bool Solver::solve(){
  cout << "---solve" << endl;
  int N, S, p, ans;
  vec_t t;
  for(int test=0;test<TNum;test++){
    cout << "====loop " << test+1 << "====" << endl;
    ans = 0; t.clear(); // reset
    inputLine(&N, &S, &p, &t);
    sort(t.rbegin(),t.rend());
    debugPrint(cout, N,S,p,t);

    for(iterator_t it=t.begin();it!=t.end();it++){
      if(judge(*it,false,p)){
        ans++;
      }else if(judge(*it,true,p) && S>0){
        ans++; S--;
      }
    }
    cout << "===ans: " << ans << "====" << endl;
    answers.push_back(ans);
  }
  cout << *this;

  return true;
}

bool Solver::judge(int ti, bool isSurprising, int p) const{
  cout << "---judge(" << ti << ", " << isSurprising << ", " << p << "): ";
  int ans;
  if(ti==0){
    ans = 0>=p;
  }
  else if(ti%3==0){                 // ti=3n
    if(isSurprising){
      ans = ((ti/3)+1)>=p;
    }else{
      ans = (ti/3)>=p;
    }
  }else if(ti%3==1){           // ti=3n+1
    ans = ((ti/3)+1)>=p;
  }else{                       // ti=3n+2
    if(isSurprising){
      ans = ((ti/3)+2)>=p;
    }else{
      ans = ((ti/3)+1)>=p;
    }
  }

  cout << "(ti/3):" << ti/3 <<  ", ans:" << ans << endl;
  return ans;
}

bool Solver::inputLine(int* N, int* S, int* p, std::vector<int>* t){
  cout << "---inputLine" << endl;
  if(!ifs.is_open()){
    cout << inputFile << " is not found" << endl;
    assert(0);
  }

  ifs >> *N >> *S >> *p;
  for(int i=0;i<*N;i++){
    int tmp;
    ifs >> tmp;
    (*t).push_back(tmp);
  }

  return true;
}

bool Solver::output() const {
  cout << "---output" << endl;
  std::ofstream ofs(outputFile);
  dump(ofs);
  return true;
}

std::ostream& Solver::debugPrint(std::ostream& s, int N, int S, int p, vector<int> t) const{
  cout << "---debugPrint" << endl;
  s << "N:" << N << ", S:" << S << ", p:" << p << endl;
  for(int i=0;i<(int)(t).size();i++){
    s << "t[" << i << "]:" << (t)[i] << " ";
  }
  s << endl;

  return s;
}

std::ostream& Solver::dump(std::ostream& s) const{
  cout << "---dump" << endl;
  stringstream ss;
  for (int i=0;i<(int)answers.size();i++) {
    ss << "Case #" << i+1 << ": " << answers[i] << endl;
  }
  s << ss.str();
  return s;
}

std::ostream& operator<<(std::ostream& s, const Solver& sol){
  return sol.dump(s);
}
