#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define vi vector<int>
#define si set<int>
#define f first
#define s second
#define ii pair<int,int>
#define vvi vector<vi>
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

template<class T>
inline void pv(T const & v, char c){
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it;
    auto ite = it;
    if (++ite == v.end())continue;
    else if(c!='x'){cout << c;}
  }cout << endl;
}

template<class T>
inline void pa(T const v[],int n, char c){
  for (int i = 0; i < n; ++i) {
    cout << v[i];
    if (i==n-1)continue;
    else if(c!='x'){cout << c;}
  }
  cout << endl;
}


template<class T>
inline void pvv(T const & vv, char c){
  for (auto it = vv.begin(); it != vv.end(); ++it) {
    pv(*it,c);
  }
}


inline void iv(vi &v,int n){
  for (int i = 0; i < n; ++i) {
    int temp;
    scanf("%d",&temp);
    v.push_back(temp);
  }
}

inline void is(si &v,int n){
  for (int i = 0; i < n; ++i) {
    int temp;
    scanf("%d",&temp);
    v.insert(temp);
  }
}

template<class T>
inline void ia(T a[],int n){
  for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
}

//global variables

int main(){
  int n,k;
  while (scanf("%d %d ", &n,&k)!=EOF) {
    int t[n];
    for (int i = 0; i < n; i++)scanf("%d ", &t[i]);
    vvi lis(n,vi());
    vector<vector<ii> > adj(100,vector<ii>());
    for (int i = 0; i < n; i++) {
      string st;
      getline(cin, st);
      stringstream ss(st);
      int tmp;
      while (ss>>tmp)lis[i].push_back(tmp);
      for (int j = 0; j < (int)lis[i].size(); j++) {
        for (int k = j+1; k < (int)lis[i].size(); k++) {
          int u = lis[i][j]; int v = lis[i][k];
          int fw = u==0 ? v*t[i] : (v-u)*t[i]+60;
          int bw = (v-u)*t[i]+60;
          adj[u].push_back(ii(v,fw));
          adj[v].push_back(ii(u,bw));
        }
      }
    }
    vi dist(100,(1<<30)-1);
    dist[0] = 0;
    priority_queue<ii,vector<ii>,greater<ii> > q;
    q.push(ii(0,0));
    while (!q.empty()) {
      ii tmp = q.top(); q.pop();
      int d = tmp.f; int u = tmp.s;
      if(d>dist[u])continue;
      for (int i = 0; i < (int)adj[u].size(); i++) {
        ii nei = adj[u][i];
        if (dist[u]+nei.s<dist[nei.f]) {
          dist[nei.f] = dist[u] + nei.s;
          q.push(ii(dist[nei.f],nei.f));
        }
      }
    }
    if(dist[k] == (1<<30)-1)cout << "IMPOSSIBLE"<< endl;
    else cout << dist[k] << endl;






  }
}
