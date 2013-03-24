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
typedef boost::tokenizer<boost::char_separator<char> > tokenizer_t;
typedef vector<string>::iterator iterator_t;

bool Solver::solve(){
  cout << "---solve" << endl;
  for(iterator_t it=q.begin();it!=q.end();it++){
    cout << *it << endl;

    string str = "";
    for(string::iterator s_it=(*it).begin();s_it!=(*it).end();s_it++){
      str += convert(*s_it);
    }
    ans.push_back(str);
  }

  return true;
}

char Solver::convert(const char c) const{
  char ans;
  switch(c){
    case 'a' : ans = 'y'; break;
    case 'b' : ans = 'h'; break; break; break;
    case 'c' : ans = 'e'; break;
    case 'd' : ans = 's'; break;
    case 'e' : ans = 'o'; break;
    case 'f' : ans = 'c'; break;
    case 'g' : ans = 'v'; break;
    case 'h' : ans = 'x'; break;
    case 'i' : ans = 'd'; break;
    case 'j' : ans = 'u'; break;
    case 'k' : ans = 'i'; break;
    case 'l' : ans = 'g'; break;
    case 'm' : ans = 'l'; break;
    case 'n' : ans = 'b'; break;
    case 'o' : ans = 'k'; break;
    case 'p' : ans = 'r'; break;
    case 'q' : ans = 'z'; break;
    case 'r' : ans = 't'; break;
    case 's' : ans = 'n'; break;
    case 't' : ans = 'w'; break;
    case 'u' : ans = 'j'; break;
    case 'v' : ans = 'p'; break;
    case 'w' : ans = 'f'; break;
    case 'x' : ans = 'm'; break;
    case 'y' : ans = 'a'; break;
    case 'z' : ans = 'q'; break;
    default  : ans = c;   break;
  }

  cout << "---convert('" << c << "' to '" << ans << "'" << endl;

  return ans;
}

bool Solver::input(){
  cout << "---input" << endl;
  std::ifstream ifs(inputFile);
  //  char str[256];
  string str;

  if(!ifs.is_open()){
    cout << inputFile << " is not found" << endl;
    assert(0);
  }
  // ‘”‚ÌŽæ“¾
  if(getline(ifs, str)){
    N = atoi(str.c_str());
  }
  for(int i=0;i<N;i++){
    if(getline(ifs, str)){
      q.push_back(str);
    }
  }
  ifs.close();

  return true;
}

bool Solver::output() const {
  cout << "---output" << endl;
  std::ofstream ofs(outputFile);
  dump(ofs);
  return true;
}

std::ostream& Solver::dump(std::ostream& s) const{
  cout << "---dump" << endl;
  stringstream ss;
  for (int i=0;i<(int)ans.size();i++) {
    ss << "Case #" << i+1 << ": " << ans[i] << endl;
  }
  s << ss.str();
  return s;
}

std::ostream& operator<<(std::ostream& s, const Solver& sol){
  return sol.dump(s);
}
