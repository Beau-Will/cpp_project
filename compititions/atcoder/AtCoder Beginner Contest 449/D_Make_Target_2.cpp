#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int L, R, D, U;
  std::cin >> L >> R >> D >> U;

  i64 ans = 0;
  int umin = L + D;
  int umax = R + U;

  auto count = [&](i64 l, i64 r, int t){
    if(l > r){
      return 0LL;
    }

    t = (t % 4 + 4) % 4;
    i64 st = l + ((t - l) % 4 + 4) % 4;

    if(st > r){
      return 0LL;
    }
    return (r - st) / 4 + 1;
  };

  for(int u = umin; u <= umax; u++){
    i64 vmin = std::max(2LL * L - u, 1LL * u - 2 * U);
    i64 vmax = std::min(2LL * R - u, 1LL * u - 2 * D);
    if(vmin > vmax){
      continue;
    }

    i64 vl = vmin, vr = vmax;
    int uabs = std::abs(u);
    int t = u & 1;

    i64 ed = std::min(vr, -1LL);
    if(vl <= ed){
      int tmp = uabs % 4;

      for(int r = 0; r < 4; r++){
        if((r & 1) == t && r == tmp){
          ans += count(vl, ed, r);
          break;
        }
      }
    }

    if(vl <= 0 && vr >= 0){
      if(t == 0 && uabs % 4 == 0){
        ans++;
      }
    }

    i64 st = std::max(vl, 1LL);
    if(st <= vr){
      int tmp = ((-uabs) % 4 + 4) % 4;
      for(int r = 0; r < 4; r++){
        if((r & 1) == t && r == tmp){
          ans += count(st, vr, r);
          break;
        }
      }
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}