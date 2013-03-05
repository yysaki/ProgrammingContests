// SRM 564 Div2 Easy
// ŠÔ‚ÉŠÔ‚É‡‚Á‚½‚ªstd::string::erase ‚Ìˆµ‚¢‚É‚à‚½‚Â‚¢‚½

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class FauxPalindromes {

  public: string classifyIt(string word) {
    int N = word.length();

    bool isPalindrome = true;
    for(int i = 0; i < N; i++){
      if(word[i]!=word[N-i-1]){
        isPalindrome = false;
      }
    }
    if(isPalindrome) return "PALINDROME";

    for(int i = 0; i < N; i++){
      for(int j = i + 1; j < N; j++){
        // check i to j
        if(word[i]!=word[j]){
          break;
        }else{
          word[j] = '_';
        }
      }
    }

    while(word.find('_')!=string::npos){
      word.erase(word.find('_'),1);
    }

    N = word.length();
    bool isFaux = true;
    for(int i = 0; i < N; i++){
      if(word[i]!=word[N-i-1]){
        isFaux = false;
      }
    }
    if(isFaux) return "FAUX";

    return "NOT EVEN FAUX";
  }

};
