#include <iostream>
#include "Solver.h"

using namespace std;

int main() {
  Solver s("data/A-small-attempt0.in", "data/A-small-attempt0.out");
  s.input();
  cout << s; // dump

  s.solve();
  s.output();

  return 0;
}
