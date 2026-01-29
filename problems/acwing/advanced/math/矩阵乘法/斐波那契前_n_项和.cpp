#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/*
A[i]      =   B         *   A[i - 1]

f[i + 1]    1  1  0        f[i]
f[i]  =     1  0  0   *    f[i - 1]
S[i]        1  0  1        S[i - 1]

=>
A[n]      =   B^(n-1)      *   A[1]
*/

using Matrix = std::vector<std::vector<int>>;

int n,m;

Matrix operator * (const Matrix& A, const Matrix& B) {
  Matrix C(A.size(),std::vector<int>(B[0].size()));
  for(int i = 0; i < A.size(); i++){
    for(int j = 0; j < A[0].size(); j++){
      for(int k = 0; k < B[0].size(); k++){
        C[i][k] = (C[i][k] + (1LL * A[i][j] * B[j][k] % m)) % m;
      }
    }
  }
  return C;
}

template<typename T>
Matrix power(Matrix A, T b){
  Matrix res(A.size(), std::vector<T>(A[0].size()));
  for(int i = 0; i < A.size(); i++){
    res[i][i] = 1;
  }
  for(; b; A = A * A, b >>= 1){
    if(b & 1){
      res = res * A;
    }
  }
  return res;
}

void solve(){
  std::cin >> n >> m;

  if(m == 1){
    std::cout << "0\n";
    return;
  }
  if(n == 1){
    std::cout << "1\n";
    return;
  }

  Matrix A1 = {{1}, {1}, {1}};
  Matrix B = {
    {1, 1, 0},
    {1, 0, 0},
    {1, 0, 1}
  };

  Matrix B_power = power(B, n - 1);
  Matrix ans = B_power * A1;

  std::cout << ans[2][0] << "\n";
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