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
char grid[105][105];
int n;
int ip[] = {1,0,-1,0};
int jp[] = {0,1,0,-1};
int scount,tcount,wcount;

void dfs(int i, int j, int dir){
  if(i>=n || i<0 || j>=n || j<0)return;
  if(grid[i][j]=='.')return;
  if(wcount>n/2+1)return;
  if(tcount==0 && grid[i][j] == 'x'){tcount = 1;scount++;}
  grid[i][j] = '.';
  wcount++;
  dfs(i+1-dir,j+dir,dir);
  dfs(i+dir-1,j-dir,dir);
}

int main(){
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    memset(grid,'.',sizeof(grid));
    scount = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)scanf(" %c",&grid[i][j]);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++){
        if(grid[i][j] != '.'){
          int dir=1;
          tcount = 0;
          wcount = 1;
          for (int k = 0; k < 4; k++) {
            if(j+jp[k]<n&&j+jp[k]>=0&&i+ip[k]<n&&i+ip[k]>=0&&grid[i+ip[k]][j+jp[k]]!='.')dir = abs(jp[k]);
          }
          dfs(i,j,dir);
        }
      }
    printf("Case %d: %d\n",ji+1,scount);

  }
}
