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

struct Node{
  i64 t;
  int num;
  bool operator < (const Node &node) const{
    return t > node.t;
  }
};

void solve() {
  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n),b(n),c(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i] >> b[i] >> c[i];
  }

  std::priority_queue<Node> pq;//[离开时间，人数]
  std::vector<i64> ans;//答案可能爆int
  i64 now = 0;
  int cur = 0;

  for(int i = 0; i < n; ++i){
    now = std::max(now,1LL*a[i]);
    while(!pq.empty()){
      auto [leave,num] = pq.top();
      if(leave<=now){
        pq.pop();
        cur -= num;
      }else{
        break;
      }
    }
    if(cur+c[i]<=k){
      cur += c[i];
      pq.push({now+b[i],c[i]});
      ans.push_back(now);
    }else{
      while(!pq.empty()){
        auto [leave,num] = pq.top();
        pq.pop();
        now = leave;
        cur -= num;
        if(cur+c[i]<=k){
          cur += c[i];
          pq.push({now+b[i],c[i]});
          ans.push_back(now);
          break;
        }
      }
    }
  }

  for(int i = 0; i < n; ++i){
    std::cout << ans[i] << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  // std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}