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
  int n,m,s;
  while (cin >> n >> m >> s,n) {
    vector<string> str;
    int count = 0;
    str.resize(n, "");
    int x,y;
    char pos;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        char c; scanf(" %c ",&c);
        str[i].push_back(c);
        if(c=='N'||c=='S'||c=='L'||c=='O'){
          pos = c;
          x = i; y = j;
        }
      }

    string com; cin >> com;
    for(char c:com){
      switch(c){
      case 'D':
        if(pos=='N'){pos = 'L';continue;}
        if(pos=='L'){pos = 'S';continue;}
        if(pos=='S'){pos = 'O';continue;}
        if(pos=='O'){pos = 'N';continue;}
      case 'E':
        if(pos=='N'){pos = 'O';continue;}
        if(pos=='O'){pos = 'S';continue;}
        if(pos=='S'){pos = 'L';continue;}
        if(pos=='L'){pos = 'N';continue;}
      case 'F':
        {
          if(pos=='L'){
            if(y!=m-1&&str[x][y+1]!='#'){
              y++;
              if(str[x][y]=='*'){count++;str[x][y]='.';}
            }
            continue;
          }
          if(pos=='O'){
            if(y&&str[x][y-1]!='#'){
              y--;
              if(str[x][y]=='*'){count++;str[x][y]='.';}
            }
            continue;
          }
          if(pos=='N'){
            if(x&&str[x-1][y]!='#'){
              x--;
              if(str[x][y]=='*'){count++;str[x][y]='.';}
            }
            continue;
          }
          if(pos=='S'){
            if(x!=n-1&&str[x+1][y]!='#'){
              x++;
              if(str[x][y]=='*'){count++;str[x][y]='.';}
            }
            continue;
          }
        }
        continue;
      }
    }
    cout << count << endl;

  }
}
