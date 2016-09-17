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
vector<vector<ii> > mst;
int ans[105][105];
int vis[105];

int dfs(int s, int d){
  int mx = -(1<<29), nmx = -(1<<29);
  for (int i = 0; i < (int)mst[s].size(); i++) {
    int nei = mst[s][i].first, neiw = mst[s][i].second;
    if(!vis[nei]){
      vis[nei] = 1;
      nmx = max(nmx,neiw);
      if(nei==d)return neiw;
      mx = max(mx,dfs(nei,d));
      if(mx>=0) return max(mx,nmx);
    }
  }
  return -(1<<29);
}

int main(){
  int c,s,q,count = 1;
  while (scanf("%d %d %d", &c,&s,&q),c) {
    if(count!=1)cout << endl;
    vector<pair<int,ii> > elist;
    mst.clear();
    mst.resize(c);
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < s; i++){
      int u,v,w;
      scanf(" %d %d %d", &u,&v,&w);
      elist.push_back(make_pair(w, ii(u-1,v-1)));
    }
    sort(all(elist));
    UnionFind uf(c);
    for (int i = 0; i < s; i++) {
      auto top = elist[i];
      if (!uf.isSameSet(top.second.first, top.second.second)) {
        mst[top.second.first].push_back(ii(top.second.second,top.first));
        mst[top.second.second].push_back(ii(top.second.first,top.first));
        uf.unionSet(top.second.first, top.second.second);
      }
    }
    for (int i = 0; i < c; i++)
      for (int j = i+1; j < c; j++){
        memset(vis, 0, sizeof(vis));
        vis[i] = 1;
        ans[i][j] = ans[j][i] = dfs(i,j);
      }
    printf("Case #%d\n", count);
    count++;
    for (int i = 0; i < q; i++) {
      int u,v;
      scanf("%d %d", &u,&v);
      if(ans[u-1][v-1]>=0) cout << ans[u-1][v-1] << endl;
      else cout << "no path" << endl;
    }
  }
}
