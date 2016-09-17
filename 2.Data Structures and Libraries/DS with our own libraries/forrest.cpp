#include <sstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;

int main()
{
  int t;
  string str;
  getline(cin,str);
  istringstream istr(str);
  istr >> t;
  for (int i = 0; i < t; i++) {
    unsigned long ne = 0;
    bitset<26> b;
    while (getline(cin,str),str[0]!='*') {
      ne++;
      char u,v;
      u = str[1];
      v = str[3];
      b.set(u-'A',true);
      b.set(v-'A',true);
    }
    getline(cin,str);
    unsigned long nv = str.size()/2 + 1;
    printf("There are %lu tree(s) and %lu acorn(s).\n",b.count()-ne,nv-b.count());
  }
  return 0;
}

