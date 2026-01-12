#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::unordered_map<std::string,std::vector<std::string>> map;

void solve(){
  std::string s;
  int j,k;
  std::cin >> s >> j >> k;

  auto f = [&](const std::string &s1,const std::string &s2){
    int cnt1 = 0,cnt2 = 0;
    std::unordered_map<char,int> cntS1,cntS2;
    for(int i = 0; i < s1.size(); i++){
      if(s1[i] == s2[i]){
        cnt1++;
      }else{
        cntS1[s1[i]]++;
        cntS2[s2[i]]++;
      }
    }
    for(auto [u,v]:cntS1){
      cnt2 += std::min(v,cntS2[u]);
    }

    std::cout << cnt1 << "A" << cnt2 << "B\n";
  };

  f(map[s][j],map[s][k]);
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  map["12"] = {"","12","21"};
  map["123"] = {"","123","132","213","231","312","321"};
  map["1234"] = {"","1234","1243","1324","1342","1423","1432","2134","2143","2314","2341","2413","2431","3124","3142","3214","3241","3412","3421","4123","4132","4213","4231","4312","4321"};

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }
}