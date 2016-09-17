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
#include <initializer_list>

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
  int m,n;
  int rp[4] = {1,0,-1,0};
  int cp[4] = {0,1,0,-1};
  while (scanf("%d %d", &m,&n),m) {
    int store[m][n];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)scanf("%d", &store[i][j]);
    ii s,d,d1; scanf("%d %d %d %d ", &s.f,&s.s,&d.f,&d.s);
    d1 = d;
    d1.f-=1;
    d1.s-=1;
    string str; cin >> str;
    int dir = str=="north" ? 0 : str=="east" ? 1 : str == "south" ? 2 : 3;
    if(s==d){cout << "0" << endl;continue;}
    s.f-=1;
    s.s-=1;
    if(m==1 || n==1){cout << "-1" << endl; continue;}
    int state[m-1][n-1][4];
    for (int i = 0; i < m-1; i++)
      for (int j = 0; j < n-1; j++) {
        if(store[i][j]||store[i+1][j]||store[i][j+1]||store[i+1][j+1])state[i][j][0] = state[i][j][1] = state[i][j][2] = state[i][j][3] = -2;
        else state[i][j][0] = state[i][j][1] = state[i][j][2] = state[i][j][3] = -1;
      }
    if(state[d.f-1][d.s-1][0]==-2){cout << "-1" << endl; continue;}
    pair<ii,int> source(s,dir);
    queue<pair<ii,int> > q;
    q.push(source);
    state[s.f][s.s][dir] = 0;
    while(!q.empty()){
      auto tmp = q.front();
      q.pop();
      if (tmp.f == d1 && state[d.f-1][d.s-1][0] > 0 && state[d.f-1][d.s-1][1] > 0 && state[d.f-1][d.s-1][2] > 0 && state[d.f-1][d.s-1][3] > 0) {
        int ans = (1<<29);
        for (int jj = 0; jj < 4; jj++) {
          if (state[d.f-1][d.s-1][jj] > 0) {
            ans = min(ans,state[d.f-1][d.s-1][jj]);
          }
        }
        if(ans == (1<<29)) cout << "-1" << endl;
        else cout << ans << endl;
        goto end;
      }
      for (int i = 1; i < 4; i++) {
        ii nei;
        nei.f = tmp.f.f - i*(1-tmp.s)*(!(tmp.s%2));
        nei.s = tmp.f.s + i*(2-tmp.s)*(tmp.s%2);
        if(state[nei.f][nei.s][tmp.s]==-2)break;
        if (nei.f>=0 && nei.s>=0 && nei.f<m-1 && nei.s<n-1 && state[nei.f][nei.s][tmp.s] == -1 && state[nei.f][nei.s][tmp.s] != -2) {
          state[nei.f][nei.s][tmp.s] = state[tmp.f.f][tmp.f.s][tmp.s]+1;
          q.push(make_pair(ii(nei.f,nei.s), tmp.s));
        }
      }
      int l = tmp.s-1<0 ? 3 : tmp.s-1;
      int r = tmp.s+1>3 ? 0 : tmp.s+1;
      for(int k : {l,r}){
        if (state[tmp.f.f][tmp.f.s][k] == -1 && state[tmp.f.f][tmp.f.s][k] != -2) {
          state[tmp.f.f][tmp.f.s][k] = state[tmp.f.f][tmp.f.s][tmp.s]+1;
          q.push(make_pair(tmp.f, k));
        }
      }
    }
    cout << "-1" << endl;
    // int ans = (1<<29);
    // for (int i = 0; i < 4; i++) {
    //   if (state[d.f-1][d.s-1][i] > 0) {
    //     ans = min(ans,state[d.f-1][d.s-1][i]);
    //   }
    // }
    // if(ans == (1<<29)) cout << "-1" << endl;
    // else cout << ans << endl;

    // for (int i = 0; i < m-1; i++) {
    //   for (int j =0; j < n-1; j++) {
    //     int ret = (1<<29);
    //     for (int k = 0; k < 4; k++) {
    //       if (state[i][j][k] >= 0) {
    //         ret = min(ret,state[i][j][k]);
    //       }
    //     }
    //     if(ret==(1<<29))cout << "-1  ";
    //     else cout << ret << "  ";
    //   }cout << endl;
    // }
  end:
    continue;
  }
}
