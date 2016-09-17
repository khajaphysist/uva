#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;

void run(pair<int,int> left, pair<int,int> right, vector<pair<int,int> > &v, int count, bool & test){
  for (unsigned int i = 0; i < v.size(); i++) {
    auto tleft = left, tv = v[i];
    if (v[i].first == left.second || v[i].second == left.second) {
      if (v[i].second == left.second) {
	v[i].second = v[i].first;
	v[i].first = left.second;
      }
      left = v[i];
      v.erase(v.begin()+i);
      if (count+1 == n) {
	if(left.second == right.first){
	  test = true;
	  return;
	}
      }
      run(left,right,v,count+1,test);
      if(test)return;
      v.insert(v.begin()+i,tv);
      left = tleft;
    }
  }
}

int main()
{
  while (cin >> n,n) {
    int m;
    cin >> m;
    bool test = false;
    pair<int, int> left, right;
    cin >> left.first >> left.second >> right.first >> right.second;
    vector<pair<int,int> > v;
    v.resize(m);
    for (int i = 0; i < m; i++)cin >> v[i].first >> v[i].second;
    run(left,right,v,0,test);
    if(test)cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
