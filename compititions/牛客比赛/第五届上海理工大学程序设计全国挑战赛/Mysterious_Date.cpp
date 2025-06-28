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

struct Node{
  int m1,d1,m2,d2;
};

void solve() {
  int n,M,D;
  std::cin >> n >> M >> D;

  std::vector<Node> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i].m1 >> a[i].d1 >> a[i].m2 >> a[i].d2;
  }

  std::vector<int> d(M*D+5);
  for(int i = 0; i < n; ++i){
    ++d[(a[i].m1-1)*D+a[i].d1];
    --d[(a[i].m2-1)*D+a[i].d2+1];
  }

  std::vector<int> x = d;
  for(int i = 1; i <= M*D; ++i){
    x[i] += x[i-1];
  }
  // for(int i = 1; i <= M*D; ++i){
  //   std::cout << x[i] << " \n"[i%D==0];
  // }

  for(int i = 1; i <= M*D; ++i){
    if(x[i]==0){
      std::cout << (i/D+1) << " " << (i%D) << "\n";
      return;
    }
  }

  std::cout << "Online\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  // std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}