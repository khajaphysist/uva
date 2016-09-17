#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define vi vector<int>
#define ii pair<int,int>
#define vvi vector<vi>
#define um(a,b) unordered_map<a,b>
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


template<class T>
inline void ia(T a[],int n){
  for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
}

//global variables
unsigned int table[30001];

int main(){
  int t;
  cin >> t;
  for (int ji = 0; ji < t; ++ji) {
    int p,n; cin >> p; cin >> n;
    memset(table, -1, sizeof(table));
    table[0] = 0;
    for (int i = 0; i < n; i++) {
      int c; cin >> c;
      for (int v = 30001 - c - 1; v >= 0; v--)
        if(table[v] < 4294967295) table[v+c] = table[v+c] < table[v]+1 ? table[v+c]:table[v]+1;
    }

    for (int i = p; i < 30001; i++) {
      if(table[i]<4294967295){
        cout << i << " " << table[i] << endl;
        break;
      }
    }


  }
}
