#include <iostream>
#include <fstream>
#include <vector>


#ifndef PROBLEMCSOLVER_H_
#define PROBLEMCSOLVER_H_

class ProblemCSolver{
public:
  ProblemCSolver(const char* in, const char* out);
  virtual ~ProblemCSolver();
  bool solve();
  bool output() const;
  std::ostream& dump(std::ostream& s) const;
private:
  int getDigits(int x) const;
  bool isRecyclable(int A, int B, int n, int digit) const;
  int recycle(int n, int digit) const;
  bool inputLine(int* A, int* B);
  std::ifstream ifs;
  const char* inputFile;
  const char* outputFile;
  int TNum;
  std::vector<int> answers;
};

std::ostream& operator<<(std::ostream& s, const ProblemCSolver& sol);

#endif /* PROBLEMCSOLVER_H_ */
