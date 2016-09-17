#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    unsigned long s,q;
    unsigned long time = 0, nOfBoxes = 0;
    cin >> n >> s >> q;
    vector<queue<int> > stations;
    
    //taking input
    for (int j = 0; j < n; j++) {
      queue<int> temp;
      int naq;
      cin >> naq;
      nOfBoxes += naq;
      for (int k = 0; k < naq; k++) {
	int box;
	cin >> box;
	temp.push(box);
      }
      
      stations.push_back(temp);
    }

    

    vector<int> carrier;
    //simulation
  mark1:
    for (int j = 0; j < n; j++) {
     	
      while (!carrier.empty() && stations[j].size() <= q ) {
	if (carrier.back() - 1 == j) {
	  carrier.pop_back();
	  nOfBoxes--;
	  time++;
	  if(nOfBoxes == 0)goto mark2;
	  continue;
	}
	if(stations[j].size() == q)break;

	stations[j].push(carrier.back());
	carrier.pop_back();
	time++;
      }

      while (carrier.size() < s && !stations[j].empty()) {
	carrier.push_back(stations[j].front());
	stations[j].pop();
	time++;
      }

      time += 2;
      if(nOfBoxes == 0)break;
      if(j == n-1) goto mark1;
    }
  mark2:
    cout << time << endl;
  }
  return 0;
}
