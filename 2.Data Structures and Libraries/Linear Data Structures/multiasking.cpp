#include <iostream>
#include <bitset>
#include <stdio.h>
#include <string>
using namespace std;

void run(int m, int n){
  bitset<1000001> b;
  b.reset();
  string str;
  bool flag = true;
  
  for (int i = 0; i < m; i++) {
    int s,e;
    cin >> s >> e;
    for (int j = s + 1; j <= e && flag; j++) {
      if (j == e && b[j]) {
	str = "CONFLICT";
	flag = false;
      }else if (j==e) {
	b[j] = true;
      }
      else if(b[j]){
	str = "CONFLICT";
	flag = false;
      }else b[j] = true;
    }
  }


  for (int i = 0; i < n; i++) {
    int s,e,t;
    cin >> s >> e >> t;
    for (int l = s; l <= 1000000 && flag; l+=t) {
      for (int j = l+1; (j <= l+e-s) && flag && (j <= 1000000); j++) {
        if (j == l+e-s && b[l+e-s]) {
	  str = "CONFLICT";
	  flag = false;
	}else if(j == l+e-s)b[l+e-s] = true;
        else if(b[j]){
	  str = "CONFLICT";
	  flag = false;
        }else b[j] = true;
      }
    }
  }
  if (flag) {
    cout << "NO CONFLICT" << endl;
  }else cout << str << endl;
}

int main()
{
  int m,n;
  while (scanf("%d %d",&m,&n),m+n) {
    run(m,n);
  }
  return 0;
}
