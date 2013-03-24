/*
 * Solver.h
 *
 *  Created on: 2012/04/14
 *      Author: yysaki
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <iostream>
#include <fstream>
#include <vector>

class Solver {
public:
  Solver(const char* in, const char* out);
  virtual ~Solver();
  bool solve();
  bool output() const;
  std::ostream& dump(std::ostream& s) const;
  std::ostream& debugPrint(std::ostream& s, int N, int S, int p, std::vector<int> t) const;
private:
  bool judge(int ti, bool s, int p) const;
  bool inputLine(int* N, int* S, int* p, std::vector<int>* t);
  std::ifstream ifs;
  const char* inputFile;
  const char* outputFile;
  int TNum;
  std::vector<int> answers;
};

std::ostream& operator<<(std::ostream& s, const Solver& sol);

#endif /* SOLVER_H_ */
