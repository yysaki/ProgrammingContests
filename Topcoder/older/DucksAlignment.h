// �����҂̐^��

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

class DucksAlignment {
	typedef pair<int, int> pos_t; // (y,x)

	public: int minimumTime(vector<string> grid) {
		const int H = grid.size();
		const int W = grid[0].size();
		for(int x=0;x<H;x++){
			for(int y=0;y<W;y++){
				cout << grid[x][y];
			}
			cout << endl;
		}

		// duck�̍��W
		vector<pos_t> pos;
		for(int x=0;x<H;x++){
			for(int y=0;y<W;y++){
				if(grid[x][y]=='o'){
					pos.push_back(pos_t(y,x));
				}
			}
		}
		// y�̏����Ƀ\�[�g
		sort(pos.begin(), pos.end());

		int ans = 10000;
		for(int i=0;i<H;i++){ // i,j�̓����牡�ɐ���
			for(int j=0;j<W-(int)pos.size()+1;j++){
				int dis = 0;
				for(int k=0;k<(int)pos.size();k++){
					int x1 = i;
					int y1 = j+k;
					int x2 = pos[k].second;
					int y2 = pos[k].first;
					dis += abs(x1-x2) + abs(y1-y2);
				}
				if(ans>dis){
					ans = dis;
				}
			}
		}


		return ans;
	}

};
