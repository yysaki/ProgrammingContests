
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// }}}

class DivideByZero
{
public:
  int CountNumbers(vector <int> numbers){
    if(numbers.size() == 1) return 1;
    vector<int> arr = numbers;
    std::sort(arr.rbegin(), arr.rend());
    vector<int> arr_prev = vector<int>();
    while(arr_prev != arr){
      arr_prev = arr;
      bool is_found = false;
      for (int i = 0; i < (int)arr.size(); i++) {
        for (int j = i + 1; j < (int)arr.size(); j++) {
          if(std::find(arr.begin(), arr.end(), (arr[i]/arr[j])) == arr.end()){
            arr.push_back(arr[i]/arr[j]);
            is_found = true;
            break;
          }
        }
        if(is_found) break;
      }
      std::sort(arr.rbegin(), arr.rend());
    }

    return (int)arr.size();

  }
};

