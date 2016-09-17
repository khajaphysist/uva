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
vector<char> symbols;
vector<vector<char> > adj;
vector<bool> vis;

bool valid(char c){
  for (int i = 0; i < adj[c].size(); i++)if(vis[adj[c][i]])return false;
  return true;
}

bool dfs(string path){
  if(path.length()==symbols.size()){pv(path,' ');return true;}
  bool ret = false;
  for (int i = 0; i < symbols.size(); i++) {
    if(!vis[symbols[i]]){
      if(valid(symbols[i])){
        vis[symbols[i]] = true;
        ret = dfs(path+symbols[i]) | ret;
        vis[symbols[i]] = false;
      }
    }
  }
  return ret;
}

int main(){
  int t;
  scanf("%d\n\n", &t);
  string st;
  for (int ji = 0; ji < t; ++ji) {
    if(ji)cout << endl;
    stringstream ss;
    getline(cin, st);
    ss.str(st);
    char a,b,c;
    symbols.clear();
    while(ss>>c)symbols.push_back(c);
    sort(all(symbols));
    getline(cin, st);
    ss.clear();
    ss.str(st);
    adj.clear();
    adj.resize(256);
    vis.clear();
    vis.resize(256, false);
    while(ss>>a>>b>>c)adj[a].push_back(c);
    if(!dfs(""))printf("NO\n");
    if(!getline(cin, st))break;
  }
}
