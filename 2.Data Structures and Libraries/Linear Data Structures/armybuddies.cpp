#include <stdio.h>
#include <iostream>
using namespace std;

struct buddy{
  int left;
  int right;
};

void run(int s, int b){
  buddy army[s+1];
    for (int i = 1; i <= s; i++) {
      army[i].left = i - 1;
      army[i].right = i + 1;
    }
    army[1].left = 0;
    army[s].right = 0;

    for (int i = 0; i < b; i++) {
      int l,r;
      scanf("%d %d",&l,&r);
      if (army[l].left == 0 && army[r].right == 0) {
	cout << "* *" << endl;
	continue;
      }
      if (army[l].left == 0 && army[r].right != 0) {
	army[army[r].right].left = 0;
	cout << "* " << army[r].right << endl;
	continue;
      }
      if (army[l].left != 0 && army[r].right == 0) {
	army[army[l].left].right = 0;
	cout << army[l].left << " *" << endl;
	continue;
      }
      if (army[l].left != 0 && army[r].right != 0) {
	army[army[l].left].right = army[r].right;
	army[army[r].right].left = army[l].left;
	cout << army[l].left << " " << army[r].right << endl;
	continue;
      }
    }
}

int main()
{
  int s,b;
  while (scanf("%d %d",&s,&b),s) {
    run(s,b);
    cout << "-" << endl;
  }
  return 0;
}
