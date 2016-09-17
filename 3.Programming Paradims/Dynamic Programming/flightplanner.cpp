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
int hold = 30, climb = 60, sink = 20;
int winds[12][1010],paths[12][1010];

int findminpath(int h, int x){
  if(h==0 && x == 0) return 0;
  if(h>x || h < 0 || h > 9) return (1<<30)-2;;
  if(paths[h][x]!=16843009) return paths[h][x];
  int ans = (1<<30)-2;
  int l = h-1<0?INT32_MAX:findminpath(h-1,x-1)+climb-winds[h-1][x];
  int m = findminpath(h,x-1)+hold-winds[h][x];
  int u = findminpath(h+1,x-1)+sink-winds[h+1][x];
  ans = paths[h][x] = min(ans,min(min(l,m),u));
  return ans;
}

int run(int dist){
  if (dist == 1)
    return paths[0][1] = hold - winds[0][1];
  run (dist - 1);
  return findminpath(0,dist);
}

int main(){
  int t,dist;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    cin >> dist; dist/=100;
    memset(winds, 1, sizeof(winds));
    memset(paths, 1, sizeof(paths));
    for (int i = 9; i >= 0; --i)
      for (int j = 1; j <= dist; j++)scanf("%d", &winds[i][j]);
    cout << run(dist) << endl;
    cout << endl;
  }
}
