#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  vector<long> N;
  N.reserve(10000);
  long temp;
  while(scanf("%ld", &temp)!=EOF){
    if (N.size()==0) {
      N.push_back(temp);
    }else{
      auto it = lower_bound(N.begin(),N.end(),temp,greater<long>());
      N.insert(it, temp);
    }
    if (N.size()%2) {
      int i = N.size()/2;
      cout << N[i] << endl;
    }else{
      int i = N.size()/2, j = N.size()/2-1;
      cout << (N[i] + N[j])/2 << endl;
    }
  }
  return 0;
}
