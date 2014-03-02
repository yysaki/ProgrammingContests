// erase()参考: http://yasu2.prosou.nu/blog/2008/04/stdmap-stdvector-erase.html
// 解けた 36:13
// 答え合わせ http://apps.topcoder.com/wiki/display/tc/SRM+606 1:02:10
// topcoderのコンパイラはforeach文を使えるらしい

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class EllysNumberGuessing{
public:
  // mine
  int getNumber(vector <int> guesses, vector <int> answers){
    const int max = 1000000000;
    const int n = guesses.size();
    vector<int> g = guesses;
    vector<int> a = answers;

    vector<int> pos;

    if(g[0] + a[0] <= max){
      pos.push_back(g[0] + a[0]);
    }
    if(g[0] - a[0] > 0 && g[0] + a[0] != g[0] - a[0]){
      pos.push_back(g[0] - a[0]);
    }

    if(pos.size() == 0) return -2;
    if(pos.size() == 1) return pos[0];

    for (int i = 1; i < n; i++) {
      for(vector<int>::iterator it = pos.begin(); it != pos.end(); ){
        if(g[i] + a[i] != *it && g[i] - a[i] != *it){
          it = pos.erase(it);
        }else{
          ++it;
        }
      }
      if(pos.size() == 0) return -2;
    }

    return pos.size() == 1 ? pos[0] : -1;
  }

  // official
//  int getNumber(vector <int> guesses, vector <int> answers){
//    int options[] = { guesses[0] + answers[0], guesses[0] - answers[0] };
//    int res = -2;
//    for (int i = 0; i < 2; i++) {
//      const int option = options[i];
//      bool isValid = (1 <= option && option <= 1000000000);
//      for (int j = 0; j < (int)guesses.size(); j++) {
//        isValid = isValid && (std::abs(guesses[j] - option) == answers[j]);
//      }
//
//      if(isValid){
//        if(res == -2){
//          res = option;
//        }else{
//          res = -1;
//        }
//      }
//    }
//
//    return res;
//  }

};

