#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
  string str;
  cin >> str;
  while (str != "#") {
    if (next_permutation(str.begin(),str.end())) cout << str << endl;
    else cout << "No Successor" << endl;
    cin >> str;
  }
  return 0;
}
