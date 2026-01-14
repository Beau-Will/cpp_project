#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

struct DSU{
  std::vector<int> f,siz;

  DSU(int n){
    f.resize(n+1);
    std::iota(f.begin(),f.end(),0);

    siz.assign(n+1,1);
  }

  int find(int x){
    if(f[x] != x){
      f[x] = find(f[x]);
    }
    return f[x];
  }

  bool merge(int u,int v){
    int fu = find(u);
    int fv = find(v);

    if(fu == fv){
      return false;
    }

    if(fv > fu){
      std::swap(fu,fv);
    }

    f[fv] = fu;
    siz[fu] += siz[fv];
    return true;
  }
};

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> p(n+1),d(n+1);

  for(int i = 1; i <= n; i++){
    std::cin >> p[i];
  }
  for(int i = 1; i <= n; i++){
    std::cin >> d[i];
  }

  DSU dsu(n);
  for(int i = 1; i <= n; i++){
    if(i-d[i]>=1){
      dsu.merge(i,i-d[i]);
    }
    if(i+d[i]<=n){
      dsu.merge(i,i+d[i]);
    }
  }

  for(int i = 1; i <= n; i++){
    int fi = dsu.find(i);
    int fpi = dsu.find(p[i]);

    if(fi != fpi){
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
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}