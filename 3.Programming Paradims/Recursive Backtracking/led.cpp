#include <set>
#include <vector>
#include <iostream>
using namespace std;

#define vi vector<int>
#define vc vector<char>
#define si set<int>
const char s[][7] = {{'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N'},
		     {'N', 'Y', 'Y', 'N', 'N', 'N', 'N'},
		     {'Y', 'Y', 'N', 'Y', 'Y', 'N', 'Y'},
		     {'Y', 'Y', 'Y', 'Y', 'N', 'N', 'Y'},
		     {'N', 'Y', 'Y', 'N', 'N', 'Y', 'Y'},
		     {'Y', 'N', 'Y', 'Y', 'N', 'Y', 'Y'},
		     {'Y', 'N', 'Y', 'Y', 'Y', 'Y', 'Y'},
		     {'Y', 'Y', 'Y', 'N', 'N', 'N', 'N'},
		     {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
		     {'Y', 'Y', 'Y', 'Y', 'N', 'Y', 'Y'}};
vector<vc> g;
int n;
bool flag = false;

void run(int p, si burned){
  for (int i = 1; i < n && p >= 0; i++) {
    p--;
    for (int j = 0; j < 7; j++) {
      if (g[i][j] == 'Y' && s[p][j] == 'N') {
	return;
      }
      if (g[i][j] == 'Y' && s[p][j] == 'Y') {
	if(burned.find(j)!=burned.end())return;
      }
      if (g[i][j] == 'N' && s[p][j] == 'Y') {
	if(burned.find(j)==burned.end())burned.insert(j);	
      }
    }
  }
  flag = true;
}

int main()
{
  while (cin >> n,n) {
    g.clear();
    g.resize(n);
    flag = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 7; ++j) {
	char c; cin >> c;
	g[i].push_back(c);
      }
    }
    si t;
    vi possible;
    vector<si>burned;
    for (int i = 0; i < 10; ++i) {
      t.clear();
      for (int j = 0; j < 7; j++) {
	if(g[0][j]=='Y' && s[i][j]=='N')break;
	if(g[0][j]!=s[i][j])t.insert(j);
	if(j == 6){burned.push_back(t);possible.push_back(i);}
      }
    }
    
    for (unsigned int i = 0; i < possible.size(); i++) {
      if(possible[i]<n-1)continue;
      run(possible[i],burned[i]);
    }
    if(flag) cout << "MATCH" << endl;
    else cout << "MISMATCH" << endl;
  }
  return 0;
}
