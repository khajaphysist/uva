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
int grid[110][110],r,c,m,n,w;

int getk(int x, int y){
  int count = 0;
  set<ii> temp;
  if(y+m<c && x+n<r && grid[y+m][x+n]!=-1)temp.insert(make_pair(y+m,x+n));
  if(y+m<c && x-n>=0 && grid[y+m][x-n]!=-1)temp.insert(make_pair(y+m,x-n));
  if(y-m>=0 && x+n<r && grid[y-m][x+n]!=-1)temp.insert(make_pair(y-m,x+n));
  if(y-m>=0 && x-n>=0 && grid[y-m][x-n]!=-1)temp.insert(make_pair(y-m,x-n));
  if(y+n<c && x+m<r && grid[y+n][x+m]!=-1 && m!=n)temp.insert(make_pair(y+n,x+m));
  if(y-n>=0 && x+m<r && grid[y-n][x+m]!=-1 && m!=n)temp.insert(make_pair(y-n,x+m));
  if(y+n<c && x-m>=0 && grid[y+n][x-m]!=-1 && m!=n)temp.insert(make_pair(y+n,x-m));
  if(y-n>=0 && x-m>=0 && grid[y-n][x-m]!=-1 && m!=n)temp.insert(make_pair(y-n,x-m));
  return temp.size();
}

int main(){
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    memset(grid,0,sizeof(grid));
    int ecount = 0, ocount = 0;
    cin >> r >> c >> m >> n >> w;
    for (int i = 0; i < w; i++) {
      int x,y; cin >> x >> y;
      grid[y][x] = -1;
    }
    queue<ii> path;
    path.push(make_pair(0,0));
    while(!path.empty()){
      ii u = path.front();
      path.pop();
      if(grid[u.second][u.first]>0)continue;
      int ns = getk(u.first,u.second);
      if(ns%2){grid[u.second][u.first] = 1;ocount++;}
      else {grid[u.second][u.first] = 2;ecount++;}
        if(u.second+m<c && u.first+n<r && grid[u.second+m][u.first+n]!=-1)if(grid[u.second+m][u.first+n]<=0)path.push(make_pair(u.first+n,u.second+m));
        if(u.second+m<c && u.first-n>=0 && grid[u.second+m][u.first-n]!=-1)if(grid[u.second+m][u.first-n]<=0)path.push(make_pair(u.first-n,u.second+m));
        if(u.second-m>=0 && u.first+n<r && grid[u.second-m][u.first+n]!=-1)if(grid[u.second-m][u.first+n]<=0)path.push(make_pair(u.first+n,u.second-m));
        if(u.second-m>=0 && u.first-n>=0 && grid[u.second-m][u.first-n]!=-1)if(grid[u.second-m][u.first-n]<=0)path.push(make_pair(u.first-n,u.second-m));
        if(u.second+n<c && u.first+m<r && grid[u.second+n][u.first+m]!=-1)if(grid[u.second+n][u.first+m]<=0)path.push(make_pair(u.first+m,u.second+n));
        if(u.second-n>=0 && u.first+m<r && grid[u.second-n][u.first+m]!=-1)if(grid[u.second-n][u.first+m]<=0)path.push(make_pair(u.first+m,u.second-n));
        if(u.second+n<c && u.first-m>=0 && grid[u.second+n][u.first-m]!=-1)if(grid[u.second+n][u.first-m]<=0)path.push(make_pair(u.first-m,u.second+n));
        if(u.second-n>=0 && u.first-m>=0 && grid[u.second-n][u.first-m]!=-1)if(grid[u.second-n][u.first-m]<=0)path.push(make_pair(u.first-m,u.second-n));
    }
    printf("Case %d: %d %d\n", ji+1,ecount,ocount);
  }
}
