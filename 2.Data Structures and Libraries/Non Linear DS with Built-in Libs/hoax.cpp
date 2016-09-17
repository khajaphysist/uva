#include <iostream>
#include <set>
using namespace std;

int main()
{
  int n;
  while (cin>> n,n) {
    multiset<int> bills;
    unsigned long long int budget=0;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
	int temp;
	cin >> temp;
	bills.insert(temp);
      }
      multiset<int>:: iterator it;
      it = bills.end();
      it--;

      budget += *it - *(bills.begin());
      bills.erase(it);
      bills.erase(bills.begin());
    }
    cout << budget << endl;
  }
  return 0;
}
