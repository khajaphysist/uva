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
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    int n,m; cin >> n >> m;
    vector<vector<ii> > adj(n);
    for (int i = 0; i < m; i++) {
      int u,v,w; scanf("%d %d %d", &u,&v,&w);
      adj[u].push_back(ii(v,w));
    }
    vi dist(n,(1<<29));
    dist[0] = 0;
    for (int i = 0; i < n-1; i++) {
      bool mod = true;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < (int)adj[j].size(); k++) {
          ii nei = adj[j][k];
          if (dist[j]+nei.s<dist[nei.f]) {
            dist[nei.f] = dist[j] + nei.s;
            mod = false;
          }
        }
      }
      if(mod)break;
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int)adj[i].size(); j++) {
        ii nei = adj[i][j];
        if (dist[i]+nei.s<dist[nei.f]) {
          ans = true;
          goto end;
        }
      }
    }
  end:
    if (ans) {
      cout << "possible" <<endl;
    }else cout << "not possible" <<endl;
  }
}
