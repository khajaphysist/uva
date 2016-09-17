#include <iostream>
#include <unordered_set>
#include <stdio.h>

int main()
{
  int n,m;
  while (scanf("%d %d",&n,&m),n+m) {
    std::unordered_set<int> N,M;
    int count = 0;
    for (int i = 0; i < n; i++) {
      int temp;
      scanf("%d",&temp);
      N.insert(temp);
    }
    for (int i = 0; i < m; i++) {
      int temp;
      scanf("%d",&temp);
      M.insert(temp);
    }
    std::unordered_set<int> &small = N.size() > M.size() ? M : N;
    std::unordered_set<int> &large = N.size() > M.size() ? N : M;

    for (auto it = small.begin(); it != small.end(); ++it) {
      std::unordered_set<int>::iterator f;
      f = large.find(*it);
      if(f == large.end())continue;
      else count++;
    }

    printf("%d\n",count);
  }
  return 0;
}
