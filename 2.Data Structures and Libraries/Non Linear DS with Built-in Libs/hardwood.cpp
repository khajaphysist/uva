#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
  int t;
  string str;
  getline(cin,str);
  t = stoi(str);
  for (int i = 0; i < t; i++) {
    int count = 0;
    map<string,int> trees;
    cout << setprecision(4) << fixed;
    if(i==0)getline(cin,str);
    while (getline(cin,str),!str.empty()) {
      count ++;
      auto it = trees.find(str);
      if (it == trees.end()) trees.insert(make_pair(str,1));
      else it->second += 1;
    }
    for (auto it = trees.begin(); it != trees.end(); ++it) {
      double temp;
      temp = ((double)it->second)/((double)count);
      temp *= 100;
      cout << it->first << " " << temp << endl;
    }
    if(i!=t-1)cout << endl;
  }
  return 0;
}
