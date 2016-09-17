#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

bool isprime(int p){
  if(p==2||p==3||p==5||p==7||p==11||p==13||p==17||p==19||p==23||p==29||p==31)return true;
  else return false;
}

void run(vector<int> temp, vector<int> v, vector<vector<int> > &sol){
  auto ct = temp;
  auto cv = v;
  for (unsigned int i = 0; i < v.size(); i++) {
    temp = ct; v = cv;
    
    if (isprime(temp.back()+v[i])) {
      temp.push_back(v[i]);
      v.erase(v.begin()+i);

      if (v.empty()) {
	if (isprime(temp.back()+1)) {
	  sol.push_back(temp);
	  return;
	}
      }   
      run(temp,v,sol);
    }

    
  }

 
  
}

int main()
{
  int n;
  int count = 1;
  while (scanf("%d",&n)!=EOF) {
    vector<int> v,temp;
    for (int i = 2; i <= n; i++)v.push_back(i);
    vector<vector<int> > sol;
    temp.push_back(1);
    run(temp,v,sol);

    cout << "Case " << count << ":" << endl;
    count++;
    for (auto it = sol.begin(); it != sol.end(); ++it) {
      for (auto it1 = (*it).begin(); it1 != (*it).end(); ++it1) {
	if(it1+1 == (*it).end())cout << *it1;
	else cout << *it1 << " ";
      }
      cout << endl;
    }
    if(cin.peek()!=EOF)cout << endl;
  }
  return 0;
}

