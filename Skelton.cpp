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

template <class _Ans>
class Solver {
public:
  Solver(const char* in, const char* out) : ifs_(in), ofs_(out), now_(0) {
    if(!ifs_.is_open()){
      cerr << "input file is not found" << endl;
      assert(0);
    }
    ifs_ >> T_;
  }
  ~Solver(){ ifs_.close(); ofs_.close(); }
  bool hasNext(){ return (now_++)<T_; }

  //TODO change initial values
  void readTest(int* N){
    if(!ifs_.is_open()){
      cerr << "input file is not found" << endl;
      assert(0);
    }
    // TODO set init
    //    ifs_ >> *N;
  }

  void writeAns(_Ans ans){
    assert(now_<=0 || T_<=now_);
    ofs_ << "Case #" << now_ << ": ";
    ofs_ << ans << endl;
  }

private:
  ifstream ifs_; ofstream ofs_;
  int T_, now_;

public:
  // TODO change initial values
  _Ans solve(int N){
    _Ans ans;
    // TODO main logic

    return ans;
  }
};

int main() {
  // TODO change _Ans-type and filename
  Solver<int> s("sample.in", "sample.out");
  while(s.hasNext()){
    // TODO chenge initial values
    int N;
    // TODO change operands
    s.inputTest(&N);
    s.outputAns(s.solve(N));
  }

  return 0;
}
