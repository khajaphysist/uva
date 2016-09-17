#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int count(vector<string> big, vector<string> small){
  int ret = 0;
  int N = big.size();
  int n = small.size();
  vector<size_t> pos;
  for (int i = 0; i < N-n+1; i++) {
    pos.clear();
    size_t fnd = big[i].find(small[0]);
    while (fnd != string::npos) {
      pos.push_back(fnd);
      fnd = big[i].find(small[0],fnd+1);
    }
    for (int j = 1; j < n; j++) {
      for (auto it = pos.begin(); it != pos.end();) {
	if (big[i+j].find(small[j],*it) != *it){
	  it = pos.erase(it);
	}
	else
	  ++it;
      }
    }
    ret += pos.size();
  }
  return ret;
}

int main()
{
  int N,n;
  while (scanf("%d %d",&N,&n),N) {
    vector<string> big, small, temp;
    string str;
    for (int i = 0; i < N; i++) {
      cin >> str;
      big.push_back(str);
    }
    for (int i = 0; i < n; i++) {
      cin >> str;
      small.push_back(str);
      temp.push_back("");
    }
    cout << count(big,small) << " ";
    for (int i = 0; i < n; i++) {
      for (int j = 0;j < n; j++) {
	temp[j] += small[n-1-i][j];
      }
    }
    cout << count(big,temp) << " ";
    for (int i = 0; i < n; i++) {
      for (int j = 0;j < n; j++) {
	small[j][n-i-1] = temp[i][j];
      }
    }
    cout << count(big,small) << " ";
    for (int i = 0; i < n; i++) {
      for (int j = 0;j < n; j++) {
	temp[j][n-i-1] = small[i][j];
      }
    }
    cout << count(big,temp) << endl;
  }
  return 0;
}
