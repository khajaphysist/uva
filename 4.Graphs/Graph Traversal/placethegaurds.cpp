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
  vector<vi> adj;
  unsigned int col[205];
  for (int ji = 0; ji < t; ++ji) {
    int v,e; cin >> v >> e;
    int mxn = 0;
    adj.clear();
    adj.resize(v+2);
    memset(col, -1, sizeof(col));
    for (int i = 0; i < e; i++) {
      int u,v1; scanf("%d %d", &u,&v1);
      adj[u].push_back(v1);
      adj[v1].push_back(u);
    }
    bool ispos = true;
    queue<int> q;
    for (int j = 0; j < v && ispos; j++) {
      if(col[j] <= 1)continue;
      col[j] = 0;
      q.push(j);
      int zn = 1, tn = 1;
      ispos = true;
      while (ispos && !q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i= 0; i < (int)adj[tmp].size(); i++) {
          int nei = adj[tmp][i];
          if (col[nei]>1) {
            col[nei] = 1-col[tmp];
            q.push(nei);
            tn++;
            if(!(col[nei]))zn++;
          }else if(col[nei] == col[tmp]){ispos = false;break;}
        }
      }
      if(zn==tn)mxn+=zn;
      else mxn += min(zn,tn-zn);
    }
    if(ispos)cout << mxn << endl;
    else cout << -1 << endl;
  }
}
