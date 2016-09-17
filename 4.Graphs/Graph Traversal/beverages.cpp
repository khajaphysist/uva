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
int n,m;
map<string,int> lis;
vector<string> ansup;
int vis[105];
vector<set<int> > nxt, pre;
vi ans;

int main(){
  int count = 1;
  while (scanf("%d ", &n)!=EOF) {
    string str,str1;
    lis.clear();
    ansup.clear();
    nxt.clear();
    pre.clear();
    ans.clear();
    for (int i = 0; i < n; i++) {
      getline(cin, str);
      ansup.push_back(str);
      lis.insert(make_pair(str, i));
    }
    memset(vis, 0, (n+2)*sizeof(int));
    nxt.resize(n+2);
    pre.resize(n+2);
    scanf(" %d ", &m);
    for (int i = 0; i < m; i++) {
      cin >> str; cin >> str1;
      nxt[lis[str]].insert(lis[str1]);
      pre[lis[str1]].insert(lis[str]);
    }
    priority_queue<int,vector<int>,greater<int> > q;
    for (int i = 0; i < n; i++) {
      if(!pre[i].size()){q.push(i);vis[i] = 1;}
    }
    while(!q.empty()){
      int tmp = q.top();
      ans.push_back(tmp);
      q.pop();
      for (auto it = nxt[tmp].begin(); it != nxt[tmp].end(); ++it) {
        if(!vis[*it])pre[*it].erase(tmp);
      }
      for (int i = 0; i < n; i++) {
        if((!vis[i])&&!pre[i].size()){q.push(i);vis[i] = 1;}
      }
    }
    printf("Case #%d: Dilbert should drink beverages in this order: ", count);
    count++;
    for (int i = 0; i < n; i++) {
      cout << ansup[ans[i]];
      if(i!=n-1)cout << " ";
    }
    cout << "."<<endl;
    cout << endl;
  }
}
