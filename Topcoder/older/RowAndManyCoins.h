#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class RowAndManyCoins {
private:
	string Alice, Bob;
	string cells;
	int N;
public:
//	//1�X�e�b�v��player�̏�����Ԃ����邩
//	bool canBeWinAtOneStep(string player){
//		return false;
//	}
//
//	//player�̏�����Ԃ�
//	bool isWin(string player){
//		char check = '\0';
//		for(int i=0;i<N;i++){
//			if(cells[i]!='C'){
//				if(check=='\0'){
//					check = cells[i];
//				}else{
//					return false;
//				}
//			}
//		}
//		if(check==player[0]){
//			return true;
//		}else{
//			return false;
//		}
//	}
//
//	// �w��ꏊ�ɃR�C������ׂ�
//	void placeCoins(int start, int end){
//		for(int i=start;i<end;i++){
//			cells[i] = 'C';
//		}
//	}
//
//	//
	string getWinner(string input_cells) {
		cells = input_cells;
		N = cells.length();
		Alice = "Alice"; Bob = "Bob";

		if(cells[0]==Alice[0] || cells[N-1]==Alice[0]){
			return Alice;
		}else{
			return Bob;
		}
	}

};
