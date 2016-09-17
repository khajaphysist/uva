#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    int count = 0;
    cin >> n;
    UnionFind F(100000);
    unordered_map<string,int> N;
    for (int j = 0; j < n; j++) {
      string f1,f2;
      cin >> f1 >> f2;
      auto it1 = N.find(f1);
      auto it2 = N.find(f2);
      if(it1 != N.end() && it2 != N.end()){
	F.unionSet(it1->second,it2->second);
	cout << F.sizeOfSet(it1->second) << endl;
      }
      if(it1 == N.end() && it2 != N.end()){
	N.insert(make_pair(f1,count));
	F.unionSet(count, it2->second);
	cout << F.sizeOfSet(count) << endl;
	count++;
      }
      if(it1 != N.end() && it2 == N.end()){
	N.insert(make_pair(f2,count));
	F.unionSet(it1->second,count);
	cout << F.sizeOfSet(count) << endl;
	count++;
      }
      if(it1 == N.end() && it2 == N.end()){
	N.insert(make_pair(f1,count));
	F.unionSet(count, count+1);
	count++;
	N.insert(make_pair(f2,count));
	cout << F.sizeOfSet(count) << endl;
	count++;
      }
      
    }
  }
  return 0;
}


