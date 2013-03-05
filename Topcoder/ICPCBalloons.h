/**
 * SRM 561 div2 mid
 *�@�×~�@, �r�b�g�}�X�N
 * ��: http://apps.topcoder.com/wiki/display/tc/SRM+561
 * bit mask: http://ja.wikipedia.org/wiki/%E3%83%9E%E3%82%B9%E3%82%AF_(%E6%83%85%E5%A0%B1%E5%B7%A5%E5%AD%A6)
 */

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

class ICPCBalloons {
  enum{ INF= 1<<10 };

//  void print(vector<int> bLC, vector<int> bMC, vector<int> maxAccepted){
//    vector<int>::iterator it;
//    cout << "L          : ";
//    for(it=bLC.begin();it!=bLC.end();it++) cout << *it << ", ";
//    cout << endl << "M          : ";
//    for(it=bMC.begin();it!=bMC.end();it++) cout << *it << ", ";
//    cout << endl << "maxAccepted: ";
//    for(it=maxAccepted.begin();it!=maxAccepted.end();it++) cout << *it << ", ";
//    cout << endl;
//  }

  /**
   * @post colors��need�����蓖�Ă��������̍ŏ��l, �o���Ȃ��ꍇ��INF
   */
  int subProblem(vector<int> colors, vector<int> need){
    sort(colors.rbegin(), colors.rend());
    sort(need.rbegin(), need.rend());

    int c = accumulate(colors.begin(), colors.end(), 0);
    int n = accumulate(need.begin(), need.end(), 0);

    if(n > c){
      return INF;
    }

    int cost = n;
    for(int i=0;i<(int)colors.size() && i<(int)need.size(); i++){
      cost -= min(colors[i], need[i]); // ���蓖�Ă�ύX���Ȃ��ōςސ�
    }

    return cost;
  }

public:
  int minRepaintings(vector<int> balloonCount, string balloonSize, vector<int> maxAccepted) {
    const int N = maxAccepted.size();
    int best = INF;

    vector<int> largeCount, midiumCount;
    for(int i=0;i<(int)balloonCount.size();i++){
      switch(balloonSize.at(i)){
        case 'L': largeCount.push_back(balloonCount[i]); break;
        default:  midiumCount.push_back(balloonCount[i]); break; // case 'M'
      }
    }

    //    print(bLC, bMC, maxAccepted);

    // M-L �̊��蓖�ĕ��̑S�g�ݍ��킹��subProblem���v�Z������
    // �g�ݍ��킹�p�^�[���̓r�b�g�}�X�N�Ő�������
    for(int mask=0; mask < (1<<N); mask++){
      vector<int> largeNeed, midiumNeed;

      // �}�X�N�ɂ����maxAccepted��L, M�Ɋ��蓖�Ă�
      for(int i=N-1; i>=0; i--){
        if(mask & (1<<i)){
          midiumNeed.push_back(maxAccepted[i]);
        }else{
          largeNeed.push_back(maxAccepted[i]);
        }
      }
      int r1 = subProblem(largeCount, largeNeed);
      int r2 = subProblem(midiumCount, midiumNeed);
      best = min(best, r1+r2);
    }

    return (best==INF) ? -1 : best;
  }
};
