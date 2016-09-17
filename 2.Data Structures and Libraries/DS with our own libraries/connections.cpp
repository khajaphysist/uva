#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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
  string str;
  getline(cin,str);
  istringstream istr(str);
  istr >> t;
  
  getline(cin,str);
  
  for (int i = 0; i < t; i++) {
    int n, u = 0, s = 0;
    getline(cin,str);
    n = stoi(str);
    UnionFind N(n);
    while (getline(cin,str),str != "") {
      char c;
      int ci,cj;
      istringstream istr1(str);
      istr1.get(c);
      istr1 >> ci >> cj;
      if(c == 'c')N.unionSet(ci-1,cj-1);
      if (c == 'q') {
	if(N.isSameSet(ci-1, cj-1))s++;
	else u++;
      }
    }
    cout << s << "," << u << endl;
    if(i!=t-1)cout << endl;
  }
  return 0;
}
