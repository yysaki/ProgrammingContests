/**
 * SRM 577 div2 Easy
 * answered
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <limits>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
using namespace std;

class EllysNewNickname {
  bool isVowel(char arg){
    static char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for(int i=0;i<6;i++){
      if(arg==vowels[i]){
        return true;
      }
    }
    return false;
  }

public: 
	int getLength(string nickname) {
	  int count = (int)nickname.size();
	  for(int i = 0; i < (int)nickname.size(); i++){
	    if(isVowel(nickname[i]) && i < (int)nickname.size()){
	      for(i++; i < (int)nickname.size(); i++){
	        if(!isVowel(nickname[i])) break;
	        count--;
	      }
	    }
	  }
		return count;
	}

};
