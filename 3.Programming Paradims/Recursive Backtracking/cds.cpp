#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
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
    int sum = 0;
    int rsum = 0;
    int last = 0;
    int nxt = 0;
    // int lpop=0, lpush = 0;
    vector<int> store;
    s.push_back(0);
    sum += tracks[0];
    nxt = 1;
   
    while (!s.empty()) {

      if(nxt>=n){
        sum-=tracks[s.back()];
	last = s.back(); 
	s.pop_back();
	nxt = last+1;
      }
      else{
	
	while (sum+tracks[nxt] <= N && nxt < n ) {
	  s.push_back(nxt);
	  // lpush = lpop + 1;
	  sum+= tracks[s.back()];
	  nxt++;
	  // lpop++;
	}
      

	if(nxt >= n){
	  //if(sum >= rsum || (sum == rsum && s.size() > store.size()))store = s;
	  if((sum>rsum && sum<=N) || (sum == rsum && s.size() > store.size())){
	    store = s;
	    rsum = sum;
	  }

	  sum-=tracks[s.back()];
	  s.pop_back();
	  // lpop = lpush;
	  // lpush--;

	  sum-=tracks[s.back()];
	  last = s.back(); 
	  s.pop_back();
	  nxt = last+1;
	  // s.push_back(s.back()+1);
	  // lpop = lpush;
	  // lpush--;
	}

	else{
	  if((sum>rsum && sum<=N) || (sum == rsum && s.size() > store.size())){
	    store = s;
	    rsum = sum;
	  }
	  // lpop++;
	  nxt++;

	}
      }
    }

    while (!store.empty()) {
      cout << store.back() << " ";
      store.pop_back();
    }

    cout << endl;
  }
  return 0;
}
