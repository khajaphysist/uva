#include<iostream>
using namespace std;

void calculate(){
  int k, L, totalCost = 0;
  char c;
  cin >> k;
  int costs[128];
  for (int i = 0; i < 128; i++) costs[i] = 0;
  for (int i = 0; i < k; i++) {
    cin >> c;
    cin >> costs[(int)c];
  }
  cin >> L;
  for (int i = 0; i <= L; i++) {
    string str;
    getline(cin,str);
    for (auto it = str.begin(); it != str.end(); ++it){
      if ((int) *it >127 || (int) *it < 0) {
	
      }
      else
	totalCost += costs[(int) *it];
      
    }
  }
  int dollar, cents;
  dollar = totalCost - totalCost % 100;
  dollar = dollar / 100;
  cents = totalCost % 100;
  if (cents < 10) {
    cout << dollar << "." << "0"<< cents << "$" << endl;
  }
  else
    cout << dollar << "." << cents << "$" << endl;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    calculate();
  }
  return 0;
}
