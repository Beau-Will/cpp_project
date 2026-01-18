#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::vector<std::vector<int>> a(4,std::vector<int>(4));

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      std::cin >> a[i][j];
    }
  }

  
  for(int i = 0; i < 4; i++){
    std::vector<int> cnt(5);
    for(int j = 0; j < 4; j++){
      cnt[a[i][j]]++;
    }
    for(int j = 1; j <= 4; j++){
      if(cnt[j] != 1){
        std::cout << "NO\n";
        return;
      }
    }
  }

  for(int i = 0; i < 4; i++){
    std::vector<int> cnt(5);
    for(int j = 0; j < 4; j++){
      cnt[a[j][i]]++;
    }
    for(int j = 1; j <= 4; j++){
      if(cnt[j] != 1){
        std::cout << "NO\n";
        return;
      }
    }
  }

  std::vector<int> cnt(5);
  cnt[a[0][0]]++;
  cnt[a[0][1]]++;
  cnt[a[1][0]]++;
  cnt[a[1][1]]++;

  for(int i = 1; i <= 4; i++){
    if(cnt[i] != 1){
      std::cout << "NO\n";
      return;
    }
  }

  for(int i = 1; i <= 4; i++){
    cnt[i] = 0;
  }
  cnt[a[0][2]]++;
  cnt[a[0][3]]++;
  cnt[a[1][2]]++;
  cnt[a[1][3]]++;

  for(int i = 1; i <= 4; i++){
    if(cnt[i] != 1){
      std::cout << "NO\n";
      return;
    }
  }

  for(int i = 1; i <= 4; i++){
    cnt[i] = 0;
  }
  cnt[a[2][0]]++;
  cnt[a[2][1]]++;
  cnt[a[3][0]]++;
  cnt[a[3][1]]++;

  for(int i = 1; i <= 4; i++){
    if(cnt[i] != 1){
      std::cout << "NO\n";
      return;
    }
  }

  for(int i = 1; i <= 4; i++){
    cnt[i] = 0;
  }
  cnt[a[2][2]]++;
  cnt[a[2][3]]++;
  cnt[a[3][2]]++;
  cnt[a[3][3]]++;

  for(int i = 1; i <= 4; i++){
    if(cnt[i] != 1){
      std::cout << "NO\n";
      return;
    }
  }

  std::cout << "YES\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }
}