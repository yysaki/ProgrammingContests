// SRM 528 Div2 Middle
// 39:24.2
// Submit Errorなので見提出

// 方針 10の倍数のうなぎを昇順に調べcut, 10の倍数でないもののうなぎを昇順に調べcut, で最適解

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

class Cut {

public:
	int getMaximum(vector<int> eelLengths, int maxCuts) {
		int cutCount = 0;
		int pieceCount = 0;

		sort(eelLengths.begin(), eelLengths.end());

		for(vector<int>::iterator it=eelLengths.begin(); it!=eelLengths.end(); it++){
			if((*it)%10==0){
				if((*it)!=10){
					int plus = (*it)/10 -1;
					if(cutCount+plus>maxCuts){
						pieceCount += maxCuts - cutCount;
						cutCount = maxCuts;
						break;
					}
					pieceCount += plus + 1;
					cutCount += plus;
				}else{
					pieceCount++;
				}
			}
		}

		for(vector<int>::iterator it=eelLengths.begin(); it!=eelLengths.end(); it++){
			if((*it)%10!=0){
				int plus = (*it)/10;
				if(cutCount+plus>maxCuts){
					pieceCount += maxCuts - cutCount;
					cutCount = maxCuts;
					break;
				}
				pieceCount += plus;
				cutCount += plus;
			}
		}
		return pieceCount;
	}

};
