#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::multiset<int> set1;
  std::multiset<int,std::greater<int>> set2;
  set1.insert(-1);
  set1.insert(100002);
  set2.insert(-1);
  set2.insert(100002);

  std::vector<int> cnt(100001);
  int ans = 0;
  for(int i = 0; i < n; i++){
    cnt[a[i]]++;
    set1.insert(a[i]);
    set2.insert(a[i]);

    int t1 = *set1.upper_bound(a[i]);
    int t2 = *set2.upper_bound(a[i]);
    if((t1!=a[i]+1 && t2!=a[i]-1) || 
       (t1==a[i]+1 && cnt[a[i]]>cnt[a[i]+1] && t2!=a[i]-1) || 
       (t1!=a[i]+1 && t2==a[i]-1 && cnt[a[i]]>cnt[a[i]-1]) || 
       (t1==a[i]+1 && cnt[a[i]]>cnt[a[i]+1] && t2==a[i]-1 && cnt[a[i]]>cnt[a[i]-1])){
      ans++;
    }else if(t1==a[i]+1 && cnt[a[i]]<=cnt[a[i]+1] && t2==a[i]-1 && cnt[a[i]]<=cnt[a[i]-1]){
      ans--;
    }

    std::cout << ans << " \n"[i+1==n];
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