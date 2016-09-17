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

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
      else                   { p[x] = y; setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
//global variables
int n,r;
int xy[1005][2];
vector<pair<double, ii> > elist;
int main(){
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    cin >> n >> r;
    memset(xy, 0, sizeof(xy));
    elist.clear();
    for (int i = 0; i < n; i++)scanf("%d %d", &xy[i][0],&xy[i][1]);
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++){
        double dist = sqrt((double)((xy[i][0]-xy[j][0])*(xy[i][0]-xy[j][0]) + (xy[i][1]-xy[j][1])*(xy[i][1]-xy[j][1])));
        elist.push_back(make_pair(dist, ii(i, j)));
      }
    sort(all(elist));

    int ns=1;
    double raildist = 0,roaddist = 0;
    UnionFind uf(n);
    for (unsigned int i = 0; i < elist.size(); i++) {
      auto top = elist[i];
      if (!uf.isSameSet(top.second.first, top.second.second)) {
        if(top.first > (double) r){ns++;raildist+=top.first;}
        else roaddist += top.first;
        uf.unionSet(top.second.first, top.second.second);
      }
    }

    printf("Case #%d: %d %d %d\n", ji+1,ns,(int)floor(roaddist+0.5),(int)floor(raildist+0.5));

  }
}
