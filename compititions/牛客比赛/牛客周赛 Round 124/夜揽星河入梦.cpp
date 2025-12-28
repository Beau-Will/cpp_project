#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::vector<int> all;
  for(int i = 0; i < n; i++){
    all.push_back(a[i]);
    all.push_back(a[i]+m-1);
    all.push_back(a[i]-m+1);
  }

  std::sort(all.begin(),all.end());
  all.erase(std::unique(all.begin(),all.end()),all.end());

  auto query = [&](int x)->int {
    return std::lower_bound(all.begin(),all.end(),x)-all.begin();
  };

  std::vector<int> cnt(all.size()+1),pre(all.size()+1);
  for(int i = 0; i < n; i++){
    int idx = query(a[i])+1;
    cnt[idx]++;
  }
  for(int i = 1; i < cnt.size(); i++){
    pre[i] = pre[i-1]+cnt[i];
  }

  for(int i = 0; i < n; i++){
    //[a[i],a[i]+m-1]有m-1个
    //[a[i]-m+1,a[i]]有m-1个

    int idx1 = query(a[i])+1;
    int idx2 = query(a[i]+m-1)+1;
    int idx3 = query(a[i]-m+1)+1;

    if(pre[idx2]-pre[idx1-1] == m-1){
      std::cout << "YES\n";
      return;
    }
    if(pre[idx1]-pre[idx3-1] == m-1){
      std::cout << "YES\n";
      return;
    }
  }

  std::cout << "NO\n";
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