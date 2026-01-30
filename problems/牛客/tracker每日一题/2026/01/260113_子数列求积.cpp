#include <iostream>
#include <vector>

using i64 = long long;

constexpr int P = 1E9+7;

int quickPower(int a,int b){
  int res = 1;
  for(; b; a=1LL*a*a%P,b>>=1){
    if(b & 1){
      res = 1LL*res*a%P;
    }
  }
  return res;
}

int inv(int a){
  return quickPower(a,P-2);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,q;
  std::cin >> n >> q;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> pre(n+1);
  pre[0] = 1;
  for(int i = 1; i <= n; i++){
    pre[i] = 1LL*pre[i-1]*a[i]%P;
  }

  for(int qi = 0; qi < q; qi++){
    int l,r;
    std::cin >> l >> r;

    std::cout << 1LL*pre[r]*inv(pre[l-1])%P << " \n"[qi+1==q];
  }
}