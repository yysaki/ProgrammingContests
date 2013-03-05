/*
 * TwiceString.h
 *
 *  Created on: 2011/09/14
 *      Author: yysaki
 */
#include <iostream>
#include <string>
#include <vector>

#ifndef TWICESTRING_H_
#define TWICESTRING_H_

/* moved */
class TwiceString {
public:
	TwiceString();
	virtual ~TwiceString();

	std::string getShortest(std::string s);
};

#endif /* TWICESTRING_H_ */
