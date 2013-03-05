/**
 * SRM 562 div2 easy
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

class CucumberMarket {

  public: string check(vector<int> price, int budget, int k) {
    std::sort(price.rbegin(), price.rend());
    int sum = 0;
    for(int i=0;i<k;i++){
      sum += price[i];
    }

    return (sum<=budget) ? "YES" : "NO";
  }

};
