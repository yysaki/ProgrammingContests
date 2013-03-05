// SRM 528 Div2 Easy
// 45:12.4
// Submit ErrorÇ»ÇÃÇ≈ñ¢íÒèo

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

class MinCostPalindrome {

public:
	int getMinimum(string s, int oCost, int xCost) {
		int totalCosts = 0;
		string::iterator it = s.begin();
		string::reverse_iterator r_it = s.rbegin();

		for(int i=0;i<(int)s.size()/2;i++){
			switch(*it){ // è∏èá
			case('x'):
				switch(*r_it){ // ç~èá
				case('x'):
					break;
				case('o'):
					return -1;
				default: // case('?')
					totalCosts += xCost;
					break;
				}
				break;
			case('o'):
				switch(*r_it){ // ç~èá
				case('x'):
					return -1;
				case('o'):
					break;
				default: // case('?')
					totalCosts += oCost;
					break;
				}
				break;
			default: // case('?')
				switch(*r_it){ // ç~èá
				case('x'):
					totalCosts += xCost;
					break;
				case('o'):
					totalCosts += oCost;
					break;
				default: // case('?')
					totalCosts += 2 * min(oCost, xCost);
					break;
				}
				break;
			}
			it++; r_it++;
		}

		return totalCosts;
	}
};
