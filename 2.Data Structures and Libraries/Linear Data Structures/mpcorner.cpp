#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  uint16_t N;
  while(cin >> N){

    //scanning no's
    uint16_t a[1<<N], w[1<<N];
    for (uint16_t i = 0; i < (1<<N); i++ ) {
      cin >> a[i];
    }

    //calculating weights
    for(uint16_t i = 0; i < (1<<N); i++){
      uint16_t sum = 0;
      for (uint16_t j = 0; j < N; j++) {
	sum += a[i ^ (1<<j)];
      }
      w[i] = sum;
    }

    uint16_t max = 0;
    for(uint16_t i = 0; i < (1<<N); i++){
      for (uint16_t j = 0; j < N; j++) {
	max >= w[i]+w[i ^ (1<<j)] ? : max = w[i]+w[i ^ (1<<j)];
      }
    }
    cout << max << endl;
  }
  return 0;
}
