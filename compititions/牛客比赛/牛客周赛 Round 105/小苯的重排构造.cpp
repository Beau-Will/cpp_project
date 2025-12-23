#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  if(k<n-1){
    std::cout << "-1\n";
    return;
  }

  std::vector<int> cnt(3);
  for(int i = 0; i < n; ++i){
    ++cnt[a[i]];
  }

  if(k==n-1 && cnt[2]>cnt[1]){
    std::cout << "-1\n";
    return;
  }
  if(k>n-1 && cnt[2]<=k-(n-1)){
    std::cout << "-1\n";
    return;
  }

  std::vector<int> ans;

  for(int i = 0; i <= k-(n-1); ++i){
    ans.push_back(2);
    --cnt[2];
  }

  while(cnt[2]){
    ans.push_back(1);
    ans.push_back(2);
    --cnt[1];
    --cnt[2];
  }

  while(cnt[1]){
    ans.push_back(1);
    --cnt[1];
  }

  for(int i = 0; i < ans.size(); ++i){
    std::cout << ans[i] << " \n"[i+1==ans.size()];
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}