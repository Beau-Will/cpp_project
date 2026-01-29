#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,m;
  std::cin >> n >> m;

  if(m == 1){
    std::cout << "0\n";
    return;
  }
  if(n == 1){
    std::cout << "1\n";
    return;
  }

  using Matrix = std::vector<std::vector<int>>;

  //        f(n+1),f(n),S(n),P(n)
  //        P(n) = n * S(n) - T(n)
  Matrix A1 = {{1, 1, 1, 0}};
  Matrix B = {
    {1, 1, 1, 0},
    {1, 0, 0, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1}
  };

  auto mul = [&](const Matrix& A,const Matrix& B){
    Matrix res(A.size(), std::vector<int>(B.front().size()));
    for(int i = 0; i < A.size(); i++){
      for(int j = 0; j < A.front().size(); j++){
        for(int k = 0; k < B.front().size(); k++){
          res[i][k] = (1LL * res[i][k] + (1LL * A[i][j] * B[j][k] % m)) % m;
        }
      }
    }
    return res;
  };

  auto power = [&](Matrix A, int b){
    Matrix res(A.size(), std::vector<int>(A.size()));
    for(int i = 0; i < A.size(); i++){
      res[i][i] = 1;
    }
    for(; b; A = mul(A, A), b >>= 1){
      if(b & 1){
        res = mul(res, A);
      }
    }
    return res;
  };

  auto Bpower = power(B, n - 1);
  auto An = mul(A1, Bpower);

  std::cout << (((1LL * n * An[0][2]) % m) - An[0][3] + m) % m << "\n";
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