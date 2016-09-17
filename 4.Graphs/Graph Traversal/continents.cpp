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
int m,n;
char l=0,w=0;
char grid[55][55];
int ix[] = {1,0,-1,0};
int iy[] = {0,1,0,-1};

int dfs(int x, int y){
  if(x<0||x>=m) return 0;
  if(y<0)y=n-1;
  if(y==n)y=0;
  if(grid[x][y]!=l)return 0;
  grid[x][y] = w;
  int ans = 1;
  for (int i = 0; i < 4; i++)
    ans += dfs(x+ix[i],y+iy[i]);
  return ans;
}

int main(){
  while (scanf("%d %d", &m,&n)!=EOF) {
    int x,y;
    l = 0; w = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++){
        char c; scanf(" %c",&c);
        if(l==0)l=c;
        if(c!=l)w=c;
        grid[i][j] = c;
      }
    cin >> x >> y;
    if(grid[x][y]!=l)swap(l,w);
    dfs(x,y);

    int ans = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++){
        if(grid[i][j]==l)ans = max(ans,dfs(i,j));
      }
    cout << ans << endl;

  }
}
