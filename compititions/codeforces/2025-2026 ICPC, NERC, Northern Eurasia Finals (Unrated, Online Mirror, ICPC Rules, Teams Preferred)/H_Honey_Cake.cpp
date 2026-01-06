#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int a,b,c,n;
  std::cin >> a >> b >> c >> n;

  std::vector<int> faca,facb,facc;
  for(int i = 1; i <= a/i; i++){
    if(a % i == 0){
      faca.push_back(i);
      if(a/i != i){
        faca.push_back(a/i);
      }
    }
  }
  for(int i = 1; i <= b/i; i++){
    if(b % i == 0){
      facb.push_back(i);
      if(b/i != i){
        facb.push_back(b/i);
      }
    }
  }
  for(int i = 1; i <= c/i; i++){
    if(c % i == 0){
      facc.push_back(i);
      if(c/i != i){
        facc.push_back(c/i);
      }
    }
  }

  std::sort(faca.begin(),faca.end());
  std::sort(facb.begin(),facb.end());
  std::sort(facc.begin(),facc.end());

  for(int i = 0; i < faca.size(); i++){
    int cnt1 = a/faca[i];
    for(int j = 0; j < facb.size(); j++){
      int cnt2 = b/facb[j];
      if(n % (cnt1*cnt2) != 0){
        continue;
      }
      
      int cnt3 = n/(cnt1*cnt2);
      if(c % cnt3 != 0){
        continue;
      }

      std::cout << cnt1-1 << " " << cnt2-1 << " " << cnt3-1 << "\n";
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
  // std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}