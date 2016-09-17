#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct person{
  int id, solved = 0;
  vector<int> problems;
  vector<bool> problemIsSolved;
  vector<int> ictimes;
  int penalty = 0;
  bool isPresent = false;
};

bool compare(const person& person1, const person& person2){
  if (person1.problems.size() < person2.problems.size())
    return true;
  if (person1.problems.size() == person2.problems.size() && (person1.penalty > person2.penalty))
    return true;
  if((person1.problems.size() == person2.problems.size()) && (person1.penalty == person2.penalty))
    return person1.id > person2.id;
  return false;
}

int main()
{
  int t;
  string str;
  getline(cin,str);
  t = stoi(str);
  for (int i = 0; i < t; i++) {
    
    vector<person> contestants;
    contestants.clear();
    contestants.resize(100);
    for (int j = 0; j < 100; j++) {
      contestants[j].id = j+1;
      contestants[j].problemIsSolved.resize(10,false);
      contestants[j].ictimes.resize(10,0);
      contestants[j].penalty = 0;
    }

    if(i==0) getline(cin, str);
    while (getline(cin,str),!str.empty()) {
      istringstream line(str);
      int cont, prob, time;
      char ans;
      line >> cont >> prob >> time >> ans;
      contestants[cont-1].isPresent = true;
      if (ans == 'C')  {
	if (!contestants[cont-1].problemIsSolved[prob-1]) {
	  contestants[cont-1].problemIsSolved[prob-1] = true;
	  contestants[cont-1].problems.push_back(prob-1);
	  contestants[cont-1].penalty += time;
	}
      }
      if (ans == 'I') {
	if (!contestants[cont-1].problemIsSolved[prob-1])
	  contestants[cont-1].ictimes[prob-1] += 1;
      }
    }


    for (auto it = contestants.begin(); it != contestants.end(); ++it)
      for (auto prob1 = it->problems.begin(); prob1 != it->problems.end(); ++prob1)
	it->penalty += it->ictimes[*prob1] * 20;
    

    
    
    sort(contestants.begin(),contestants.end(),compare);
    reverse(contestants.begin(),contestants.end());

    for (auto it = contestants.begin(); it != contestants.end(); ++it) {
      if(it->isPresent)
	cout << it->id << " " << it->problems.size() << " " << it->penalty << endl;
    }


    if(i!=t-1)cout << endl;
  }
  return 0;
}
