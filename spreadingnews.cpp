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
  int e; cin >> e;
  vvi adj;
  adj.resize(e);
  for (int i = 0; i < e; i++) {
    int n; cin >> n;
    for (int j = 0; j < n; j++) {
      int v; cin >> v;
      adj[i].push_back(v);
    }
  }
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    int s; cin >> s;
    int mx = 0;
    vvi days(3000,vi());
    vi dist(e,(1<<29));
    dist[s] = 0;
    queue<int>q;
    q.push(s);
    while (!q.empty()) {
      int tmp = q.front();
      q.pop();
      for (int j = 0; j < (int)adj[tmp].size(); j++) {
        int nei = adj[tmp][j];
        if(dist[nei]==(1<<29)){
          dist[nei] = dist[tmp]+1;
          days[dist[nei]].push_back(nei);
          mx = max(mx,(int)days[dist[nei]].size());
          q.push(nei);
        }
      }
    }
    if(mx == 0)cout << "0" << endl;
    else{
      for (int j = 0; j < 3000; j++) {
        if((int)days[j].size()==mx){
          cout << mx << " " << j << endl;
          break;
        }
      }

    }
  }
}
