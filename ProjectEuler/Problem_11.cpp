#include <algorithm>
#include <boost/tuple/tuple.hpp>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int NUM = 20;
typedef vector<long long> line_t;
typedef vector<line_t> grid_t;
typedef pair<int, int> point_t;

long long productInAGrid(const grid_t& grid, const point_t& now, const point_t& delta){
  if(now.first + 3 * delta.first < 0 || now.first + 3 * delta.first >= NUM
      || now.second + 3 * delta.second < 0 || now.second + 3 * delta.second >= NUM){
    return -1;
  }

  long long ret = grid[now.first][now.second];
  for(int i = 1; i <= 3; i++){
    ret *= grid[now.first + delta.first * i][now.second + delta.second * i];
  }
  
  return ret;
}

long long largestProductInAGrid(){
  ifstream ifs("Problem_11.txt");
  grid_t grid;
  for(int i = 0; i < NUM; i++){
    line_t line;
    for(int j = 0; j < NUM; j++){
      long num;
      ifs >> num;
      line.push_back(num);
    }
    grid.push_back(line);
  }

  long long max = 0;
  for(int i = 0; i < NUM; i++){
    for(int j = 0; j < NUM; j++){
      point_t deltas[] = {make_pair(0, 1), make_pair(1, 0), make_pair(1, 1), make_pair(-1, 1)};
      for(int k = 0; k < 4; k++){
        max = std::max(max, productInAGrid(grid, make_pair(i, j), deltas[k]));
      }
    }
  }

  return max;
}

int main(){
  cout << largestProductInAGrid() << endl;
  return 0;
}

