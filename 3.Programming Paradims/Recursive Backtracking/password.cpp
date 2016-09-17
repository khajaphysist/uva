#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;
#define sc set<char>
#define vi vector<int>
#define vc vector<char>

template<class T>
void pv(T  &v){
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it;
  }cout << endl;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    sc g1[5],g2[5];
    vector<char> p[5];
    for (int j = 0; j < 6; j++) {
      for (int l = 0; l < 5; l++) {
	char temp;
	cin >> temp;
	g1[l].insert(temp);
      }
    }
    for (int j = 0; j < 6; j++) {
      for (int l = 0; l < 5; l++) {
	char temp;
	cin >> temp;
	g2[l].insert(temp);
      }
    }
    
    for (int j = 0; j < 5; j++) {
      p[j] = vector<char>(6,'-');
      set_intersection(g1[j].begin(), g1[j].end(), g2[j].begin(), g2[j].end(), p[j].begin());
    }
    int m[5];
    bool flag = false;
    for (int j = 0; j < 5; j++) {
      m[j]=0;
      for (int l = 0; l < 5; l++) {
	if(p[j][l]!='-')++m[j];
	else break;
      }
      if(m[j]==0){flag = true; break;}
    }

    
    
    if(flag){cout << "NO" << endl;continue;}
    vc out;
    int m1,m2,m3,m4;

    m4 = m[3]*m[2]*m[1]*m[4];
    m3 = m[2]*m[4]*m[3];
    m2 = m[3]*m[4];
    m1 = m[4];

    if(k > m4 * m[0]){cout << "NO" << endl;continue;}
    k--;

    int r1,r2,r3,r4;

    r4 = k >=m4 ? k %m4 : k;
    r3 = r4>=m3 ? r4%m3 : r4;
    r2 = r3>=m2 ? r3%m2 : r3;
    r1 = r2>=m1 ? r2%m1 : r2;

    out.push_back(p[0][k/m4]);
    out.push_back(p[1][r4/m3]);
    out.push_back(p[2][r3/m2]);
    out.push_back(p[3][r2/m1]);
    out.push_back(p[4][r1]);

    for (auto it = out.begin(); it != out.end(); ++it) {
      cout << *it;
    }cout << endl;
  }
  return 0;
}
