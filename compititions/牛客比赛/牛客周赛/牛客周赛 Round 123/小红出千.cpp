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

  std::vector<int> b = a;
  std::sort(b.begin(),b.end());

  auto it = std::unique(b.begin(),b.end());

  int low = -1,high = inf1,max = 0;
  for(int i = 0; i < n; i++){
    int idx2 = std::upper_bound(b.begin(),it,a[i]+n-1)-b.begin();
    int idx1 = std::lower_bound(b.begin(),it,a[i])-b.begin();

    if(idx2-idx1>max){
      low = a[i];
      high = a[i]+n-1;
      max = idx2-idx1;
    }
  }
  for(int i = n-1; i >= 0; i--){
    int idx2 = std::upper_bound(b.begin(),it,a[i])-b.begin();
    int idx1 = std::lower_bound(b.begin(),it,a[i]-n+1)-b.begin();

    if(idx2-idx1>max){
      low = a[i]-n+1;
      high = a[i];
      max = idx2-idx1;
    }
  }

  std::cout << n-max << "\n";

  std::set<int> set;
  for(int i = low; i <= high; i++){
    set.insert(i);
  }
  for(auto i = b.begin(); i != it; i++){
    if(*i>=low && *i<=high){
      set.erase(*i);
    }
  }

  std::vector<bool> isok(n+5);
  for(int i = 0; i < n; i++){
    if(a[i]<low || a[i]>high){
      std::cout << i+1 << " " << *set.begin() << "\n";
      set.erase(set.begin());
    }else{
      if(set.count(a[i])==0 && isok[a[i]-low]){
        std::cout << i+1 << " " << *set.begin() << "\n";
        set.erase(set.begin());
      }
      isok[a[i]-low] = true;
    }
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