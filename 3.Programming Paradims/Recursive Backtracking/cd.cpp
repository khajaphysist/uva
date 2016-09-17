#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
//global variables
vector<int> tracks, best;
int N,n, bestSum=0;

void run(int i, int sum, vector<int> temp){
  sum += tracks[i];
  
  if(sum>N)return;
  
  else if(sum==N){
    temp.push_back(tracks[i]);
    if(bestSum < sum || (bestSum == sum && best.size() < temp.size())){
      best = temp;
      bestSum = sum;
    }
    return;
  }
  
  else{
    temp.push_back(tracks[i]);
    if (bestSum < sum || (bestSum == sum && best.size() < temp.size())) {
      bestSum = sum;
      best = temp;
    }
    for (int j = i+1; j < n; j++) {
      run(j,sum,temp);
    }
    return;
  }

  
}

int main()
{
  while (scanf("%d",&N)!=EOF) {
    cin >> n;
    tracks.resize(n, 0);
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      tracks[i] = temp;
    }

    for (int i = 0; i < n; i++) {
      vector<int>temp;
      run(i,0,temp);     
    }
   
    for (auto it = best.begin(); it != best.end(); ++it) {
      cout << *it << " ";
    }
    cout << "sum:" << bestSum << endl;

    best.clear();
    bestSum = 0;
    
    
  }
  return 0;
}
