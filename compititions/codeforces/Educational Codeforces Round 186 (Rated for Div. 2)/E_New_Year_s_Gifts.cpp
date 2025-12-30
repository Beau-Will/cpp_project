#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

struct Node{
  i64 x,y,z,d;
};

void solve(){
  i64 n,m,k;
  std::cin >> n >> m >> k;

  std::vector<i64> a(m);
  for(int i = 0; i < m; i++){
    std::cin >> a[i];
  }

  std::vector<i64> x(n),y(n),z(n);
  for(int i = 0; i < n; i++){
    std::cin >> x[i] >> y[i] >> z[i];
  }

  std::vector<Node> f(n);
  i64 sumy = 0;
  for(int i = 0; i < n; i++){
    f[i].x = x[i];
    f[i].y = y[i];
    f[i].z = z[i];
    f[i].d = z[i]-y[i];
    sumy += y[i];
  }

  if(sumy > k){
    std::cout << 0 << "\n";
    return;
  }

  std::sort(f.begin(),f.end(),[&](auto &t1,auto &t2){
    if(t1.d != t2.d){
      return t1.d > t2.d;
    }
    return t1.x < t2.x;
  });

  std::multiset<i64> set;

  std::sort(a.begin(),a.end());

  for(int i = 0; i < a.size(); i++){
    set.insert(a[i]);
  }

  std::vector<i64> b;
  for(auto [_x,_y,_z,_d]:f){
    auto it = set.lower_bound(_x);
    if(it == set.end()){
      b.push_back(_d);
    }else{
      set.erase(it);
    }
  }

  std::sort(b.begin(),b.end());

  i64 t = k-sumy;
  i64 sumd = 0;
  i64 cnt = 0;

  for(int i = 0; i < b.size(); i++){
    int _d = b[i];
    if(sumd+_d <= t){
      sumd += _d;
      cnt++;
    }else{
      break;
    }
  }

  std::cout << (n-b.size())+cnt << "\n";
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

  return 0;
}