// http://d.hatena.ne.jp/komiyam/20111201/1322674379 参考
// [0,0] - [i,j] のコイン数 => height * width回
// 部分長方形のコイン数 => 1/2*height*(height+1) * 1/2*width*(width+1) 回

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class DropCoins {

public:
	int getMinimum(vector<string> board, int K) {
		const int height = board.size();
		const int width = board[0].size();
		const int inf = width+height;

		int nums[height+1][width+1]; // [0,0] -[x,y] 範囲のコイン数
		// init
		memset(nums,0,sizeof(nums));
		for(int i=1;i<height+1;i++){
			for(int j=1;j<width+1;j++){
				nums[i][j] = nums[i-1][j] + nums[i][j-1] - nums[i-1][j-1] + (board[i-1][j-1]=='o' ? 1 : 0);
			}
		}
		cout << "coins: " << endl;
		cout << endl;
		for(int i=0;i<height;i++){
			cout << "   " ;
			for(int j=0;j<width;j++){
				cout << setw(3) << board[i][j];
			}
			cout << endl;
		}
		cout << "nums: " << endl;
		for(int i=0;i<height+1;i++){
			for(int j=0;j<width+1;j++){
				cout << setw(3) << nums[i][j];
			}
			cout << endl;
		}

		int count = inf;

		for(int x1=0;x1<height;x1++){
			for(int x2=x1+1;x2<=height;x2++){
				for(int y1=0;y1<width;y1++){
					for(int y2=y1+1;y2<=width;y2++){
						int sum = nums[x2][y2] - nums[x1][y2] - nums[x2][y1] + nums[x1][y1];
						if(sum==K){
							int countX = min(x1,height-x2) * 2 + max(x1,height-x2);
							int countY = min(y1,width-y2) * 2 + max(y1,width-y2);
							count = min(count, countX+countY);
							cout << "(" << x1 << "," << y1 << ") - (" << x2 <<"," << y2 << "): ["
									<< countX << ", " << countY << " => " << countX+countY << "]" << endl;
						}
					}
				}
			}
		}

		return (count!=inf) ? count : -1;
	}

};
