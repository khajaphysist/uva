#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define vi vector<int>
#define ii pair<int,int>
#define vvi vector<vi>
#define um(a,b) unordered_map<a,b>
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

template<class T>
inline void pv(T const & v){
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it;
  }cout << endl;
}

template<class T>
inline void psv(T const & v){
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
  }cout << endl;
}

template<class T>
inline void pnv(T const & v){
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << endl;
  }cout << endl;
}

template<class T>
inline void pvv(T const & vv){
  for (auto it = vv.begin(); it != vv.end(); ++it) {
    pv(*it);
  }
}

template<class T>
inline void psvv(T const & vv){
  for (auto it = vv.begin(); it != vv.end(); ++it) {
    psv(*it);
  }
}

template<class T>
inline void pnvv(T const & vv){
  for (auto it = vv.begin(); it != vv.end(); ++it) {
    pnv(*it);
  }
}

inline void iv(vi &v,int n){
  for (int i = 0; i < n; ++i) {
    int temp;
    scanf("%d",&temp);
    v.push_back(temp);
  }
}
//global variables


int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    char fld[n];
    int count = 0;
    for (int j = 0; j < n; ++j)cin >> fld[j];
    for (int j = 0; j < n; ++j) {
      if(fld[j]=='.'){
        count++;
        j+=2;
      }
    }
    cout << "Case " << i+1 << ": " << count << endl;
  }
}
