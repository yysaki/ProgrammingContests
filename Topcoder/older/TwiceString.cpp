/*
 * TwiceString.cpp
 *
 *  Created on: 2011/09/14
 *      Author: yysaki
 */

#include "TwiceString.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

TwiceString::TwiceString(){}
TwiceString::~TwiceString(){}

/*
 * s‚ğ•”•ª•¶š—ñ‚Æ‚µ‚Ä2‚Â‚ÂÅ¬‚Ìstring
 */
string TwiceString::getShortest(string s){
	string longestS = s+s;
	cout << "longest: " << longestS << endl;

	//s + s‚Ìæ“ª‚ğí‚Á‚½string
	string::reverse_iterator rit = s.rbegin();
	string::reverse_iterator rend = s.rend();
	string::iterator end= s.end();

	string tmp;
	string rev = "";
	int first, second;
	while(rit!=rend){
		rev = *rit + rev;
		tmp = s + rev;
		cout << "tmp: " << tmp << endl;

		// twicestring‚Ì”»’è
		first = tmp.find(s);
		second = tmp.rfind(s);
		cout << "first: " << first << ", second: " << second << endl;
		if(first!=(int)string::npos && first!=second){
			return tmp;
		}
		rit++;
	}
//		string shortestS = s;
//		shortestS +=;


	return longestS; // "topcoder"‚È‚çOK
}

