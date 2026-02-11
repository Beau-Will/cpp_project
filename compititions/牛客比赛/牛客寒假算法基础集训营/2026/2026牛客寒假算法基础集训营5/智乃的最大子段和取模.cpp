#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/*
正在启动对拍程序...

============================================================
编译 generator.cpp...
编译 std.cpp...
编译 brute.cpp...

============================================================
所有程序编译成功! 开始对拍测试...

测试 #1  [AC]
测试 #2  [AC]
测试 #3  [AC]
测试 #4  [AC]
测试 #5  [AC]
测试 #6  [AC]
测试 #7  [AC]
测试 #8  [AC]
测试 #9  [AC]
测试 #10  [AC]
测试 #11  [AC]
测试 #12  [AC]
测试 #13  [AC]
测试 #14  [AC]
测试 #15  [AC]
测试 #16  [AC]
测试 #17  [AC]
测试 #18  [AC]
测试 #19  [AC]
测试 #20  [AC]
测试 #21  [AC]
测试 #22  [AC]
测试 #23  [AC]
测试 #24  [AC]
测试 #25  [AC]
测试 #26  [AC]
测试 #27  [AC]
测试 #28  [AC]
测试 #29  [AC]
测试 #30  [AC]
测试 #31  [AC]
测试 #32  [AC]
测试 #33  [AC]
测试 #34  [AC]
测试 #35  [AC]
测试 #36  [AC]
测试 #37  [AC]
测试 #38  [AC]
测试 #39  [AC]
测试 #40  [AC]
测试 #41  [AC]
测试 #42  [AC]
测试 #43  [AC]
测试 #44  [AC]
测试 #45  [AC]
测试 #46  [AC]
测试 #47  [AC]
测试 #48  [AC]
测试 #49  [AC]
测试 #50  [WA]

============================================================
发现不一致的输出!

输入数据 (in.txt):
5 41
33 7 39 6 21

标准解法输出 (std_out.txt):
39

暴力解法输出 (brute_out.txt):
40
*/

void solve(){
  int n, p;
  std::cin >> n >> p;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> pre(n + 1);
  for(int i = 0; i < n; i++){
    pre[i + 1] = (pre[i] + a[i]) % p;
  }

  using pll = std::pair<i64, i64>;
  std::set<pll> set;

  set.insert({pre[0], 0});

  int l = 0, r = 0;
  i64 ans = 0;

  for(int i = 1; i <= n; i++){
    auto it1 = set.begin();
    if((*it1).first < pre[i]){
      i64 t = (pre[i] - (*it1).first) % p;
      if(t > ans){
        ans = t;
        l = (*it1).second;
        r = i - 1;
      }
    }

    auto it2 = set.upper_bound({pre[i], n});
    if(it2 != set.end()){
      i64 t = (p + pre[i] - (*it2).first) % p;
      if(t > ans){
        ans = t;
        l = (*it2).second;
        r = i - 1;
      }
    }

    auto it3 = set.lower_bound({pre[i], -1});
    if(it3 != set.end() && (*it3).first == pre[i]){
      if(i < (*it3).second){
        set.erase(it3);
        set.insert({pre[i], i});
      }
    }else{
      set.insert({pre[i], i});
    }
  }

  std::cout << l << " " << r << " " << ans << "\n";
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