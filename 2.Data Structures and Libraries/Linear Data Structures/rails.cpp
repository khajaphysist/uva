#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void run(int n){
 mark:
  int c;
  vector<int> a,b,s;
  while (scanf("%d",&c),c) {
      b.push_back(c);
      for (int i = 0; i < n-1; i++) {
        scanf("%d",&c);
	b.push_back(c);
      }
      if(c==0)goto mark;

      for (int i = n; i > 0; i--) {

	while (1) {
	  if(b.empty() && s.back() != i){ cout << "No" << endl; goto mark;}
	  if(!s.empty() && s.back() == i){ a.push_back(s.back()); s.pop_back(); break;}
	  s.push_back(b.back());
	  b.pop_back();

	}
	
      }

      cout << "Yes" << endl;
      
  }

}

int main() {
  int n;
  while (scanf("%d",&n), n) {
    run(n);
    cout << endl;
  }
  return 0;
}
