#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  i64 x1,y1,x2,y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  i64 dx = std::abs(x1-x2),dy = std::abs(y1-y2);
  i64 d = dx+dy;

  std::unordered_map<i64,int> cnt;
  cnt[d] += 2;

  std::vector<int> x(n),y(n);
  for(int i = 0; i < n; i++){
    std::cin >> x[i] >> y[i];
    i64 disx = std::abs(x1-x[i])+std::abs(x2-x[i]);
    i64 disy = std::abs(y1-y[i])+std::abs(y2-y[i]);
    i64 dis = disx+disy;
    cnt[dis]++;
  }

  for(int i = 0; i < n; i++){
    i64 disx = std::abs(x1-x[i])+std::abs(x2-x[i]);
    i64 disy = std::abs(y1-y[i])+std::abs(y2-y[i]);
    i64 dis = disx+disy;

    if(dis==d){
      std::cout << (dx+1)*(dy+1)-cnt[d] << " \n"[i+1==n];
    }else{
      std::cout << dis*2-cnt[dis] << " \n"[i+1==n];
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}