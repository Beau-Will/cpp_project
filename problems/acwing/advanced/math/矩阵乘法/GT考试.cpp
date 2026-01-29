#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m, K;
  std::cin >> n >> m >> K;

  std::string s;
  std::cin >> s;
  s = " "+s;

  std::vector<int> next(21);
  for(int i = 2, j = 0; i <= m; i++){
    while(j and s[j + 1] != s[i]){
      j = next[j];
    }
    if(s[j + 1] == s[i]){
      j++;
    }
    next[i] = j;
  }

  using Matrix = std::vector<std::vector<int>>;

  Matrix A(21,std::vector<int>(21));
  for(int j = 0; j < m; j++){
    for(char c = '0'; c <= '9'; c++){
      int k = j;
      while(k and s[k + 1] != c){
        k = next[k];
      }
      if(s[k + 1] == c){
        k++;
      }
      if(k < m){
        A[j][k]++;
      }
    }
  }

  auto mul = [&](const Matrix& A, const Matrix& B){
    Matrix res(A.size(),std::vector<int>(B.front().size()));
    for(int i = 0; i < m; i++){
      for(int j = 0; j < m; j++){
        for(int k = 0; k < m; k++){
          res[i][k] = (res[i][k] + (1LL * A[i][j] * B[j][k] % K)) % K;
        }
      }
    }
    return res;
  };

  auto power = [&](Matrix A, int b){
    Matrix res(A.size(),std::vector<int>(A.size()));
    for(int i = 0; i < m; i++){
      res[i][i] = 1;
    }
    for(; b; A = mul(A, A), b >>= 1){
      if(b & 1){
        res = mul(res, A);
      }
    }
    return res;
  };

  Matrix F0(21,std::vector<int>(21));
  F0[0][0] = 1;

  auto Apower = power(A, n);
  auto Fn = mul(F0, Apower);

  int ans = 0;
  for(int i = 0; i < m; i++){
    ans = (ans + Fn[0][i]) % K;
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}