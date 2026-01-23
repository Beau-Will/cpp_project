#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9 + 7, P2 = 998'244'353;

/*
下标0base
*/
template <typename T>
struct Fenwick {
  int n;
  std::vector<T> a;

  Fenwick(int n_ = 0){
    init(n_);
  }

  void init(int n_){
    n = n_;
    a.assign(n, T{});
  }

  void add(int x, const T& v){
    for(int i = x + 1; i <= n; i += i & -i){
      a[i - 1] = a[i - 1] + v;
    }
  }

  T sum(int x){
    T ans{};
    for(int i = x; i > 0; i -= i & -i){
      ans = ans + a[i - 1];
    }
    return ans;
  }

  T rangeSum(int l, int r){
    return sum(r) - sum(l);
  }

  int select(const T& k){
    int x = 0;
    T cur{};
    for(int i = 1 << std::__lg(n); i; i /= 2){
      if(x + i <= n && cur + a[x + i - 1] <= k){
        x += i;
        cur = cur + a[x - 1];
      }
    }
    return x;
  }
};

using BIT = Fenwick<i64>;

void solve(){
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  BIT fen1(n), fen2(n);

  for(int i = 0; i < n; i++){
    int di;
    if(i == 0){
      di = a[i];
    }else{
      di = a[i]-a[i-1];
    }
    fen1.add(i,di);
    fen2.add(i,1LL*(i+1)*di);
  }

  for(int qi = 0; qi < q; qi++){
    int op,l,r;
    std::cin >> op >> l >> r;
    l--;
    r--;

    if(op == 1){
      int x;
      std::cin >> x;

      fen1.add(l,x);
      if(r+1 < n) fen1.add(r+1,-x);

      fen2.add(l,1LL*(l+1)*x);
      if(r+1 < n) fen2.add(r+1,-1LL*(r+2)*x);
    }else{
      i64 sumr = fen1.sum(r+1)*(r+2)-fen2.sum(r+1);
      i64 suml = (l>0?fen1.sum(l)*(l+1)-fen2.sum(l):0);

      std::cout << sumr-suml << "\n";
    }
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