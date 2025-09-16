#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using d128 = long double;

constexpr int inf1 = 1'000'000'000, P = 131;//P = 13331;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr int inf2 = 0x3f3f3f3f;
constexpr i64 inf3 = 1'000'000'000'000'000'000;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define fi first
#define se second

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> even,odd;
  for(int i = 0; i < n; ++i){
    int x;
    std::cin >> x;

    if(x&1){
      odd.push_back(x);
    }else{
      even.push_back(x);
    }
  }

  if(odd.size()==0){
    std::cout << "0\n";
    return;
  }

  i64 ans = 0;
  for(int i = 0; i < even.size(); ++i){
    ans += even[i];
  }

  std::sort(all(odd));

  int cnt = (odd.size()+1)/2;
  for(int i = odd.size()-1; i >= 0; --i){
    ans += odd[i];
    --cnt;
    if(cnt==0){
      break;
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}