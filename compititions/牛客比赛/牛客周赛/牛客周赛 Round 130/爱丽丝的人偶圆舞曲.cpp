#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  int n = s.size();
  if(n == 1){
    std::cout << "0\n";
    return;
  }

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    a[i] = (s[i] - 'a');
  }

  int ans = n;

  for(int d = 0; d <= 26; d++){
    std::vector<int> dp(26, inf1), ndp(26, inf1);

    for(int c = 0; c < 26; c++){
      dp[c] = (a[0] != c);
    }

    for(int i = 1; i < n; i++){
      std::fill(ndp.begin(), ndp.end(), inf1);

      for(int c = 0; c < 26; c++){
        if(dp[c] == inf1){
          continue;
        }

        int next1 = (c + d) % 26;
        int next2 = (c - d + 26) % 26;

        ndp[next1] = std::min(ndp[next1], dp[c] + (a[i] != next1));
        ndp[next2] = std::min(ndp[next2], dp[c] + (a[i] != next2));
      }

      std::swap(dp, ndp);
    }

    for(int c = 0; c < 26; c++){
      ans = std::min(ans, dp[c]);
    }
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