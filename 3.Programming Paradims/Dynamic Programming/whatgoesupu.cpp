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
int a[1000000],lis[1000000],p[1000000],n = 0,L[1000000],lisn = 0;

int main(){
  while (scanf("%d", &a[n])==1)n++;
  //n is count
  int d;
  for (int i = 0; i < n; ++i) {
    d = a[i];
    if(lisn){

      if (a[L[lisn-1]] < d) {
        L[lisn] = i;
        p[i] = L[lisn-1];
        lis[i] = 1 + lis[L[lisn-1]];
        lisn++;continue;
      }
      if (d < a[L[0]]) {
        L[0] = i;
        p[i] = -1;
        lis[i] = 1;
        continue;
      }

      int lo = 0, hi = lisn-1;
      while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(a[L[mid]]>=d) hi = mid;
        else lo = mid+1;
      }

      if (a[L[lo]]!=d) {
        L[lo] = i;
        p[i] = L[lo-1];
        lis[i] = 1 + lis[L[lo-1]];
      }
    }
    else {
      L[0] = i;
      p[i] = -1;
      lis[i] = 1;
      lisn++;
    }
  }

  int ans[lisn];
  cout << lisn << endl << "-" << endl;
  for (int i = n-1; i >= 0; --i) {
    if (lis[i] == lisn) {
      int count = 0;
      do{
        ans[lisn-1-count] = a[i];count++;
        i = p[i];
      }while(i!=-1);
      break;
    }
  }
  pa(ans,lisn,'\n');



}
