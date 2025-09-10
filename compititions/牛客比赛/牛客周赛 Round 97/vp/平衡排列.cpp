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

std::vector<bool> isok(100001);

void solve() {
  i64 n;
  std::cin >> n;

  if(!isok[n]){
    std::cout << "-1\n";
    return;
  }

  i64 sum = (1+n)*n/2;
  i64 half_sum = sum/2;
  int last = n;

  for(int i = n; i >= 1; --i){
    if(half_sum<i){
      break;
    }
    std::cout << i << " ";
    half_sum -= i;
    last = i;
  }

  if(half_sum!=0){
    std::cout << half_sum << " ";
  }

  for(int i = 1; i < last; ++i){
    if(i==half_sum){
      continue;
    }
    std::cout << i << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  i64 s = 0;
  for(int i = 1; i <= 100000; ++i){
    s += i;
    if(s&1){
      isok[i] = false;
    }else{
      isok[i] = true;
    }
  }

  int _t = 1;
  std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}