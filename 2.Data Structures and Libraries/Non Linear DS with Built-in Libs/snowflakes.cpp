#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    vector<int> v;
    unsigned long mxsize=0;
    cin >> n;
    unordered_map<int,int> pack;
    for (int j = 0; j < n; j++) {
      int f;
      cin >> f;
      v.push_back(f);
      auto it = pack.find(f);
      if(it == pack.end())pack.insert(make_pair(f,j));
      else{
	for (int k = it->second; k >= 0 && !pack.empty(); k--) {
	  auto et = pack.find(v[k]);
	  if(et == pack.end())continue;
	  else{
	    if(et->second > it->second)continue;
	    else
	      pack.erase(v[k]);
	  }
	}
	pack.insert(make_pair(f,j));
      }
      mxsize = mxsize > pack.size() ? mxsize : pack.size();
      
    }
    cout << mxsize << endl;
  }
  return 0;
}

