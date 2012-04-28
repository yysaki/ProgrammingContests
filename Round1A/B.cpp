// http://code.google.com/codejam/contest/1645485/dashboard#s=p1

// ����: ���Ԑ؂�
// small-practice OK
// large-practice NG
// ���̕��j: B[i]>A[i]�̏��Ń����_���Ɍ��āAB[i]�I�����ɑ��̓K�؂�A[j]�������A[i]�� A[j]��u��������

// �Q�l(SnapDragon)�̕��j: A�͍œK��A[i](�����𖞂���B[i]���ő�)���珇�ɑI������

// ����: �œK��A�̎擾�������l����ׂ�

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
      ss << "Case #" << i+1 << ": " << answers[i] << endl;
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
      cout << "==test " << test+1 << endl;
      int N;
      vector<int> A, B; // a: �P��, b: 2�� �ɂ����遚
      inputTest(&N, &A, &B);

      int now = 0, step = 0;
      vector<int> done(N, 0);
      // mine
      //      vector<int> prev(N, INT16_MIN);
      //      vector<bool> CompA, CompB;

      while(now<2*N){
        step++;
        bool isFound = false;

        // 2-star search
        for(int i=0;i<N;i++) if(done[i]<2 && now>=B[i]){
          cout << "B[" << i << "]" << endl;
          isFound = true;
          now += 2-done[i];
          done[i] = 2;

          // mine
          // A[i]���� A[j]�ɁA1-star�����蓖�ĉ\�Ȏ�
          // bug!!! switch������������
          //          for(int j=0;j<N;j++) if(done[j]<1 && prev[i]>=A[j]){
          //            cout << "=switch A[" << i << "] to A[" << j << "]" << endl;
          //            prev[j] = prev[i];
          //            now += 1-done[j];
          //            done[j] = 1;
          //
          //            break;
          //          }

          break;
        }

        // 1-star search
        if(!isFound){
          int bestI = -1;
          for(int i=0;i<N;i++) if(done[i]<1 && now>=A[i]){
            if(bestI==-1 || B[i]>B[bestI]){
              bestI = i;
            }
          }
          if(bestI!=-1){
            cout << "A[" << bestI << "]" << endl;
            isFound = true;
            now += 1-done[bestI];
            done[bestI] = 1;
          }
          // mine
          //          for(int i=0;i<N;i++) if(done[i]<1 && now>=A[i]){
          //            cout << "A[" << i << "]" << endl;
          //            isFound = true;
          //            prev[i] = now;
          //            now += 1-done[i];
          //            done[i] = 1;
          //
          //            break;
          //          }
        }

        if(!isFound) break;
      } // end while

      stringstream ans;
      if(now==2*N){ // isBad
        ans << step;
      }else{
        cout << "now: " << now << endl;
        ans << "Too Bad";
      }
      cout << "==ans " << ans.str() << endl;
      answers.push_back(ans.str());
    }
  }

private:
  void inputTest(int* N, vector<int>* a, vector<int>* b){
    if(!ifs.is_open()){
      cout << ifName << " is not found" << endl;
      assert(0);
    }
    ifs >> *N;
    for(int i=0;i<*N;i++){
      int tmp;
      ifs >> tmp;
      a->push_back(tmp);
      ifs >> tmp;
      b->push_back(tmp);
    }
  }

  std::ifstream ifs;
  const char* ifName; const char* ofName;
  int T;
  std::vector<string> answers;
};

std::ostream& operator<<(std::ostream& s, const Solver& sol){ return sol.dump(s); }

int main() {
  Solver s("data/sample.in", "data/sample.out");
  //  Solver s("data/B-large-practice.in", "data/B-large-practice.out");
  s.solve();
  s.output();

  cout << s;

  return 0;
}
