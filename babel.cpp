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
  int m;
  while (cin >> m,m) {
    string o,de; cin >> o >> de;
    unordered_map<string,int> lis;
    vector<vector<pair<ii,char> > > adj(m,vector<pair<ii,char> >());
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      string us,vs,ws; int u,v;
      cin >> us >> vs >> ws;
      if (present(lis,us))u = lis[us];
      else u = lis[us] = cnt++;
      if (present(lis,vs))v = lis[vs];
      else v = lis[vs] = cnt++;
      adj[u].push_back(make_pair(ii(v,(int)ws.length()),ws[0]));
      adj[v].push_back(make_pair(ii(u,(int)ws.length()),ws[0]));
    }
    vi dist(m,(1<<29));
    if(!present(lis,o)){cout << "impossivel" << endl;continue;}
    if(!present(lis,de)){cout << "impossivel" << endl;continue;}
    int s = lis[o], dest = lis[de];
    dist[s] = 0;
    priority_queue<pair<ii,char>,vector<pair<ii,char> >,greater<pair<ii,char> > > q;
    q.push(make_pair(ii(0,s),'-'));
    while (!q.empty()) {
      auto tmp = q.top(); q.pop();
      int d = tmp.f.f; int u = tmp.f.s; char prev = tmp.s;
      if(d>dist[u])continue;
      for (int i = 0; i < (int)adj[u].size(); i++) {
        auto nei = adj[u][i];
        if (dist[u]+nei.f.s<dist[nei.f.f] && prev != nei.s) {
          dist[nei.f.f] = dist[u] + nei.f.s;
          q.push(make_pair(ii(dist[nei.f.f],nei.f.f),nei.s));
        }
      }
    }
    if (dist[dest] == (1<<29))cout << "impossivel" << endl;
    else cout << dist[dest] << endl;
  }
}
