#include <iostream>
#include <vector>
#include <string>
#include <bitset>

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
  unsigned long n,m;
  string str;
  while(1){
    vector<int> curr;
    vector<int> next;
    bitset<26> isAwake;
    bool willAwake;
    int years=0;
    curr.assign(26,0);
    next.assign(26,0);
    isAwake.reset();

    
    getline(cin,str);
    n=stoi(str);
    
    getline(cin,str);
    m=stoi(str);
    
    getline(cin,str);
    vector<UnionFind> v;
    v.assign(26, UnionFind(26));
    isAwake[str[0]-'A'] = true;
    isAwake[str[1]-'A'] = true;
    isAwake[str[2]-'A'] = true;
    v[str[0]-'A'].unionSet(str[1]-'A',str[2]-'A');
    v[str[0]-'A'].unionSet(str[1]-'A',str[0]-'A');
    v[str[1]-'A'].unionSet(str[2]-'A',str[0]-'A');
    v[str[1]-'A'].unionSet(str[2]-'A',str[1]-'A');
    v[str[2]-'A'].unionSet(str[0]-'A',str[1]-'A');
    v[str[2]-'A'].unionSet(str[2]-'A',str[1]-'A');

    for (unsigned long i = 0; i < m; i++) {
      getline(cin,str);
      v[str[0]-'A'].unionSet(str[0]-'A',str[1]-'A');
      v[str[1]-'A'].unionSet(str[0]-'A',str[1]-'A');
      if(isAwake[str[0]-'A'] && !isAwake[str[1]-'A'])curr[str[1]-'A']++;
      if(!isAwake[str[0]-'A'] && isAwake[str[1]-'A'])curr[str[0]-'A']++;
    }

    next = curr;

    while(1){
      if(isAwake.count()==n){
	  willAwake = true;
	  break;
	}
      
      willAwake = false;
      for (int i = 0; i < 26; i++) {
	if(!isAwake[i] && curr[i] > 2) {
	  isAwake[i] = true;
	  for (int j = 0; j < 26; j++)
	    if(v[i].isSameSet(i, j))next[j]++;
	  willAwake = true;
	}
	if(isAwake.count()==n){
	  willAwake = true;
	  break;
	}
      }

      years++;
      curr = next;
      if(!willAwake)break;

      if(isAwake.count()==n){
	willAwake = true;
	break;
      }
    }

    if(willAwake)cout << "WAKE UP IN, " << years << ", YEARS" << endl;
    else cout << "THIS BRAIN NEVER WAKES UP" << endl;

    if(cin.peek()==EOF)break;
    else getline(cin,str);
  }
  return 0;
}
