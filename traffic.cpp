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
  int n;
  int count = 1;
  while (scanf("%d", &n)!=EOF) {
    int bsy[n];
    for (int i = 0; i < n; i++)cin >> bsy[i];
    int r; cin >> r;
    vector<vector<ii> >adj(n);
    for (int i = 0; i < r; i++) {
      int u,v; cin >> u >> v;
      u-=1;v-=1;
      adj[u].push_back(ii(v,bsy[v]-bsy[u]));
    }
    vi dist(n,(1<<29));
    dist[0] = 0;
    for (int i = 0; i < n-1; i++) {
      bool mod = true;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < (int)adj[j].size(); k++) {
          ii nei = adj[j][k];
          if (dist[j]!=(1<<29)&&dist[j]+nei.s<dist[nei.f]) {
            dist[nei.f] = dist[j] + nei.s;
            mod = false;
          }
        }
      }
      if(mod)break;
    }
    printf("Set #%d\n", count++);
    if(n==0) continue;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
      int d; cin >> d; d-=1;
      if (dist[d] < 3 || dist[d] == (1<<29)) {
        cout << "?" << endl;
      }
      else cout << dist[d] << endl;
    }

  }
}
