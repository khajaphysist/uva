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
int nodes[11][2],n;

int tsp(int pos, int mask){
  if (mask == (1<<(n+1))-1)return abs(nodes[pos][0]-nodes[0][0])+abs(nodes[pos][1]-nodes[0][1]);
  int ans =10000000;
  for (int i = 0; i < n+1; i++) {
    if (i==pos || (mask & (1<<i)))continue;
    ans = min(ans,abs(nodes[pos][0]-nodes[i][0])+abs(nodes[pos][1]-nodes[i][1])+tsp(i,mask|(1<<i)));
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    int x,y; cin >> x >> x >> x >> y >> n;
    nodes[0][0] = x; nodes[0][1] = y;
    for (int i = 0; i < n; i++)scanf("%d %d", &nodes[i+1][0],&nodes[i+1][1]);
    printf("The shortest path has length %d\n", tsp(0,1));
  }
}
