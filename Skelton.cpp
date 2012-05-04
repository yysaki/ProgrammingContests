#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <cassert>

using namespace std;

template <class _Ans>
class Solver {
public:
  Solver(const char* in, const char* out) : ifs_(in), ofs_(out), now_(0) {
    assert(ifs_.is_open());
    ifs_ >> T_;
  }
  ~Solver(){ ifs_.close(); ofs_.close(); }
  bool hasNext(){ return (now_++)<T_; }

  //TODO change initial values
  void readTest(int* param){
    assert(ifs_.is_open());
    // TODO set init
        ifs_ >> *param;
  }

  void writeAns(_Ans ans){
    assert(0<now_ || now_<=T_);
    ofs_ << "Case #" << now_ << ": ";
    ofs_ << ans << endl;
  }

private:
  ifstream ifs_; ofstream ofs_;
  int T_, now_;

public:
  // TODO change initial values
  _Ans solve(int param){
    /* TODO main logic */

    _Ans ans;
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
    s.readTest(&N);
    s.writeAns(s.solve(N));
  }

  return 0;
}
