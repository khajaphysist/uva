#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;


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
inline void ia(T a[],int n){
  for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
}

//global variables
int a[10000000],lis[10000000],p[10000000],n = 0;

int main(){
  int maxlis = 0;
  while (scanf("%d", &a[n])==1) {
    lis[n] = 1; p[n] = -1;
    for (int j = n-1; j >= 0; --j) {
      if (a[j]<a[n] && lis[n] < lis[j] + 1) {
        lis[n] = lis[j] + 1;
        p[n] = j;
      }
    }
    maxlis = max(maxlis,lis[n]);
    n++;
  }

  for (int i = n-1; i >= 0; --i) {
    if(lis[i]==maxlis){
      int ans[maxlis];
      cout << maxlis << endl << "-" << endl;
      for (int j = 0; j < maxlis; ++j) {
        ans[maxlis-1-j] = a[i];
        i = p[i];
      }
      pa(ans,maxlis,'\n');
      break;
    }
  }

}
