#include <bits/stdc++.h>

using i64 = long long;

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> pre(n+1);
  std::partial_sum(a.begin()+1,a.end(),pre.begin()+1);

  std::sort(pre.begin()+1,pre.begin()+n);

  i64 L = 0,R = pre[n];
  if(L > R){
    std::swap(L,R);
  }

  int m = std::lower_bound(pre.begin()+1,pre.begin()+n,L)-pre.begin();

  i64 ans = 0;
  i64 l = L,r = pre[m];
  for(int i = m; i >= 1; i--){
    if(l < r){
      std::swap(l,r);
    }
    ans = std::max(ans,l-pre[i]);
    l = pre[i];
  }

  ans = std::max({ans,l-r,r-l});
  l = pre[m],r = R;
  for(int i = m+1; i < n; i++){
    if(l > r){
      std::swap(l,r);
    }
    ans = std::max(ans,pre[i]-l);
    l = pre[i];
  }

  ans = std::max({ans,l-r,r-l});
  if(m == n){
    ans = std::max(ans,R-pre[n-1]);
  }

  std::cout << ans << "\n";
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