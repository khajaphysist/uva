#include <climits>
#include <cmath>
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
  int u,v,tcnt=1;
  int d[100][100];
  while (cin >> u >> v,u+v) {
    memset(d, 31, sizeof(d));
    vector<vector<int> > adj(100,vi());
    u-=1;v-=1;
    adj[u].push_back(v);
    d[u][v] = 1;
    while (cin >> u >> v,u){adj[u-1].push_back(v-1);d[u-1][v-1] = 1;}
    for (int k = 0; k < 100; k++)
      for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
          d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    int sum = 0, cnt = 0;
    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++) {
        if (d[i][j]<100000 && i!=j){sum+=d[i][j];cnt++;}
      }
    double ret = (double)(((double)sum)/((double)cnt));
    ret = floor(ret*1000 + 0.5);
    ret/=1000;
    printf("Case %d: average length between pages = %.3lf clicks\n",tcnt++,ret);
  }
}
