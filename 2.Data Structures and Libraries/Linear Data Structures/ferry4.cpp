#include <queue>
#include <iostream>
#include <string>
using namespace std;

enum pos {l = 0,r = 1};

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int cap;
    int turns = 0;
    int cases;
    cin >> cap >> cases;
    cap *= 100;
    queue<int> left, right;
    for (int j = 0; j < cases; j++) {
      string str;
      int temp;
      cin >> temp;
      cin >> str;
      if(str == "left")left.push(temp);
      else right.push(temp);
    }

    int ferry=0;
    pos ferpos = l;
    while (!(left.empty() && right.empty())) {
      queue<int> &cq = ferpos ? right :left;
      while (ferry <= cap && !cq.empty()) {
	if(ferry + cq.front() > cap)break;
	ferry += cq.front();
	cq.pop();
	if(ferry == cap)break;
      }
      turns ++;
      ferpos = ferpos ? l : r;
      ferry = 0;
    }
    cout << turns << endl;
  }
  return 0;
}
