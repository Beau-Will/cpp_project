#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,m,k;
  std::cin >> n >> m >> k;

  std::string s;
  std::cin >> s;

  std::string t = " "+s;

  std::vector<int> preR(n+1),preY(n+1),preW(n+1);
  for(int i = 1; i <= n; i++){
    preR[i] = preR[i-1]+(t[i]=='r');
    preY[i] = preY[i-1]+(t[i]=='y');
    preW[i] = preW[i-1]+(t[i]=='w');
  }

  auto query = [&](int l,int r,const std::vector<int> &pre){
    return pre[r]-pre[l-1];
  };

  auto check = [&](int len){
    for(int l = 1; l+len-1 <= n; l++){
      int r = l+len-1;

      int cntR = query(l,r,preR);
      int cntY = query(l,r,preY);
      int cntW = query(l,r,preW);

      if(cntR*2+cntY >= k){
        return true;
      }

      if(cntY > cntR){
        std::swap(cntY,cntR);
      }

      cntR += std::min(cntW,m);

      if(cntR*2+cntY >= k){
        return true;
      }
    }

    return false;
  };

  int lo = 1,hi = n;

  while(lo < hi){
    int mid = (lo+hi)/2;

    if(check(mid)){
      hi = mid;
    }else{
      lo = mid+1;
    }
  }

  if(lo != n){
    std::cout << lo << "\n";
    return;
  }

  for(int l = 1; l+n-1 <= n; l++){
    int r = l+n-1;

    int cntR = query(l,r,preR);
    int cntY = query(l,r,preY);
    int cntW = query(l,r,preW);

    if(cntR*2+cntY >= k){
      std::cout << lo << "\n";
      return;
    }

    if(cntY > cntR){
      std::swap(cntY,cntR);
    }

    cntR += std::min(cntW,m);

    if(cntR*2+cntY >= k){
      std::cout << lo << "\n";
      return;
    }
  }

  std::cout << "-1\n";
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
}