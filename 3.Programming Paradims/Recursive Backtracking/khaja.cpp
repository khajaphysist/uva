#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
  int N,n;
  vector<int> tracks;
  tracks.resize(20, 0);
	
  while (scanf("%d",&N)!=EOF) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      tracks[i] = temp;
    }
		
    vector<int> s;
    vector<int> store;
    int sum = 0;
    int rsum = 0;
    int nxt = 0;
		
    while(1){
      if(nxt<n){
	if(sum+tracks[nxt]<=N){
	  sum += tracks[nxt];
	  s.push_back(nxt);
	  nxt++;
	}
	else{
	  nxt++;
	}
      }
      else if(!s.empty()){
	sum -= tracks[s.back()];
	nxt = s.back()+1;
	s.pop_back();
      }
      else break;
		    
      if((sum>rsum && sum<=N) || (sum==rsum && s.size()>store.size())){
	store = s;
	rsum = sum;
      }
    }
    reverse(store.begin(), store.end());
    sum = accumulate(store.begin(),store.end(),0);
    while (!store.empty()) {
      cout << tracks[store.back()] << " ";
      store.pop_back();
    }
    cout << "sum:" << rsum;
    cout << endl;
  }
  return 0;
}
