#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

unordered_set<int> best;
int n,k;

unordered_set<int> nodes, temp;
vector<unordered_set<int> > g;

void pv(vi const &v){
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it+1 << " ";
  }cout << endl;
}

void pv(unordered_set<int> const &v){
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it+1 << " ";
  }cout << endl;
}

void run(){
  for (auto it = nodes.begin(); it != nodes.end();) {
    int v = *it;
    int next;
    if(g[v].empty()){
      if (++it == nodes.end()) {
	next = -1;
      }else next = *(it);
      nodes.erase(v);
      temp.insert(v+1);
      if(nodes.empty()){
	if (best.size()<temp.size()) {
	  best = temp;
	}
      }
      if(next == -1)break;
      it = nodes.find(next);
      continue;
    }
    
    if (++it == nodes.end()) {
      next = -1;
    }else next = *(it);
    vi erased;
    nodes.erase(v);
    temp.insert(v+1);
    if(nodes.empty()){
      if (best.size()<temp.size()) {
	best = temp;
      }
      nodes.insert(v);
      temp.erase(v+1);
      return;
    }
    for (auto nl = g[v].begin(); nl != g[v].end(); ++nl) {
      if(nodes.erase(*nl))erased.push_back(*nl);
      if(nodes.empty()){
	if (best.size()<temp.size()) {
	  best = temp;
	}
	//nodes.insert(v);
	temp.erase(v+1);
	nodes.insert(erased.begin(),erased.end());
	run();
	//return;
      }
    }
    run();
    nodes.insert(v);
    temp.erase(v+1);
    nodes.insert(erased.begin(),erased.end());
    if(next == -1)break;
    it = nodes.find(next);
  }
}

int main()
{
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    best.clear();
    nodes.clear();
    g.clear();
    temp.clear();
    cin >> n >> k;
    for (int j = 0; j < n; ++j)nodes.insert(j);
    g.resize(n);
    for (int j = 0; j < k; ++j) {
      int u,v;
      cin >> u >> v;
      g[u-1].insert(v-1);
      g[v-1].insert(u-1);
    }

    run();

    set<int> ans(best.begin(),best.end());
    cout << best.size() << endl;
    for (auto it = ans.begin(); it != ans.end();) {
      auto cit = it;
      if (++cit == ans.end()) {
	cout << *it;
	it++;
      }else {
	cout << *it << " ";
	it++;
      }
    }cout << endl;
    
  }
  return 0;
}
