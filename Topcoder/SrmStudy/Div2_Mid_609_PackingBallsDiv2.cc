#include <algorithm>
#include <iostream>

using namespace std;

class PackingBallsDiv2
{
public:
	int minPacks(int R, int G, int B){
    int arr[3] = {R, G, B};
    std::sort(arr, arr+3);
    int pack = arr[0];
    arr[1] -= arr[0];
    arr[2] -= arr[0];
    pack += (arr[1] / 3) + (arr[2] / 3);
    arr[1] = arr[1] % 3;
    arr[2] = arr[2] % 3;
    if(arr[1] == 0){
      if(arr[2] >= 1){
        pack += 1;
      }
    }else if(arr[1] == 1){
      if(arr[2] <= 1){
        pack += 1;
      }else{
        pack += 2;
      }
    }else{
      if(arr[2] == 0){
        pack += 1;
      }else{
        pack += 2;
      }
    }
  
		return pack;
	}
};

