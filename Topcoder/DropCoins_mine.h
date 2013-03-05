// 3/5�����A����� �������Ȃǂ̑���ɖ��Ή�

// ���j: �S�T��
//�@�@�E�㉺���E�̂����͏c��������g�������Ƃ��Ăǂ��炩��n��{�[�h�����炷
// 	 �Econtainer�T�C�Y�͏c�����~�������~board�T�C�Y��荂�X3600��Ɣ��f
// 	 �E���������0�b��ŉ������A�����܂ň����͂Ȃ����x
//

// �𓚗�
// http://d.hatena.ne.jp/komiyam/20111201/1322674379
// �{�[�h���ɕ��������`���`���A���̒��̃R�C���𒲂ׂ�
// (x1,y1), (x2,y2)�̕��������`�����ɂ́Amin(x1,w-x2)*2+max(x1,w-x2)+min(y1,h-y2)*2+max(y2,h-y2)��
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

class DropCoins {
private:
	typedef enum {Up, Down, Left, Right} dir_t;
	typedef std::pair<dir_t,dir_t> pair_t;
	typedef vector<pair_t> case_t;
	typedef vector<string> board_t;
	typedef pair<int, int> record_t; // coinNum, countNum
	typedef vector<record_t> container_t;

	int getCoinNum(const board_t board){
		int count = 0;
		for(int i=0;i<(int)board.size();i++){
			for(int j=0;j<(int)board[0].size();j++){
				if(board[i][j]=='o'){
					count++;
				}
			}
		}
		return count;
	}
	board_t eraseDir(const board_t board, dir_t dir){
		board_t cpy = board;
		board_t::iterator it;
		switch(dir){
		case Up:
			cpy.erase(cpy.begin());
			break;
		case Down:
			cpy.erase(cpy.end()-1);
			break;
		case Left:
			it = cpy.begin();
			while(it!=cpy.end()){
				it->erase(0);
				it++;
			}
			break;
		case Right:
			it = cpy.begin();
			while(it!=cpy.end()){
				it->erase(it->end()-1);
				it++;
			}
			break;
		}
		return cpy;
	}

public: int getMinimum(vector<string> board, int K) {
	int rows = board.size(); // �s
	int cols = board[0].size(); // ��

	container_t container;
	case_t cases;
	cases.push_back(pair_t(Up,Left));
	cases.push_back(pair_t(Up,Right));
	cases.push_back(pair_t(Down,Left));
	cases.push_back(pair_t(Down,Right));

	case_t::iterator case_it = cases.begin();

	while(case_it!=cases.end()){
		board_t copy_1 = board;
		for(int i=0;i<rows;i++){

			int coinNum;
			board_t copy_2 = copy_1;
			for(int j=0;j<cols;j++){
				coinNum = getCoinNum(copy_2);
				container.push_back(record_t(coinNum, (i+j)));
				if(coinNum==K){
					break;
				}

				if (copy_2.size()>1) {
					copy_2 = eraseDir(copy_2, case_it->first);
				}
			}
			if(coinNum==K){
				break;
			}
			if (copy_1.size()>1) {
				copy_1 = eraseDir(copy_1, case_it->second);
			}
		}
		case_it++;
	}

	container_t::iterator ct_it = container.begin();
	int count = rows+cols;
	while(ct_it!=container.end()){
		if(ct_it->first==K){
			count = min(ct_it->second,count);
		}
		ct_it++;
	}
	if(count==rows+cols){
		return -1;
	}else{
		return count;
	}
}
};
