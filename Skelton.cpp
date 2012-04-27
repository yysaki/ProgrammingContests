#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/tokenizer.hpp>

using namespace std;

class Solver {
public:
  Solver(const char* in, const char* out) : ifs(in), ifName(in), ofName(out) {
    if(!ifs.is_open()){
      std::cout << ifName << " is not found" << std::endl;
      assert(0);
    }
    ifs >> T;
  }
  ~Solver(){ ifs.close(); }

  std::ostream& dump(std::ostream& s) const{
    stringstream ss;
    for (int i=0;i<T;i++) {
      // TODO
      //      ss << "Case #" << i+1 << ": " << answers[i] << endl;
    }
    s << ss.str();
    return s;
  }
  void output() const {
    std::ofstream ofs(ofName);
    dump(ofs);
  }

  void solve(){
    for(int test=0;test<T;test++){
      // test–ˆ‚ÉinputTest‚Å‰Šú‰», ŒvŽZ, answers‚É’~Ï
      // TODO
    }
  }

private:
  void inputTest(int* N, int* S, int* p, std::vector<int>* t){
    if(!ifs.is_open()){
      cout << ifName << " is not found" << endl;
      assert(0);
    }
    // TODO
    //    ifs >> *N >> *S >> *p;
  }

  std::ifstream ifs;
  const char* ifName; const char* ofName;
  int T;
  std::vector<int> answers;
};

std::ostream& operator<<(std::ostream& s, const Solver& sol){ return sol.dump(s); }

int main() {
  // TODO
  Solver s("data/B-large.in", "data/B-large.out");
  s.solve();
  s.output();

  return 0;
}
