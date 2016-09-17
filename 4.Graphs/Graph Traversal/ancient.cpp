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
int H,W;
char img[505][505];
int dc = 2;
int nwc = -2;
int innerComponents[100000];
int wc;
void getinput(int i, int j){
  char c; scanf(" %c",&c);
  int val;
  if(c<='9')val = c-'0';
  else val = 10 + (c - 'a');
  if(val >= 8){img[i][j*4+0] = 1; val-= 8;}
  else img[i][j*4+0] = 0;
  if(val >= 4){img[i][j*4+1] = 1; val-= 4;}
  else img[i][j*4+1] = 0;
  if(val >= 2){img[i][j*4+2] = 1; val-= 2;}
  else img[i][j*4+2] = 0;
  if(val >= 1){img[i][j*4+3] = 1; val-= 1;}
  else img[i][j*4+3] = 0;
}

int ip[8] = {1,1,0,-1,-1,-1,0,1};
int jp[8] = {0,1,1, 1, 0,-1,-1,-1};
int ocount = 0;
void dfs(int i, int j, int col){
  if (col == 0) {
    //cout << "(" << i <<"," << j << "," << col << "," << (int)img[i][j]<< ")" << " ";
    if(i>=H || i<0 || j>=W*4 || j<0)return;
    if(img[i][j]!=0)return;
    img[i][j] = nwc;
    for (int i1 = 0; i1 < 8; i1++) {
      char nei = img[i+ip[i1]][j+jp[i1]];
      if(i+ip[i1]>=H || i+ip[i1]<0 || j+jp[i1]>=W*4 || j+jp[i1]<0)nei=127;
      if (nei>0 && wc!= -1) {
        if(wc==0){wc = nei;innerComponents[wc]++;}
        if(nei!=wc){innerComponents[wc]--; wc=-1;}
      }
      dfs(i+ip[i1],j+jp[i1],col);
    }
  }
  if (col == 1) {
    if(i>=H || i<0 || j>=W*4 || j<0)return;
    if(img[i][j]!=1)return;
    img[i][j] = dc;
    for (int i1 = 0; i1 < 8; i1++){
      if(abs(ip[i1])==abs(jp[i1])){
        if(img[i][j+jp[i1]]==1 || img[i+ip[i1]][j]==1)
          dfs(i+ip[i1],j+jp[i1],col);
        else continue;
      }
      else{dfs(i+ip[i1],j+jp[i1],col);}

    }
  }
}

int main(){
  int count = 1;
  while (cin >> H >> W,H) {
    memset(img,0,sizeof(img));
    dc = 2;
    nwc = -1;
    memset(innerComponents,0,sizeof(innerComponents));

    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)getinput(i,j);

    // for (int i = 0; i < H; i++){
    //   for (int j = 0; j < W*4; j++)cout << (int) img[i][j] <<" ";
    //   cout << endl;
    // }

    for (int i = 0; i < H; i++)
      for (int j = 0; j < W*4; j++){
        char col = img[i][j];
        if(col==0){wc=0;nwc--;}
        if(col==0||col==1)dfs(i,j,img[i][j]);
        if(col==1)dc++;
      }

    // cout << endl;
    // for (int i = 0; i < H; i++){
    //   for (int j = 0; j < W*4; j++)cout << (int) img[i][j] <<" ";
    //   cout << endl;
    // }


    char dic[7] = "WAKJSD";
    multiset<char> ans;
    for (int i = 2; i < dc; i++) {
      ans.insert(dic[innerComponents[i]]);
    }

    cout << "Case " << count <<": ";
    count++;
    pv(ans,'x');
  }
}
