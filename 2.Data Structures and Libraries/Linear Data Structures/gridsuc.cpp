#include<iostream>
#include<string>
using namespace std;

int sum(int g[][3]){
  int tot = 0;
  for (int i = 0; i < 9; i++) {
    tot += g[i/3][i%3];
  }
  return tot;
}

void transform(int g[][3], int h[][3]){
  for (int i = 0; i < 9; i++) {
    h[i/3][i%3] = (((i/3 + 1 <= 2) ? g[i/3+1][i%3] : 0)+
                  ((i/3 - 1 >= 0) ? g[i/3-1][i%3] : 0)+
                  ((i%3 + 1 <= 2) ? g[i/3][i%3+1] : 0)+
                  ((i%3 - 1 >= 0) ? g[i/3][i%3-1] : 0)) % 2;
  }
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int g[3][3];
    for (int j = 0; j < 9; j++) {
      char c;
      cin >> c;
      g[j/3][j%3] = c-'0';
    }
    int count = 0;
    int h[3][3];
    while (sum(g)) {
      transform(g,h);
      for (int j = 0; j < 9; j++) {
        g[j/3][j%3] = h[j/3][j%3];
      }
      count++;
    }

    cout << count - 1 << endl;
  }
  return 0;
}
