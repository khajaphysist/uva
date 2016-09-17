#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string answer(int N){
  int curr, prev;

  vector<int> flags;

    for (int i = 0; i < N; i++) flags.push_back(0);
    
    scanf("%d",&prev);
    
    for (int i = 0; i < N-1; i++) {

      scanf("%d",&curr);

      if (curr - prev == 0){
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return "Not jolly";
      }

      if (abs(curr - prev) >= N){
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return "Not jolly";
      }
      
      if (flags[abs(curr - prev)] == 0)
	flags[abs(curr - prev)] = 1;
      
      else{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return "Not jolly";
      }

      prev = curr;
    }
    return "Jolly";
 
}

int main()
{
  int N, temp;
  while(scanf("%d",&N)!=EOF){
    if (N == 1) {
      scanf("%d", &temp);
      cout << "Jolly" << endl;
    }
    else
    cout << answer(N) << endl;
  }
  return 0;
}
