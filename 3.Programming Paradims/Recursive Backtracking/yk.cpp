#include <iostream>
#include <deque>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
  int s,d;
  while (scanf("%d %d", &s, &d)!=EOF) {
    deque<int> w;
    int l=0,m=0;
    int min=-INT32_MAX;
    if ( s>=4*d || d>=5*s ){
      cout << "Deficit" << endl;
      continue;
    }

    if(4*s-d<0){
      min = 4*s-d;
      l = 4;
      m = 1;
    }
    if(3*s-2*d<0){
      if(3*s-2*d > min){
	min = 3*s-2*d;
	l = 3; m = 2;
      }
    }
    if (2*s-3*d<0) {
      if (2*s-3*d > min) {
	min = 2*s-3*d;
	l = 2; m = 3;
      }
    }
    if (s-4*d<0) {
      if (s-4*d > min) {
	min = s-4*d;
	l = 1; m = 4;
      }
    }
    int sum = 0, wsum = 0;
    for (int j = 0; j < l; j++){
      w.push_back(s);
      wsum += s;
    }
    for (int j = 0; j < m; j++){
      w.push_back(-d);
      wsum -= d;
    }
    sum = wsum;
    for (int i = 0; i < 7; i++) {
      wsum -= w.front();
      w.pop_front();
      if (wsum+s<0) {
	wsum += s;
	sum += s;
	w.push_back(s);
      }
      else {
	wsum -= d;
	sum -= d;
	w.push_back(-d);
      }
    }
    if(sum>0)cout << sum << endl;
    else cout << "Deficit" << endl;
  }
  return 0;
}

