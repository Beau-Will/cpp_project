#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, x, y;
  std::cin >> n >> x >> y;

  std::vector<int> p(n);
  for(int i = 0; i < n; i++){
    std::cin >> p[i];
  }

  std::vector<int> a, b;
  for(int i = 0; i < n; i++){
    if(i < x || i >= y){
      a.push_back(p[i]);
    }else{
      b.push_back(p[i]);
    }
  }

  if(b.size()){
    std::rotate(b.begin(), std::min_element(b.begin(), b.end()), b.end());
  }
  
  if(a.size() == 0){
    for(int i = 0; i < b.size(); i++){
      std::cout << b[i] << " \n"[i + 1 == b.size()];
    }
    return;
  }

  if(b.size() == 0){
    for(int i = 0; i < a.size(); i++){
      std::cout << a[i] << " \n"[i + 1 == a.size()];
    }
    return;
  }

  int i = 0;
  while(i < a.size() && b.front() > a[i]){
    i++;
  }
  a.insert(a.begin() + i, b.begin(), b.end());

  for(int i = 0; i < a.size(); i++){
    std::cout << a[i] << " \n"[i + 1 == a.size()];
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