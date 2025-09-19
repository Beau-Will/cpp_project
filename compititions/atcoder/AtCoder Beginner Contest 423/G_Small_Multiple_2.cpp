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

std::vector<int> pw(10);

void solve() {
  int K;
  std::string S;
  std::cin >> K >> S;

  int len = S.size();
  int inner = 0;

  std::string ans(len+9,'9');

  for(int i = 0; i < len; ++i){
    inner = (10LL*inner+S[i]-'0')%K;
  }

  auto quick_power = [&](int a,int b,int p){
    int res = 1;
    for(;b;a=1LL*a*a%p,b>>=1){
      if(b&1){
        res = 1LL*res*a%p;
      }
    }
    return res;
  };

  auto itos = [&](int x,int len){
    std::string res;
    for(int i = 1; i <= len; ++i){
      res.push_back('0'+x%10);
      x/=10;
    }
    std::reverse(all(res));
    return res;
  };

  auto work1 = [&](int t_u,int t_l){
    int pw10 = quick_power(10, t_l+len, K);
    for(int u = 0; u < pw[t_u]; ++u){
      int tmp = (1LL*u*pw10%K+1LL*inner*pw[t_l]%K)%K;
      int l = (K-tmp)%K;

      if(l<pw[t_l]){
        ans = std::min(ans,itos(u,t_u)+S+itos(l,t_l));
      }
    }
  };

  auto exgcd = [&](auto &&self,i64 a,i64 b,i64 &x,i64 &y){
    if(!b){
      x = 1,y = 0;
      return a;
    }
    i64 g = self(self,b,a%b,x,y);
    i64 t = x;
    x = y;
    y = t-(a/b)*y;
    return g;
  };

  auto work2 = [&](int t_u,int t_l){
    int pw10 = quick_power(10, t_l+len, K);
    for(int l = 0; l < pw[t_l]; ++l){
      int tmp = (1LL*inner*pw[t_l]%K+l)%K;
      tmp = (K-tmp)%K;

      i64 u = 0,y = 0;
      i64 g = exgcd(exgcd,pw10,K,u,y);

      if(tmp%g){
        continue;
      }

      u *= tmp/g;
      u = (u%(K/g)+(K/g))%(K/g);
      if(u < pw[t_u]){
        ans = min(ans, itos(u, t_u) + S + itos(l, t_l));
      }
    }
  };

  for(int t_lower = 0; t_lower < 10; ++t_lower){
    int t_upper = 9-t_lower;
    if(t_upper <= t_lower){
      work1(t_upper,t_lower);
    }else{
      work2(t_upper,t_lower);
    }
  }

  bool flag = true;
  for(auto c:ans){
    if(flag && c=='0'){
      continue;
    }
    flag = false;
    std::cout << c;
  }

  if(flag){
    std::cout << "0\n";
  }else{
    std::cout << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  pw[0] = 1;
  for(int i = 1; i < 10; ++i){
    pw[i] = pw[i-1]*10;
  }

  int _t = 1;
  std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}