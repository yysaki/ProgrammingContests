// ä‘Ç…çáÇÌÇ∏, ëºÇÃCoderÇ≥ÇÒéQçl
/*
 * LargestSubsequence.cpp
 *
 *  Created on: 2011/09/14
 *      Author: yysaki
 */

#include <iostream>
#include <string>
#include <vector>

#include "LargestSubsequence.h"

using namespace std;

LargestSubsequence::LargestSubsequence(){
	cout << "constructor is called" << endl;
}
LargestSubsequence::~LargestSubsequence(){}


/*
 * x,y: yÇÕxÇÃïîï™óÒ
 * é´èëéÆèáèòÇ≈ç≈ëÂÇÃyÇãÅÇﬂÇÈ
 *
 */

string LargestSubsequence::getLargest(string s){
	int length = s.length();

	string ans = "";
	char c;
	int index = 0, indexPrev;

	string::iterator it;
	while(index<length){
		cout << "index: " << index << endl;
		indexPrev = index;

		it = s.begin() + index;
		c = '0';
		while(it!=s.end()){
			if(*it>c){
				c = *it;
				cout << "c: " << c << endl;
				index = distance(s.begin(),it);
			}
			it++;
		}
		if(c>'0'){
			ans += c;
		}
		index++;
	}
	return ans;
};

