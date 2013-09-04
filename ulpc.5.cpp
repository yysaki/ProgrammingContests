#include <algorithm>
#include <iostream>
#include <sstream>
#include <limits>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <boost/tuple/tuple.hpp>
#include <cstdlib>
using namespace std;

class Time {
public:
  Time(){}
  Time(string row_str){
    std::replace(row_str.begin(), row_str.end(), ':', ' ');
    istringstream iss(row_str);
    iss >> hh >> mm >> ss;
  }

  bool operator<(const Time &rhs) const {
    if(hh < rhs.hh) return true;
    if(hh > rhs.hh) return false;
    if(mm < rhs.mm) return true;
    if(mm > rhs.mm) return false;
    if(ss < rhs.ss) return true;
    return false; // if(ss > rhs.ss)
  }

  string to_s(){
    ostringstream oss;
    oss << hh << ":" << mm << ":" << ss;
    return oss.str();
  }

private:
  int hh, mm, ss;
};

class Column {
public:
  Column(int t, int p, int c, string s) : t(t), p(p), c(c), s(s) {}
  int t, p, c;
  Time s;
};

class Status{
public:
  int team;
  int problems;
  Time last_commited;
  Status(){}
  Status(int t, int p, Time l) : team(t), problems(p), last_commited(l) {}
};


class CompColumnByTeamProblem {
public:
  bool operator()(const Column &lhs,const Column &rhs) const {
    if(lhs.t < rhs.t) return true;
    if(lhs.t > rhs.t) return false;
    if(lhs.p < rhs.p) return true;
    if(lhs.p > rhs.p) return false; 
    if(lhs.s < rhs.s) return true; 
    return false; //if(lhs.s >= rhs.s) 
  }
};

class CompColumnByTime {
public:
  bool operator()(const Column &lhs,const Column &rhs) const {
    return (lhs.s < rhs.s);
  }
};

class CompStatusByRank {
public:
  bool operator()(const Status &lhs,const Status &rhs) const {
    if(lhs.problems < rhs.problems) return false;
    if(lhs.problems > rhs.problems) return true;
    if(lhs.last_commited < rhs.last_commited) return false;
    return true;
  }
};

typedef vector<Column> container_t;

int T, G;
container_t container;

void arrange_container(){
  const container_t container_for_validate = container;
  container = container_t();
  for(container_t::const_iterator it = container.begin(); it != container.end(); ++it){
    if(it->c == 1){
      container.push_back(*it);
    }
  }
  for(int i = 0; i < (int)container_for_validate.size(); ++i){
    if(container_for_validate[i].c == 1){
      container.push_back(container_for_validate[i]);
    }
  }

  sort(container.begin(), container.end(), CompColumnByTeamProblem());
  const container_t container_for_uniq = container;
  container = container_t();
  for(int i = 0; i < (int)container_for_uniq.size() - 1; ++i){
    int count = 0;
    for(int j = i + 1; j < (int)container_for_uniq.size() - 1; ++j){
      if(container_for_uniq[i].t == container_for_uniq[j].t &&
          container_for_uniq[i].p == container_for_uniq[j].p){
        count++;
      }else{
        break;
      }
    }
    container.push_back(container_for_uniq[i]);
    i += count;
  }

  sort(container.begin(), container.end(), CompColumnByTime());
}

std::string solve(){
  arrange_container();

  vector<Status> statuses;
  for(int i = 0; i < T; ++i){
    statuses.push_back(Status(i, 0, Time()));
  }

  int goal_score = 9;
  for(int i = 0; i < (int)container.size(); ++i){
    if(container[i].p == G){
      statuses[container[i].t].problems += goal_score;
      goal_score = std::max(1, goal_score - 2);
    }else{
      statuses[container[i].t].problems++;
    }
    statuses[container[i].t].last_commited = Time(container[i].s);
  }
  
  sort(statuses.begin(), statuses.end(), CompStatusByRank());

  ostringstream oss;
  for(int i = 0; i < (int)statuses.size(); ++i){
    oss << statuses[i].team;
    if(i < (int)statuses.size() - 1){
      oss << " ";
    }
  }

  return oss.str();
}

int main(){
  int P, N;
  cin >> T >> P >> G >> N;
  while(T || P || G || N){
    container = container_t();

    for(int i = 0; i < N; ++i){
      int ti, pi, ci; 
      string si;
      cin >> ti >> pi >> ci >> si;

      container.push_back(Column(ti, pi, ci, si));
    }

    cout << solve() << endl;

    cin >> T >> P >> G >> N;
  }
  
  return 0;
}

