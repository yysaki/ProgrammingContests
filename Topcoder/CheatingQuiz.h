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

class CheatingQuiz {
	int countChar(string answers, char target){
		int count = 0;
		string::iterator it = answers.begin();
		while(it!=answers.end()){
			if(*it==target){
				count++;
			}
			it++;
		}
		return count;
	}
public:
	vector<int> howMany(string answers) {
		int numA = countChar(answers, 'A');
		int numB = countChar(answers, 'B');
		int numC = countChar(answers, 'C');
		int choices  = 3;;
		if(numA==0){ choices--; }
		if(numB==0){ choices--; }
		if(numC==0){ choices--; }
		vector<int> ans;
		string::iterator it = answers.begin();
		while(it!=answers.end()){
			switch(*it){
			case 'A':
				numA--;
				ans.push_back(choices);
				if(numA==0){
					choices--;
				}
				break;
			case 'B':
				numB--;
				ans.push_back(choices);
				if(numB==0){
					choices--;
				}
				break;
			case 'C':
				numC--;
				ans.push_back(choices);
				if(numC==0){
					choices--;
				}
				break;
			}

			it++;
		}

		return ans;
	}

};
