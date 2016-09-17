#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  char c;
  list<char> a,b;
  bool flag = true;
  while (flag) {
    c = cin.get();
    if (c == EOF) return 0;

    while (c != '\n' && c != EOF) {
      a.push_back(c);
      c = cin.get();
      if (c == EOF) flag = false;
    }
    
    for (auto it = a.begin(), iti = b.begin(); it != a.end();) {
      if (*it == '[') {
	it = a.erase(it);
	if(it == a.end())break;
	iti = b.begin();
	continue;
      }
      if (*it == ']') {
	it = a.erase(it);
	if(it == a.end())break;
	iti = b.end();
	continue;
      }
      if (it!=a.end()) {
	b.insert(iti,*it);
	it++;
      }
      
    }

    for (auto it = b.begin(); it != b.end(); ++it)
      cout << *it;
    cout << endl;
    a.clear();
    b.clear();
    
  }
  
  return 0;
}

