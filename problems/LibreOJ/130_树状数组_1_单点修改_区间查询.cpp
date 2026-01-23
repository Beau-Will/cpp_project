#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

template<typename T>
struct Fenwick {
  int n;
  std::vector<T> tr;

  Fenwick(int n) : n(n), tr(n + 1, 0) {}

  int lowbit(int x) {
    return x & -x;
  }

  void modify(int x, T c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
  }

  void modify(int l, int r, T c) {
    modify(l, c);
    if (r + 1 <= n) modify(r + 1, -c);
  }

  T query(int x) {
    T res = T();
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
  }

  T query(int l, int r) {
    return query(r) - query(l - 1);
  }

  int find_first(T sum) {
    int ans = 0;
    T val = 0;
    for (int i = std::__lg(n); i >= 0; i--) {
      if ((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] < sum) {
        ans |= 1 << i;
        val += tr[ans];
      }
    }
    return ans + 1;
  }

  int find_last(T sum) {
    int ans = 0;
    T val = 0;
    for (int i = std::__lg(n); i >= 0; i--) {
      if ((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] <= sum) {
        ans |= 1 << i;
        val += tr[ans];
      }
    }
    return ans;
  }

};

using BIT = Fenwick<i64>;

void solve(){
  int n,q;
  std::cin >> n >> q;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  BIT fen(n+1);
  for(int i = 1; i <= n; i++){
    fen.modify(i,a[i]);
  }

  for(int qi = 0; qi < q; qi++){
    int op;
    std::cin >> op;

    if(op == 1){
      int i,x;
      std::cin >> i >> x;

      fen.modify(i,x);
    }else{
      int l,r;
      std::cin >> l >> r;

      std::cout << fen.query(l,r) << "\n";
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