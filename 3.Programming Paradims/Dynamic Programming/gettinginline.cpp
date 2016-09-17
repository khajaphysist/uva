#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
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
int comp[9][2],n;
double ldist = 1000000,tdist = 0;
vi temp,bestN;
vector<double> best,t;

int main(){
  int count = 0;
  cout << "**********************************************************" << endl;
  cin >> n;
  while(1){
    count++;
    ldist = 1000000,tdist = 0;
    temp.clear();
    best.clear();
    t.clear();
    for (int i = 0; i < n; i++)
      scanf("%d %d", &comp[i][0],&comp[i][1]);
    for (int i = 0; i < n; i++)temp.push_back(i);

    do{
      for (int j = 0; j < n-1; j++) {
        t.push_back(16+sqrt((comp[temp[j]][0]-comp[temp[j+1]][0])*(comp[temp[j]][0]-comp[temp[j+1]][0])+(comp[temp[j]][1]-comp[temp[j+1]][1])*(comp[temp[j]][1]-comp[temp[j+1]][1])));
        tdist += t.back();
      }
      if (tdist<ldist) {
        bestN = temp;
        best = t;
        ldist = tdist;
      }
      t.clear();
      tdist = 0;
    }while(next_permutation(all(temp)));

    printf("Network #%d\n",count);
    for (int i = 0; i < n-1; i++)
      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",comp[bestN[i]][0],comp[bestN[i]][1],comp[bestN[i+1]][0],comp[bestN[i+1]][1],floor(best[i]*100+0.5)/100);
    printf("Number of feet of cable required is %.2f.\n",floor(ldist*100+0.5)/100);
    cin >> n;
    if(n)
    cout << "**********************************************************" << endl;
    else break;
  }
}
