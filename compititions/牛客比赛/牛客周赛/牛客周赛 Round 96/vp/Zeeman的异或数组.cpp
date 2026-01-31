#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using d128 = long double;

constexpr int inf1 = 1'000'000'000, P = 131;//P = 13331;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr int inf2 = 0x3f3f3f3f;
constexpr i64 inf3 = 1'000'000'000'000'000'000;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define fi first
#define se second

template<typename T = i64,bool is_i64 = true>
struct linear_basis{
    std::vector<T> d;
    int len;
    linear_basis(){
        d.assign(is_i64?64:32,T{});
        len = is_i64?62:30;
    }

    template<typename Q>
    void insert(Q x){
        for(int i = len; i >= 0; --i){
            if(x&(1LL<<i)){
                if(d[i]){
                    x ^= d[i];
                }else{
                    d[i] = x;
                    break;
                }
            }
        }
    }
    template<typename Q>
    bool contains(Q x){
      for(int i = len; i >= 0; --i){
        if(x&(1LL<<i)){
          if(d[i]){
            x ^= d[i];
          }
        }
      }
      return x == 0;
    }
    T find_max(){
        T res {};
        for(int i = len; i >= 0; --i){
            if(res^d[i]>res){
                res ^= d[i];
            }
        }
        return res;
    }
    int count(){
        int res = 0;
        for(int i = len; i >= 0; --i){
            if(d[i]){
                ++res;
            }
        }
        return res;
    }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<i64> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  linear_basis lb;
  for(int i = 0; i < n; ++i){
    lb.insert(a[i]);
  }

  for(int i = 0; i <= 62; ++i){
    if(!lb.contains(1LL<<i)){
      std::cout << (1LL<<i) << "\n";
      return;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}