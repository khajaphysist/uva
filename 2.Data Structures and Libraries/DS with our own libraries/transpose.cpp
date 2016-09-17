#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> adl;

int main()
{
  int m,n;
  while (scanf("%d %d",&m,&n) != EOF) {
    adl mat, omat;
    for (int i = 0; i < m; i++) {
      int r;
      vii tvii;
      cin >> r;
      for (int j = 0; j < r; j++) {
	int temp;
	cin >> temp;
	tvii.push_back(make_pair(temp,0));
      }
      mat.push_back(tvii);
      for (int j = 0; j < r; j++) {
	int temp;
	cin >> temp;
	mat[i][j].second = temp;
      }
    }
    
    cout << n << " " << m << endl;
    omat.resize(n);

    for (int i = 0; i < m; i++) {
      for (unsigned long j = 0; j < mat[i].size(); j++) {
	omat[mat[i][j].first-1].push_back(make_pair(i+1,mat[i][j].second));
      }
    }

    for (int i = 0; i < n; i++) {
      if(omat[i].empty()) cout << "0" << endl << endl;
      else{
	cout << omat[i].size() << " ";
	for (unsigned long j = 0; j < omat[i].size(); j++) {
	  cout << omat[i][j].first;
	  if (j != omat[i].size() -1) cout << " ";
	}
	cout << endl;
	for (unsigned long j = 0; j < omat[i].size(); j++) {
	  cout << omat[i][j].second;
	  if (j != omat[i].size() -1) cout << " ";
	}
	cout << endl;
      }
    }
    
  }
  return 0;
}
