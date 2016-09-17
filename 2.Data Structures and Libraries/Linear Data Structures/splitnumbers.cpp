#include <iostream>
#include <vector>
using namespace std;

int main()
{
  uint32_t n;
  while (cin >> n,n) {
    vector<int> v;
    for (int i = 0; i < 32; i++) {
      if (n & (1<<i)) v.push_back(i);
    }


    uint32_t a = 0, b = 0;
    for (decltype(v.size()) i = 0; i < v.size(); i++) {
      if(i%2){
	a |= (1<<v[i]);
      }else{
	b |= (1<<v[i]);
      }
    }

    cout << b << " " << a << endl;
  }
  return 0;
}
