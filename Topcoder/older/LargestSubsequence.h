// 間に合わず, 他のCoderさん参考

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
	 * x,y: yはxの部分列
	 * 辞書式順序で最大のyを求める
	 *
	 */
	std::string getLargest(std::string s);
};


#endif /* LARGESTSUBSEQUENCE_H_ */
