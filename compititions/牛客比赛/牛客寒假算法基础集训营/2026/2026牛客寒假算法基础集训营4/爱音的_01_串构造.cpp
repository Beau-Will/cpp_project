#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  i64 a, b;
  std::cin >> a >> b;

  if(a == 0){
    std::cout << std::string(b, '1') << "\n";
    return;
  }

  if(b == 0){
    std::cout << std::string(a, '0') << "\n";
    return;
  }

  auto cal = [&](i64 x, i64 k){
    if(k == 0){
      return 0LL;
    }
    i64 t1 = x / k;
    i64 t2 = x % k;

    return t2 * (t1 + 1) * (t1 + 1) + (k - t2) * t1 * t1;
  };

  i64 c1 = inf2, c2 = inf2, c3 = inf2;
  i64 p1, p2, p3, q1, q2, q3;

  q1 = std::min(a, b);
  p1 = q1;
  c1 = cal(a, p1) + 2 * cal(b, q1);

  if(a >= 2 && b >= 1){
    q2 = std::min(b, a - 1);
    p2 = q2 + 1;
    c2 = cal(a, p2) + 2 * cal(b, q2);
  }

  if(b >= 2 && a >= 1){
    q3 = std::min(b, a + 1);
    p3 = q3 - 1;
    c3 = cal(a, p3) + 2 * cal(b, q3);
  }

  int t;
  i64 p, q;
  if(c1 <= c2 && c1 <= c3){
    t = 1;
    p = p1;
    q = q1;
  }else if(c2 <= c1 && c2 <= c3){
    t = 2;
    p = p2;
    q = q2;
  }else{
    t = 3;
    p = p3;
    q = q3;
  }

  std::vector<int> z(p), o(q);
  i64 t1 = a / p;
  i64 t2 = a % p;
  for(int i = 0; i < p; i++){
    z[i] = t1 + (i < t2);
  }
  i64 t3 = b / q;
  i64 t4 = b % q;
  for(int i = 0; i < q; i++){
    o[i] = t3 + (i < t4);
  }

  std::string ans;
  if(t == 1){
    for(int i = 0; i < p; i++){
      ans += std::string(z[i], '0');
      ans += std::string(o[i], '1');
    }
  }else if(t == 2){
    for(int i = 0; i < q; i++){
      ans += std::string(z[i], '0');
      ans += std::string(o[i], '1');
    }
    ans += std::string(z[q], '0');
  }else{
    for(int i = 0; i < p; i++){
      ans += std::string(o[i], '1');
      ans += std::string(z[i], '0');
    }
    ans += std::string(o[p], '1');
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}