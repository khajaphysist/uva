#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> adl;

int main()
{
  int n,m;
  while (scanf("%d %d",&n,&m) != EOF) {
    adl N;
    N.resize(1000001);
    for (int i = 1; i <= n; i++) {
      int temp;
      cin >> temp;
      N[temp].push_back(i);
    }

    for (int i = 0; i < m; i++) {
      int v;
      unsigned long k;
      cin >> k >> v;
      if(N[v].size() == 0)cout << "0" << endl;
      else if(N[v].size() < k)cout << "0" << endl;
      else cout << N[v][k-1] << endl;
    }
    
    
  }
  return 0;
}
