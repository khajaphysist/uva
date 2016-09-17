#include <vector>
#include <iostream>
#include <bitset>
#include <stdio.h>
using namespace std;

void run(int k,vector<int> temp,vector<vector<int> > &sol,vector<bitset<8> >b){
  for (int i = k; i < 8; i++) {
    if (!b[k].any()) {
      return;
    }
  }
  auto cb = b;
  auto ct = temp;
  for (int i = 0; i < 8; i++) {
    b = cb;
    temp = ct;
    if (b[k][i]) {
      temp.push_back(i+1);
      if(k==7){sol.push_back(temp);return;}
      
      for (int j = k+1; j < 8; j++) {
	b[j][i] = false;
	if(i+j-k<8)b[j][i+j-k]=false;
	if(i-j+k>=0)b[j][i-j+k] = false;
      }
      run(k+1,temp,sol,b);
    }
  }
}

int main()
{
  int q[8];
  int ccount = 1;
  vector<bitset<8> > b(8,0);

  for (int i = 0; i < 8; i++)b[i].set();

  vector<vector<int> > sol;
  vector<int> temp;

  for (int i = 0; i < 1; i++) {
    run(i,temp,sol,b);
  }
  
  while (scanf("%d %d %d %d %d %d %d %d", &q[0],&q[1],&q[2],&q[3],&q[4],&q[5],&q[6],&q[7])!=EOF) {
    
    int count,min = 10;
    for (auto it = sol.begin(); it != sol.end(); ++it) {
      count = 0;
      for (int i = 0; i < 8; i++) {
	if(q[i] != (*it)[i])count++;
      }
      if (count == 0){min = 0;break;}
      if (count < min) min = count;
    }

    cout << "Case " << ccount << ": " << min << endl;
    ccount++;
  }
  
  return 0;
}
