#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int b,sgr,sbl;
    cin >> b >> sgr >> sbl;
    priority_queue<int> green, blue;
    for (int j = 0; j < sgr; j++) {
      int temp;
      cin >> temp;
      green.push(temp);
    }
    for (int j = 0; j < sbl; j++) {
      int temp;
      cin >> temp;
      blue.push(temp);
    }
    while (!green.empty()&&!blue.empty()) {
      vector<int> vg, vb;
      for (int j = 0; j < b; j++) {
	if (!green.empty()&&!blue.empty()) {
	  if(green.top() > blue.top())vg.push_back(green.top() - blue.top());
	  else if (blue.top() > green.top())vb.push_back(blue.top() - green.top());
	  green.pop();
	  blue.pop();
	}
	else break;
      }

      while (!vg.empty()) {
	green.push(vg.back());
	vg.pop_back();
      }
      while (!vb.empty()) {
	blue.push(vb.back());
	vb.pop_back();
      }
    }

    if(green.empty()&&blue.empty())cout << "green and blue died" << endl;
    if(!green.empty()){
      cout << "green wins" << endl;
      while (!green.empty()) {
	cout << green.top() << endl;
	green.pop();
      }
    }
    if(!blue.empty()){
      cout << "blue wins" << endl;
      while (!blue.empty()) {
	cout << blue.top() << endl;
	blue.pop();
      }
    }
    if(i!=t-1)cout << endl;
  }
  return 0;
}


