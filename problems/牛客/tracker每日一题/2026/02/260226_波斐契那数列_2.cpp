#include <iostream>
#include <vector>

using i64 = long long;

constexpr int P = 1E9 + 7;

using Matrix = std::vector<std::vector<int>>;

Matrix mul(const Matrix& A, const Matrix& B){
  Matrix res(A.size(), std::vector<int>(B[0].size()));
  for(int i = 0; i < A.size(); i++){
    for(int j = 0; j < A[0].size(); j++){
      for(int k = 0; k < B[0].size(); k++){
        res[i][k] = (res[i][k] + (1LL * A[i][j] * B[j][k] % P)) % P;
      }
    }
  }
  return res;
}

Matrix power(Matrix A, int b){
  Matrix res(A.size(), std::vector<int>(A.size()));
  for(int i = 0; i < res.size(); i++){
    res[i][i] = 1;
  }
  for(; b; A = mul(A, A), b >>= 1){
    if(b & 1){
      res = mul(res, A);
    }
  }
  return res;
}

/*

          a[i]         a[i + 1]
  B * ( a[i + 1] ) = ( a[i + 2] )
        a[i + 2]       a[i + 3]

           0 1 0
=>  B = (  0 0 1  )
           1 0 1
  
        a[n]                       a[1]
=>  ( a[n + 1] ) = B ^ (n - 1) * ( a[2] )
      a[n + 2]                     a[3]
即  ans = B ^ (n - 1) * A
*/

void solve(){
  int n;
  std::cin >> n;

  if(n < 4){
    std::cout << "1\n";
    return;
  }

  Matrix A(3, std::vector<int>(1));
  A = {
    {1},
    {1},
    {1}
  };
  Matrix B(3, std::vector<int>(3));
  B = {
    {0, 1, 0},
    {0, 0, 1},
    {1, 0, 1}
  };

  auto ans = mul(power(B, n - 1), A);

  std::cout << ans[0][0] << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}
