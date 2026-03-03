#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  auto get = [&](int x){
    std::set<int> set;
    for(int i = 2; i <= x / i; i++){
      while(x % i == 0){
        x /= i;
        set.insert(i);
      }
    }
    if(x != 1){
      set.insert(x);
    }
    if(set.size() > 1){
      return -1;
    }
    if(set.size() == 0){
      return 1;
    }
    return *set.begin();
  };

  std::vector<int> b(n);
  for(int i = 0; i < n; i++){
    b[i] = get(a[i]);
  }

  if(std::is_sorted(a.begin(), a.end())){
    std::cout << "Bob\n";
  }else if(std::count(b.begin(), b.end(), -1)){
    std::cout << "Alice\n";
  }else if(std::is_sorted(b.begin(), b.end())){
    std::cout << "Bob\n";
  }else{
    std::cout << "Alice\n";
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