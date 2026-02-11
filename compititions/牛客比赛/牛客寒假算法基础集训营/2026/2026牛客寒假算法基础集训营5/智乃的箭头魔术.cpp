#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

constexpr int map[6][4] = {
  {3, 2, 1, 0},
  {0, 3, 2, 1},
  {1, 0, 3, 2},
  {2, 1, 0, 3},
  {1, 2, 3, 0},
  {3, 0, 1, 2}
};

void solve(){
  std::string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
  int cur = 0;
  for(int i = 0; i < s.size(); i++){;
    cur = map[s[i] - '0'][cur];
    std::cout << cur;
  }
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