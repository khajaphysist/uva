#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  string str;
  int cnt = 1;
  while(cin >> str, str[0] != 'e'){
    vector<vector<char> > v;
    for (char c : str) {
      if(v.size() == 0){
	vector<char> t;
	t.push_back(c);
	v.push_back(t);
      }else{
	for (auto it = v.begin(); it != v.end(); ++it){
	  if(it->back() >= c){
	    it->push_back(c);
	    goto mark;
	  }
	}
	vector<char> t;
	t.push_back(c);
	v.push_back(t);
	
      }
    mark:
      continue;
    }

    cout << "Case " << cnt << ": " << v.size() << endl;
    cnt++;
    
  }
  
  return 0;
}
