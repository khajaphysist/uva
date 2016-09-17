#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
  int n;
  while (cin >> n,n){
    int mp=1;
    map<set<int>,int> frosh;
    for (int i = 0; i < n; i++) {
      set<int> temp;
      for (int j = 0; j < 5; j++) {
	int c;
	cin >> c;
	temp.insert(c);
      }
      auto it = frosh.find(temp);
      if(it == frosh.end()) frosh.insert(make_pair(temp,1));
      else {
	it->second += 1;
	mp = it->second > mp ? it->second : mp;
      }
    }
    
    if(mp==1)cout << n << endl;
    else{
      int count = 0;
      for (auto it = frosh.begin(); it != frosh.end(); ++it)
	if(it->second == mp)count+=mp;
      cout << count << endl;
    }
  }
  return 0;
}
