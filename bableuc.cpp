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
  int m;
  while (cin >> m,m) {
    string O,D; cin >> O >> D;
    unordered_map<string,set<string> > lang,word;
    unordered_map<string,int> lis;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      string l1,l2,w; cin >> l1 >> l2 >> w;
      if(present(lang, l1))lang[l1].insert(w);
      else{lang[l1]=set<string>(); lang[l1].insert(w);}
      if(present(lang, l2))lang[l2].insert(w);
      else{lang[l2]=set<string>(); lang[l2].insert(w);}
      if(!present(lis, w))lis[w] = cnt++;
      if(present(word, w)){word[w].insert(l1);word[w].insert(l2);}
      else{
        word[w] = set<string>();
        word[w].insert(l1);
        word[w].insert(l2);
      }
    }
    vector<vector<ii> > adj;
    adj.resize(lis.size()+2,vector<ii>());
    for (auto it = word.begin(); it != word.end(); ++it) {
      for (auto it1 = it->s.begin(); it1 != it->s.end(); ++it1) {
        for (auto it2 = lang[*it1].begin(); it2 != lang[*it1].end(); ++it2) {
          if (it->f[0]!=(*it2)[0]) {
            int u = lis[it->f]; int v = lis[*it2];
            adj[u].push_back(ii(v,(int)it->f.length()));
            adj[v].push_back(ii(u,(int)it2->length()));
          }
        }
      }
    }
    vi dist(m+2,(1<<29));
    if(!present(lang,O)){cout << "impossivel" << endl;continue;}
    if(!present(lang,D)){cout << "impossivel" << endl;continue;}

    for (auto it = lang[O].begin(); it != lang[O].end(); ++it) {
      adj[m].push_back(ii(lis[*it],0));
    }
    for (auto it = lang[D].begin(); it != lang[D].end(); ++it) {
      adj[lis[*it]].push_back(ii(m+1,it->length()));
    }
    int s = m, dest = m+1;
    dist[s] = 0;
    priority_queue<ii,vector<ii>, greater<ii> > q;
    q.push(ii(0,s));
    while (!q.empty()) {
      auto tmp = q.top(); q.pop();
      int d = tmp.f; int u = tmp.s;
      if(d>dist[u])continue;
      for (int i = 0; i < (int)adj[u].size(); i++) {
        auto nei = adj[u][i];
        if (dist[u]+nei.s<dist[nei.f]) {
          dist[nei.f] = dist[u] + nei.s;
          q.push(ii(dist[nei.f],nei.f));
        }
      }
    }
    if (dist[dest] == (1<<29))cout << "impossivel" << endl;
    else cout << dist[dest] << endl;
  }
}
