#include <queue>
#include <iostream>
#include <string>
using namespace std;

enum pos {l = 0,r = 1};

struct car{
  int id;
  int time;
};
int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    unsigned long cap;
    int stime,cases,max;
    cin >> cap >> stime >> cases;
    int atimes[cases];
    queue<car> left, right;
    for (int j = 0; j < cases; j++) {
      string str;
      car tcar;
      tcar.id = j;
      cin >> tcar.time;
      if(j == cases-1)max = tcar.time;
      cin >> str;
      if(str == "left")left.push(tcar);
      else right.push(tcar);
    }
    queue<car> ferry;
    pos ferpos = l, npos;
    int ftime = 0;
    while (!left.empty() || !right.empty()) {
      queue<car> &cq  = ferpos ? right : left;
      int lt,rt;
      lt = !left.empty() ? left.front().time : 10001;
      rt = !right.empty() ? right.front().time : 10001;
      if(lt < rt)npos = l;
      if(rt < lt)npos = r;
      if(lt == rt)npos = ferpos;
      int mmax;
      mmax = lt < rt ? lt : rt;
      ftime = mmax > ftime ? mmax : ftime;
      while(!cq.empty() && (cq.front().time <= ftime) && ferry.size() < cap){
	ferry.push(cq.front());
	cq.pop();
      }
      ftime += stime;
      ferpos = ferpos ? l : r;
      while (!ferry.empty()) {
	atimes[ferry.front().id] = ftime;
	ferry.pop();
      }
    }
    for(int a : atimes)cout << a << endl;
    if(i!=t-1)cout << endl;
  }
  return 0;
}
