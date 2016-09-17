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

bool areNei(string s1, string s2){
  if(s1.length()!=s2.length() || s1==s2)return false;
  int ret = 0;
  for (int i = 0; i < (int)s1.length(); i++)
    if(s1[i]!=s2[i])ret++;
  if(ret==1)return true;
  else return false;
}

//global variables

int main(){
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    if(ji!=0)cout << endl;
    vector<string> dict;
    string str;
    while (cin >> str,str!="*")
      dict.push_back(str);
    vvi adj;
    adj.resize(dict.size());
    for (int i = 0; i < (int)dict.size(); i++)
      for (int j = i+1; j < (int)dict.size(); j++) {
        if(areNei(dict[i], dict[j])){
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }

    string s1, s2,st;
    getline(cin,st);
    while(getline(cin,st),!st.empty()){
      stringstream ss(st);
      ss >> s1 >> s2;
      int s = find(all(dict), s1)-dict.begin();
      int d = find(all(dict), s2)-dict.begin();
      vi sd(dict.size(),(1<<29));
      sd[s]=0;
      queue<int> q;
      q.push(s);
      while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < (int)adj[tmp].size(); i++) {
          int nei = adj[tmp][i];
          if (sd[nei]==(1<<29)) {
            sd[nei] = sd[tmp]+1;
            q.push(nei);
          }
        }
      }
      cout << dict[s] << " " << dict[d] << " " << sd[d] << endl;
    }
  }
}
