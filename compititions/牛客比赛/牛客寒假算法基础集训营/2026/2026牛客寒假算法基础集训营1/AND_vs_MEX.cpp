#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
  int l, r;
  std::cin >> l >> r;

  std::set<int> set;
  std::vector<int> pre(101);
  pre[0] = l;
  set.insert(l);

  for(int i = l + 1; i <= std::min(l + 100, r); i++){
    pre[i - l] = (pre[i - l - 1] & i);
    set.insert(pre[i - l]);
    set.insert(i);

    for(int j = 0; j < 10; j++){
      set.insert(pre[rnd() % (i - l)] & pre[i - l]);
    }
    for(int j = 0; j < 10; j++){
      set.insert((rnd() % (r - l) + l) & i);
    }
  }

  if(set.size() > 200){
    std::cout << r + 1 << "\n";
  }

  for(int i = 0; i <= r; i++){
    if(!set.count(i)){
      std::cout << i << "\n";
      return;
    }
  }

  std::cout << r + 1 << "\n";
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