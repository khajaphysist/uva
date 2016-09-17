#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
  int n;
  while (scanf("%d",&n),n) {
    priority_queue<int, vector<int>, greater<int> > N;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d",&t);
      N.push(t);
    }
    unsigned long long sum = 0;
    while (!N.empty()) {
      int a,b;
      a = N.top();
      N.pop();
      b = N.top();
      N.pop();
      sum += a+b;
      if(N.empty())break;
      N.push(a+b);
    }
    cout << sum << endl;
  }
  return 0;
}
