#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

constexpr int inf = 2E9 + 1;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<int> h(n), x(n);
  for(int i = 0; i < n; i++){
    std::cin >> h[i];
  }
  for(int i = 0; i < n; i++){
    std::cin >> x[i];
  }

  std::vector<std::array<int, 2>> a(n);
  for(int i = 0; i < n; i++){
    a[i] = {x[i], x[i] + h[i]};
  }

  std::sort(a.begin(), a.end());

  int st = -inf, ed = -inf, cnt = 0;
  std::vector<int> res;
  for(int i = 0; i < a.size(); i++){
    auto [_x, _xh] = a[i];

    if(ed >= _x || st == -inf){
      ed = std::max(ed, _xh);
      if(st == -inf){
        st = _x;
      }
      cnt++;
    }else{
      res.push_back(cnt);
      cnt = 1;
      st = _x, ed = _xh;
    }
  }

  if(st != -inf){
    res.push_back(cnt);
  }

  std::sort(res.begin(), res.end(), std::greater<>());

  int ans = 0;

  for(int i = 0; i < std::min<int>(m, res.size()); i++){
    ans += res[i];
  }

  std::cout << ans << "\n";
}

int main() {
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