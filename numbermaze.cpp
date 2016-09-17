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
  int rp[4] = {-1,0,1,0};
  int cp[4] = {0,1,0,-1};
  int grid[1001][1001];
  unsigned int dist[1001][1001];
  for (int ji = 0; ji < t; ++ji) {
    int n,m; cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> grid[i][j];
    priority_queue<pair<int,ii>,vector<pair<int,ii> >,greater<pair<int,ii> > > q;
    q.push(make_pair(grid[0][0],ii(0,0)));
    dist[0][0] = grid[0][0];
    while (!q.empty()) {
      auto tmp = q.top();
      int d = tmp.f;
      ii u = tmp.s;
      if(d>(int)dist[u.f][u.s])continue;
      if(u.f==n-1&&u.s==m-1){cout << d << endl; break;}
      q.pop();
      for (int i = 0; i < 4; i++) {
        ii nei = tmp.s; nei.f+=rp[i]; nei.s+=cp[i];
        if (nei.f>=0 && nei.s>=0 && nei.f<n && nei.s<m) {
          if (dist[u.f][u.s]+grid[nei.f][nei.s]<dist[nei.f][nei.s]) {
            dist[nei.f][nei.s] = dist[u.f][u.s]+grid[nei.f][nei.s];
            q.push(make_pair(dist[nei.f][nei.s],nei));
          }
        }
      }
    }
  }
}
