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
int vis[50005];
int cc[50005];
int nxt[50005];
int n;

int run(int i){
  if(vis[i])return 0;
  vis[i] = 1;
  cc[i] = 1+run(nxt[i]);
  vis[i] = 0;
  return cc[i];
}

int main(){
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    memset(vis, 0, sizeof(vis));
    memset(cc,-1,sizeof(cc));
    cin >> n;
    for (int i = 0; i < n; i++) {
      int u,v;scanf("%d %d",&u,&v);
      nxt[u] = v;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if(cc[i]==-1)
      ans = max(ans,run(i));
    }
    int ret;
    for (int i = n; i >= 0; --i)
      if(cc[i] == ans){ret = i;}
    cout << "Case " << ji+1 << ": ";
    cout << ret << endl;
  }
}
