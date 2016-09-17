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
  int te;
  cin >> te;
  for (int ji = 0; ji < te; ++ji) {
    int N,M,s,t,p; cin >> N >> M >> s >> t >> p;
    s-=1; t-=1;
    vector<vector<ii> > adjf(N), adjb(N);
    vector<pair<ii,int> > elist;
    for (int i = 0; i < M; i++) {
      int u,v,c; cin >> u >> v >> c;
      u-=1;v-=1;
      adjf[u].push_back(ii(v,c));
      adjb[v].push_back(ii(u,c));
      elist.push_back(make_pair(ii(u,v),c));
    }
    vi df(N,(1<<29)), db(N,(1<<29));
    df[s] = 0; db[t] = 0;
    priority_queue<ii,vector<ii>,greater<ii> > q;
    q.push(ii(0,s));
    while (!q.empty()) {
      ii tmp = q.top(); q.pop();
      int d = tmp.f; int u = tmp.s;
      if (d>df[u])continue;
      for (int i = 0; i < (int)adjf[u].size(); i++) {
        ii nei = adjf[u][i];
        if (df[u]+nei.s < df[nei.f]) {
          df[nei.f] = df[u] + nei.s;
          q.push(ii(df[nei.f],nei.f));
        }
      }
    }
    if (df[t] == (1<<29)) {
      cout << "-1" << endl;
      continue;
    }
    q.push(ii(0,t));
    while (!q.empty()) {
      ii tmp = q.top(); q.pop();
      int d = tmp.f; int u = tmp.s;
      if (d>db[u])continue;
      for (int i = 0; i < (int)adjb[u].size(); i++) {
        ii nei = adjb[u][i];
        if (db[u]+nei.s < db[nei.f]) {
          db[nei.f] = db[u] + nei.s;
          q.push(ii(db[nei.f],nei.f));
        }
      }
    }

    int ans = -1;
    for (int i=0; i < (int)elist.size(); i++) {
      int u = elist[i].f.f, v = elist[i].f.s, w = elist[i].s;
      if ((df[u]!=(1<<29)&&db[v]!=(1<<29))&&df[u]+w+db[v] <= p) {
        ans = max(ans,w);
      }
    }
    cout << ans << endl;


  }
}
