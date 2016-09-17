#include <iostream>
#include <set>
#include <stdio.h>

int main()
{
  int n;
  while (scanf("%d",&n),n) {
    std::multiset<int> bills;
    unsigned long long int budget=0;
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d",&k);
      for (int j = 0; j < k; j++) {
	int temp;
	scanf("%d",&temp);
	bills.insert(temp);
      }
      std::multiset<int>:: iterator it;
      it = bills.end();
      it--;

      budget += *it - *(bills.begin());
      bills.erase(it);
      bills.erase(bills.begin());
    }
    std::cout << budget << std::endl;
  }
  return 0;
}
