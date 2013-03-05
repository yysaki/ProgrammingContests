// ŠÔ‚É‡‚í‚¸, ‘¼‚ÌCoder‚³‚ñQl

/*
 * LargestSubsequence.h
 *
 *  Created on: 2011/09/14
 *      Author: yysaki
 */

#ifndef LARGESTSUBSEQUENCE_H_
#define LARGESTSUBSEQUENCE_H_

#include <iostream>
#include <string>
#include <vector>

class LargestSubsequence {

public:
	LargestSubsequence();
	virtual ~LargestSubsequence();

	/*
	 * x,y: y‚Íx‚Ì•”•ª—ñ
	 * «‘®‡˜‚ÅÅ‘å‚Ìy‚ğ‹‚ß‚é
	 *
	 */
	std::string getLargest(std::string s);
};


#endif /* LARGESTSUBSEQUENCE_H_ */
