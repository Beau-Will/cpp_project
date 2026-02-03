#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<i64> pow10(17);

// auto ceilD = [](i64 a, i64 b){
i64 ceilD(i64 a, i64 b){
  if(b < 0){
    a *= -1;
    b *= -1;
  }
  if(a >= 0){
    return (a + b - 1) / b;
  }

  return a / b;
};

// auto floorD = [](i64 a, i64 b){
i64 floorD(i64 a, i64 b){
  if(b < 0){
    a *= -1;
    b *= -1;
  }
  if(a >= 0){
    return a / b;
  }
  return (a - b + 1) / b;
};

i64 get(i64 a, i64 b, int k){
  i64 cur = 0;
  for(int i = 0; i < k; i++){
    i64 t = pow10[i];
    i64 t1 = pow10[i + 1];
    int st, ed;
    int step;
    if(i == k - 1 || i == 0){
      st = 9, ed = 1, step = -1;
    }else{
      st = 9, ed = 0, step = -1;
    }

    bool isok = false;
    for(int d = st; (step > 0 ? d <= ed : d >= ed); d += step){
      i64 curd = cur + d * t;
      i64 loy = ceilD(a - curd, t1);
      i64 hiy = floorD(b - curd, t1);
      i64 min = std::max(loy, 0LL);
      i64 max = std::min(hiy, pow10[k - i - 1] - 1);
      if(min <= max){
        cur = curd;
        isok = true;
        break;
      }
    }

    if(!isok){
      return 0LL;
    }
  }

  std::string s = std::to_string(cur);
  std::reverse(s.begin(), s.end());

  return std::stoll(s);
}

void solve(){
  auto getmax = [&](i64 l, i64 r){
    if(l > r){
      return 0LL;
    }

    int maxd = std::to_string(r).size();
    for(int i = maxd; i >= 1; i--){
      i64 a = std::max(l, pow10[i - 1]);
      i64 b = std::min(r, pow10[i] - 1);

      if(a > b){
        continue;
      }
      i64 res = get(a, b, i);
      if(res > 0){
        return res;
      }
    }

    return 0LL;
  };

  i64 l, r;
  std::cin >> l >> r;

  i64 ans = 0;
  i64 tk = 1;
  for(int k = 0; k <= 16; k++){
    if(tk > r){
      break;
    }
    i64 lk = (l + tk - 1) / tk;
    i64 rk = r / tk;

    if(lk <= rk){
      i64 t = getmax(lk, rk);
      if(t > ans){
        ans = t;
      }
    }
    tk *= 10;
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  pow10[0] = 1;
  for(int i = 1; i <= 16; i++){
    pow10[i] = pow10[i - 1] * 10;
  }

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}