#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int S,n;

void run(vector<int> &temp, vector<int> &v, vector<vector<int> > &sol, int sum, int i){
  if(sum+v[i] < S){
    temp.push_back(v[i]);
    sum += v[i];
    for (int j = i+1; j < n; j++) {
      run(temp,v,sol,sum,j);
    }
    temp.pop_back();
    sum -= v[i];
  }
  if(sum+v[i] == S){
    temp.push_back(v[i]);
    sol.push_back(temp);
    temp.pop_back();
  }

}

int main()
{
  while (cin >> S >> n, S) {
    vector<int> v;
    int sum = 0, k = 0;
    for (int i = 0; i < n; i++) {
      int temp; cin >> temp;
      v.push_back(temp);
      sum += temp;
    }
    cout << "Sums of " << S << ":" << endl;
    if (sum < S) {
      cout << "NONE" << endl;
      continue;
    }

    while (sum >= S) {
      sum -= v[k];
      k++;      
    }

    
    vector<vector<int> > sol;
    vector<int> temp;

    for (int i = 0; i < k; i++) {
      run(temp,v,sol,0,i);  
    }

    bool flag = false;
    for (auto it = sol.begin(); it != sol.end(); ++it) {
      
      if(find(sol.begin(),it,*it)==it){
	if(!it->empty())flag = true;
	for (auto it1 = (*it).begin(); it1 != (*it).end(); ++it1) {
	  if (it1+1 == it->end()) {
	    cout << *it1;
	  }else cout << *it1 << "+";
	}
	cout << endl;
      }
      
    }

    if(!flag)cout << "NONE" << endl;
  }
  return 0;
}
