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
  int l,u,r;
  int k[10000];
  int cnt = 0;
  while (cin >> l >> u >> r,l+u+r) {
    cnt++;
    memset(k, -1, sizeof(k));
    int rv[r];
    for (int i = 0; i < r; i++)cin >> rv[i];
    k[l] = 0;
    queue<int>q;
    q.push(l);
    while (!q.empty()) {
      int tmp = q.front();
      q.pop();
      for (int i = 0; i < r; i++) {
        int nei = (tmp + rv[i]) % 10000;
        if (nei == u) {
          printf("Case %d: %d\n", cnt,k[tmp]+1);
          goto end;
        }
        if (k[nei]==-1) {
          k[nei] = k[tmp] + 1;
          q.push(nei);
        }
      }
    }
    printf("Case %d: ", cnt);
    cout << "Permanently Locked" << endl;
  end:
    continue;
  }
}
