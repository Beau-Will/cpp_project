#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<double> f(1000);

void solve() {
  int n;
  std::cin >> n;
  std::cout << std::fixed << std::setprecision(2) << f[n] << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  double s = 0;
  for(int i = 1; i < 1000; i++){
    if(i&1){
      s += 1./i;
    }else{
      s -= 1./i;
    }
    f[i] = s;
  }

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}