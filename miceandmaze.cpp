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
#define vii vector<ii>
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
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    if(ji!=0)cout << endl;
    int n,e,T,m; cin >>n>>e>>T>>m;
    e-=1;
    vector<vii> adj;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
      int u,v,w; cin >> u >> v >> w;
      adj[v-1].push_back(ii(u-1,w));
    }

    vector<int> dist(n,(1<<29));
    dist[e] = 0;
    priority_queue<ii,vii,greater<ii> > q;
    q.push(ii(0,e));
    while (!q.empty()) {
      ii tmp = q.top();
      q.pop();
      int d = tmp.first; int u = tmp.second;
      if(dist[u]<d)continue;
      for (int i = 0; i < (int)adj[u].size(); i++) {
        ii v = adj[u][i];
        if (dist[u]+v.s<dist[v.f]) {
          dist[v.f] = dist[u]+v.s;
          q.push(ii(dist[v.f],v.f));
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if(dist[i]<=T)ans++;
    }
    cout << ans << endl;
  }
}
