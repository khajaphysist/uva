#include <queue>
#include <iostream>
#include <string>
using namespace std;

struct query{
  int id;
  int time;
  int interval;
  bool operator<(const query &q)const;
  query(){
    id = 0;
    time = 0;
    interval = 0;
  }
};

bool query::operator<(const query &q) const
{
  if(time == q.time)return id > q.id;
  else return time > q.time;
}

int main()
{
  string str;
  priority_queue<query> reqs;
  
  while(cin >> str, str != "#"){
    int qid,t;
    cin >> qid >> t;
    query temp = query();
    temp.id = qid;
    temp.interval = t;
    temp.time = t;
    reqs.push(temp);
  }
  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    query temp = reqs.top();
    reqs.pop();
    temp.time += temp.interval;
    reqs.push(temp);
    cout << temp.id << endl;
  }


  
  return 0;
}

