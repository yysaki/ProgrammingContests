/*
 * Solver.h
 *
 *  Created on: 2012/04/14
 *      Author: yysaki
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <iostream>
#include <vector>

class Solver {
public:
  Solver(const char* in, const char* out) : inputFile(in), outputFile(out) {}
  virtual ~Solver(){}
  bool input();
  bool solve();
  bool output() const;
  std::ostream& dump(std::ostream& s) const;
private:
  char convert(const char c) const;
  const char* inputFile;
  const char* outputFile;
  int N;
  std::vector<std::string> q;
  std::vector<std::string> ans;
};

std::ostream& operator<<(std::ostream& s, const Solver& sol);

#endif /* SOLVER_H_ */
