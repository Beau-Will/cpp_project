#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,m,k;
  std::cin >> n >> m >> k;

  if(m > 1LL*n*(n-1)/2){
    std::cout << "-1\n";
    return;
  }

  if(m < n-1){
    std::cout << "-1\n";
    return;
  }

  std::vector<int> v;
  for(int i = 1; i <= n; i++){
    if(i == k){
      continue;
    }

    v.push_back(i);
    if(v.size() == n-2){
      break;
    }
  }

  int rest = n;
  if(k == n){
    rest = n-1;
  }

  std::set<std::pair<int,int>> ans;

  for(int i = 0; i < v.size(); i++){
    if(i+1 != v.size()){
      ans.insert({v[i],v[i+1]});
    }else{
      if(v.back() < k){
        ans.insert({v.back(),k});
      }else{
        ans.insert({k,v.back()});
      }
    }
  }

  if(rest < k){
    ans.insert({rest,k});
  }else{
    ans.insert({k,rest});
  }

  for(int i = 0; i < v.size(); i++){
    for(int j = i+1; j < v.size(); j++){
      if(ans.count({v[i],v[j]})){
        continue;
      }

      if(ans.size() < m){
        ans.insert({v[i],v[j]});
      }else{
        break;
      }
    }
    if(ans.size() >= m){
      break;
    }
  }

  for(int i = 1; i <= n; i++){
    if(i == k){
      continue;
    }

    if(ans.size() < m){
      if(i < k){
        if(!ans.count({i,k})){
          ans.insert({i,k});
        }
      }else{
        if(!ans.count({k,i})){
          ans.insert({k,i});
        }
      }
    }else{
      break;
    }
  }

  if(ans.size() < m){
    std::cout << "-1\n";
    return;
  }

  for(auto [u,v]:ans){
    std::cout << u << " " << v << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}