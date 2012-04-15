#include <iostream>
#include "Solver.h"

using namespace std;

int main() {
  Solver s("data/B-large.in", "data/B-large.out");
  s.solve();
  s.output();

  return 0;
}
