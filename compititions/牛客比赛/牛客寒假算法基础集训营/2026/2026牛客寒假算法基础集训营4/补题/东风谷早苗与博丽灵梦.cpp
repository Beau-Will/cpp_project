#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

using i128 = __int128;

std::ostream& operator<<(std::ostream& os, i128 n) {
  if (n == 0) {
    return os << 0;
  }
  std::string s;
  while (n > 0) {
    s += char('0' + n % 10);
    n /= 10;
  }
  std::reverse(s.begin(), s.end());
  return os << s;
}

namespace Exgcd {
  std::array<i128, 4> get(i64 a, i64 b, i64 c) {
    std::array<i128, 4> ans = {1, 0, 0, 1};
    auto &[x, y, g, f] = ans;
    std::function<void(i64, i64)> dfs = [&](i64 a, i64 b){
      if (b == 0) {
        ans[2] = a;
        return;
      }
      dfs(b, a % b);
      ans = {ans[1], ans[0] - (a / b) * ans[1], ans[2], ans[3]};
    };
    dfs(a, b);
    if(g < 0){
      g = -g;
      x = -x;
      y = -y;
    }
    if(c % g) f = 0;
    else{
      x *= c / g;
      y *= c / g;
    }
    return ans;
  }

  std::array<i128, 2> minx(i64 a, i64 b, i64 c) {
    auto [x, y, g, f] = get(a, b, c);
    if(!f) return {-1, -1};
    if(!c) return {0, g};
    auto bg = b / g;
    auto k = -x / bg;
    while(x + k * bg < 0) k++;
    while(x + (k - 1) * bg >= 0) k--;
    return {x + k * bg, g};
  }
};

void solve(){
  i64 x, a, s;
  std::cin >> x >> a >> s;

  auto [_, g] = Exgcd::minx(a, s, x);
  auto X = _;
  auto Y = (x - X * a) / s;

  if(X < 0 || Y < 0){
    std::cout << "No\n";
    return;
  }
  
  std::cout << "Yes\n";
  auto sg = s / g;
  
  auto check = [&](auto mid){
    auto x1 = X + mid * sg;
    auto y1 = (x - x1 * a) / s;
    return std::pair(x1, y1);
  };

  i128 l = 0, r = 1E18;
  while(l < r){
    auto mid = (l + r) >> 1;
    auto [x1, y1] = check(mid);
    if(x1 > y1) r = mid;
    else l = mid + 1;
  }

  auto [x1, y1] = check(l);
  auto [x0, y0] = check(l - 1);

  int tar = 1;
  if(std::min(x1, y1) < 0){
    tar = 0;
  }else if(std::min(x0, y0) < 0){
    tar = 1;
  }else{
    if(std::max(x1, y1) <= std::max(x0, y0)){
      tar = 1;
    }else{
      tar = 0;
    }
  }

  if(tar){
    std::cout << x1 << " " << y1 << "\n";
  }else{
    std::cout << x0 << " " << y0 << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}