// 26:12.21
// 選ばなかった箱の容量がC-X以下であるような, 最小の選び方をする

#include <algorithm>
#include <vector>

using namespace std;

class MysticAndCandiesEasy{
public:
  int minBoxes(int C, int X, vector <int> high){
    vector<int> arr = high;
    std::sort(arr.begin(), arr.end());

    int cnt;
    int sum = 0;
    for (cnt = 0; cnt < (int)arr.size(); cnt++) {
      sum += arr[cnt];
      if(sum > C -X){
        break;
      }
    }

    return (int)high.size() - cnt;
  }
};

