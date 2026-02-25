#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

constexpr int P = 1E9 + 7;

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
  Matrix res(A.size(), std::vector<int>(A[0].size()));
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k;
  std::cin >> k;

  if(k < 3){
    std::cout << "1\n";
    return 0;
  }

  Matrix A(1, std::vector<int>(2));
  A[0] = {1, 1};

  Matrix B(2, std::vector<int>(2));
  B = {
    {0, 1},
    {1, 1}
  };

  auto Bn_1 = power(B, k - 1);
  auto ans = mul(A, Bn_1);

  std::cout << ans[0][0] << "\n";

  return 0;
}