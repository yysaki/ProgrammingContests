#include <algorithm>
#include <vector>
using namespace std;

class DeerInZooDivTwo
{
public:
	vector <int> getminmax(int N, int K) {
    vector<int> ans;
    ans.push_back(max(N - K, 0));
    ans.push_back(N - K/2 - K%2);
		return ans;
	}
};

