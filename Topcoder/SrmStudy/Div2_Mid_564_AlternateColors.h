// SRM 564 Div2 Mid
// ŠÔØ‚ê‚¾‚ªƒ`ƒƒƒŒƒ“ƒW’†‚Éì¬‚Å‚«‚½

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

class AlternateColors {

public:
  string getColor(long long r, long long g, long long b, long long k) {
    int color = 7;
    int red = 2, green = 4, blue = 1;
    long long c[8];
    c[red] = red; c[green] = green; c[blue] = blue;
    int first, second, third;
    long long mini = min(min(r,g),b), maxi = max(max(r,g),b), middle;

    if(maxi == mini){
      first = second = third = 7;
    }else{
      if(r == mini){ first = red; }
      else if(g == mini){ first = green; }
      else if(b == mini){ first = blue; }
      if(r == maxi){ third = red; }
      else if(g == maxi){ third = green; }
      else if(b == maxi){ third = blue; }
      second = color - first -third;
      middle = c[second];
    }

    cout << first << second << third << endl;

    int ans = 0;
    if(k < mini*3){
      ans = 1<<(k%3);
    }else{
      k -= mini*3;
      color -= first;
      if(k < (middle-mini)*2){
        if(k%2==1){
          if(first!=red) ans = red;
          else if(first!=green) ans = green;
          else ans = blue;
        }else{
          if(first!=blue) ans = blue;
          else if(first!=green) ans = green;
          else ans = red;
        }
      }else{
        ans = third;
      }
    }

    return (ans==red)   ? "RED" :
           (ans==green) ? "GREEN" :
                          "BLUE";
  }

};
