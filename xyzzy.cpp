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
class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
      else                   { p[x] = y; setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
//global variables

int main(){
  int n;
  while (cin >> n, n!=-1) {
    vvi adj(n);
    vi ene(n);
    vi vis(n,0);
    for (int i = 0; i < n; i++) {
      cin >> ene[i];
      ene[i] = -ene[i];
      int nnei; cin >> nnei;
      for (int j = 0; j < nnei; j++) {
        int v; cin >> v; v-=1;
        adj[i].push_back(v);
      }
    }
    queue<int> q;
    bool err = true;
    q.push(0);
    while (!q.empty()) {
      int tmp = q.front(); q.pop();
      vis[tmp] = 1;
      for (int i = 0; i < (int)adj[tmp].size(); i++) {
        int nei = adj[tmp][i];
        if (!vis[nei]) {
          if(nei==n-1){ err = false; goto p1;}
          q.push(nei);
        }
      }
    }
  p1:
    if (err){
      cout << "hopeless" << endl;
      continue;
    }

    vi dist(n,(1<<29));

    dist[0] = 0;
    for (int i = 0; i < n-1; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < (int)adj[j].size(); k++) {
          int u = j;
          int v = adj[j][k];
          int w = ene[v];
          if (dist[u]!=(1<<29)&&dist[u]+w < dist[v] && dist[u]+w < 100) {
            dist[v] = dist[u] + w;
          }
        }
      }
    }

    bool ans = false;
    int cys = (1<<29);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int)adj[i].size(); j++) {
        int u = i;
        int v = adj[i][j];
        int w = ene[v];
        if(dist[u]!=(1<<29)&&dist[u]+w < dist[v] && dist[u]+w < 100){
          ans = true;
          cys = u;
          goto p2;
        }
      }
    }
  p2:
    bool err1 = true;
    if(ans){
      vis.clear();
      vis.resize(n, 0);
      queue<int> q1;
      q1.push(cys);
      while (!q1.empty()) {
        int tmp = q1.front(); q1.pop();
        vis[tmp] = 1;
        for (int i = 0; i < (int)adj[tmp].size(); i++) {
          int nei = adj[tmp][i];
          if (!vis[nei]) {
            if(nei==n-1){err1 = false; goto p3;}
            q1.push(nei);
          }
        }
      }
    }
  p3:


    if (dist[n-1] < 100)cout << "winnable" <<endl;
    else if(ans && !err1) cout << "winnable" <<endl;
    else cout << "hopeless" <<endl;


  }
}
