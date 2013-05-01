// dfsÇ≈ëSëgÇ›çáÇÌÇπê∂ê¨

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
  enum{ INF = 1<<10 };
  vector<int> m, l, a;

  int subProblem(vector<int> colors, vector<int> need){
    int c = accumulate(colors.begin(), colors.end(), 0);
    int n = accumulate(need.begin(), need.end(), 0);
    if(n>c) return INF;

    int ans = n;
    for(int i=0; i<(int)colors.size() && i<(int)need.size(); i++){
      ans -= min(colors[i], need[i]);
    }

    return ans;
  }

  // @post INF Ç‹ÇΩÇÕ ç≈è¨ìhÇËë÷Ç¶âÒêî
  // ê[Ç≥óDêÊíTçıÇ≈ëSL-MëgÇ›çáÇÌÇπÇê∂ê¨
  // comb[i]==true means i-th a is assigned by midium
  int dfs(vector<bool> comb){
    if(comb.size()==a.size()){
      vector<int> mNeed, lNeed;
      for(int i=0;i<(int)a.size();i++){
        if(comb[i]){
          mNeed.push_back(a[i]);
        }else{
          lNeed.push_back(a[i]);
        }
      }
      int r1 = subProblem(m, mNeed);
      int r2 = subProblem(l, lNeed);

      return min(r1+r2, (int)INF);
    }

    int best = INF;
    for(int i=0;i<2;i++){
      comb.push_back(i);
      best = min(best, dfs(comb));
      comb.pop_back();
    }

    return best;
  }

public:
  int minRepaintings(vector<int> balloonCount, string balloonSize, vector<int> maxAccepted) {
    for(int i=0;i<(int)balloonSize.length();i++){
      if(balloonSize[i]=='M'){
        m.push_back(balloonCount[i]);
      }else{
        l.push_back(balloonCount[i]);
      }
    }
    a = maxAccepted;

    sort(m.rbegin(), m.rend());
    sort(l.rbegin(), l.rend());
    sort(a.rbegin(), a.rend());

    vector<bool> comb;
    int ans = dfs(comb);

    return (ans==INF) ? -1 : ans;
  }
};
