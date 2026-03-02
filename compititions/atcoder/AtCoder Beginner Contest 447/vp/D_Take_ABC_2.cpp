#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  std::vector<int> idxA, idxB, idxC;
  idxA.reserve(s.size());
  idxB.reserve(s.size());
  idxC.reserve(s.size());

  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'A'){
      idxA.push_back(i);
    }else if(s[i] == 'B'){
      idxB.push_back(i);
    }else{
      idxC.push_back(i);
    }
  }

  if(idxA.size() == 0 || idxB.size() == 0 || idxC.size() == 0){
    std::cout << "0\n";
    return;
  }

  int ans = 0;
  int idx2 = 0, idx3 = 0;
  int lastBi = 0, lastCi = 0;
  for(int i = 0; i < idxA.size(); i++){
    if(idx2 > idxB.back()){
      break;
    }
    int idx1 = idxA[i];
    
    int tmp = std::upper_bound(idxB.begin() + lastBi, idxB.end(), idx1) - idxB.begin();
    lastBi = tmp + 1;

    if(tmp > idxB.size() - 1){
      break;
    }

    idx2 = idxB[tmp];

    if(idx3 > idxC.back()){
      break;
    }

    tmp = std::upper_bound(idxC.begin() + lastCi, idxC.end(), idx2) - idxC.begin();
    lastCi = tmp + 1;

    if(tmp > idxC.size() - 1){
      break;
    }

    idx3 = idxC[tmp];
    
    ans++;
  }

  std::cout << ans << "\n";
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