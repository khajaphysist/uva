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
#define si set<int>
#define ii pair<int,int>
#define vvi vector<vi>
#define um(a,b) unordered_map<a,b>
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

template<class T>
inline void pv(T const & v, char c){
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it;
    auto ite = it;
    if (++ite == v.end())continue;
    else if(c!='x'){cout << c;}
  }if(c != '\n')cout << endl;
}

template<class T>
inline void pa(T const v[],int n, char c){
  for (int i = 0; i < n; ++i) {
    cout << v[i];
    if (i==n-1)continue;
    else if(c!='x'){cout << c;}
  }
  if(c != '\n')cout << endl;
}


template<class T>
inline void pvv(T const & vv, char c){
  for (auto it = vv.begin(); it != vv.end(); ++it) {
    pv(*it,c);
  }
}


inline void iv(vi &v,int n){
  for (int i = 0; i < n; ++i) {
    int temp;
    scanf("%d",&temp);
    v.push_back(temp);
  }
}

inline void is(si &v,int n){
  for (int i = 0; i < n; ++i) {
    int temp;
    scanf("%d",&temp);
    v.insert(temp);
  }
}

template<class T>
inline void ia(T a[],int n){
  for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
}

//global variables
int p[100][100], a[100];
int main(){
  int t;
  cin >> t;
  for (int it = 0; it < t; ++it) {
    int n,m,k; cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int temp; cin >> temp;
        p[i][j] = temp + (i?p[i-1][j]:0);
      }
    int mxarea = 0, minprice = 0;
    for (int i1 = 0; i1 < n; ++i1)
      for (int i2 = i1; i2 < n; ++i2){
        int price = 0, count = 0;
        for (int j = 0; j < m; ++j) {
          a[j] = p[i2][j] - (i1?p[i1-1][j]:0);
          if (count && (price + a[j] > k)) {
            if (mxarea<(i2-i1+1)*count) {
              mxarea = (i2-i1+1)*count;
              minprice = price;
            }
            if (mxarea==(i2-i1+1)*count)minprice = price < minprice ? price : minprice;
            while (count) {
              if (price+a[j]>k) {
                price-=a[j-count];
                count--;
              }else break;
            }
          }
          if(a[j]>k) continue;
          price+=a[j];
          count++;
          if (price == k || j == m-1) {
            if (mxarea<(i2-i1+1)*count) {
              mxarea = (i2-i1+1)*count;
              minprice = price;
            }
            if (mxarea==(i2-i1+1)*count)minprice = price < minprice ? price : minprice;
          }
        }
      }
    cout << "Case #" << it+1 << ": " << mxarea << " " << minprice << endl;

  }
}
