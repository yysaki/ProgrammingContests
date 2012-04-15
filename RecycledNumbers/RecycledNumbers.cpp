#include <iostream>
#include "ProblemCSolver.h"

using namespace std;

int main() {
  ProblemCSolver s("data/C-large-practice.in", "data/C-large-practice.out");
  s.solve();
  s.output();

  return 0;
}
