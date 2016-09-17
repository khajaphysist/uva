#include<stdio.h>
#include<iostream>
using namespace std;

void run(){
  long long int s,p;
  while (scanf("%lld %lld",&s,&p),s) {
    long long int flag = 1;
    long long int x = s/2 + 1, y = s/2 + 1;
    long long int r = 1;
    if (p == 1) {
      cout << "Line = " << y << ", " << "column = " << x << "." << endl;
      continue;
    }
    for (int i = 1; i < s; i++) {
      if (flag) {
	y += i;
	r += i;
	if (r >= p) {
	  cout << "Line = " << y - (r-p) << ", " << "column = " << x << "." << endl;
	  break;
	}
	x -= i;
	r += i;
	if (r >= p) {
	  cout << "Line = " << y << ", " << "column = " << x + (r-p) << "." << endl;
	  break;
	}
	flag = 0;
      }
      else{
	y -= i;
	r += i;
	if (r >= p) {
	  cout << "Line = " << y + (r-p) << ", " << "column = " << x << "." << endl;
	  break;
	}
	x += i;
	r += i;
	if (r >= p) {
	  cout << "Line = " << y << ", " << "column = " << x - (r-p) << "." << endl;
	  break;
	}
	flag = 1;
      }

      if (i == s-1) {
	if (flag) {
	  y += s-1;
	  r += s-1;
	  if (r >= p) {
	    cout << "Line = " << y - (r-p) << ", " << "column = " << x << "." << endl;
	    continue;
	  }
	}
        else{
	  y -= s-1;
	  r += s-1;
	  if (r >= p) {
	    cout << "Line = " << y + (r-p) << ", " << "column = " << x << "." << endl;
	    continue;
	  }
        }
      }
    }

  }
}

int main()
{
  run();
  return 0;
}
