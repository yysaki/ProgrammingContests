/*
 * LotteryTest.cpp
 *
 *  Created on: 2011/09/24
 *      Author: yysaki
 */

#define BOOST_TEST_MODULE MeikaiCpp
#include <boost/test/included/unit_test.hpp> // libboost_unit_test_framework-mt のリンク必要無し！

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


#include "Lottery.h"
BOOST_AUTO_TEST_CASE( lottery_test ){

	strvec_t rules0;
	rules0.push_back("PICK ANY TWO: 10 2 F F");
	rules0.push_back("PICK TWO IN ORDER: 10 2 T F");
	rules0.push_back("PICK TWO DIFFERENT: 10 2 F T");
	rules0.push_back("PICK TWO LIMITED: 10 2 T T");

	strvec_t::iterator it = rules0.begin();
	while(it!=rules0.end()){
		cout << *it << endl;
		it++;
	}

	Lottery lottery;
	strvec_t ans0 = lottery.sortByOdds(rules0);
	BOOST_CHECK(1);
}
