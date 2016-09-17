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
  int n1;
  int grid[2002][2002];
  int rp[4] = {1,0,-1,0};
  int cp[4] = {0,1,0,-1};
  while (cin >> n1,n1) {
    memset(grid, -1, sizeof(grid));
    for (int i = 0; i < n1; i++) {
      int a,s; cin >> a >> s;
      grid[s][a] = -2;
    }
    int n2; cin >> n2;
    queue<ii> q;
    for (int i = 0; i < n2; i++) {
      int a,s; cin >> a >> s;
      q.push(ii(s,a));
      grid[s][a] = 0;
    }
    while (!q.empty()) {
      ii tmp = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        ii nei; nei.f = tmp.f + rp[i]; nei.s = tmp.s + cp[i];
        if (nei.f>=0 && nei.f <=2000 && nei.s>=0 && nei.s <=2000) {
          if (grid[nei.f][nei.s]==-2) {
            cout << grid[tmp.f][tmp.s] + 1 << endl;
            goto end;
          }
          if (grid[nei.f][nei.s]==-1){
            grid[nei.f][nei.s] = grid[tmp.f][tmp.s]+1;
            q.push(nei);
          }
        }
      }
    }
  end:
    continue;
  }
}
