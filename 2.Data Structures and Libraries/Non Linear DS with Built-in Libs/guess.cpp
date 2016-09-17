#include <stack>
#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
  int n;
  while (scanf("%d",&n) != EOF) {
    stack<int>s;
    queue<int>q;
    priority_queue<int>p;
    bool is = true, iq = true, ip = true;
    for (int i = 0; i < n; i++) {
      int t,x;
      cin >> t;
      if (t == 1) {
	cin >> x;
	s.push(x);
	q.push(x);
	p.push(x);
      }else if (t==2) {
	cin >> x;
	if (is) {
	  is = (x == s.top()) ? true : false;
	  s.pop();
	}
	if (iq) {
	  iq = (x == q.front()) ? true : false;
	  q.pop();
	}
	if (ip) {
	  ip = (x == p.top()) ? true : false;
	  p.pop();
	}
      }
    }

    if(is && !iq && !ip)cout << "stack" << endl;
    else if(!is && iq && !ip)cout << "queue" << endl;
    else if(!is && !iq && ip)cout << "priority queue" << endl;
    else if(!is && !iq && !ip)cout << "impossible" << endl;
    else cout << "not sure" << endl;
  }
  return 0;
}

