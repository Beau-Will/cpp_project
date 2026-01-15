#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7,P2 = 998244353;

void solve(){
  std::string s;

  std::vector<std::string> a;
  while(std::getline(std::cin,s)){
    a.push_back(s);
  }

  int maxLen = std::max_element(a.begin(),a.end(),[&](const auto& s1,const auto& s2){
    return s1.size() < s2.size();
  })->size();

  int t = 0;

  for(int i = 0; i < maxLen+2; i++){
    std::cout << '*';
  }
  std::cout << "\n";

  for(int i = 0; i < a.size(); i++){
    std::cout << '*';

    if(maxLen-a[i].size() & 1){
        for(int j = 0; j < (maxLen-a[i].size()+t)/2; j++){
            std::cout << ' ';
        }
        std::cout << a[i];
        for(int j = 0; j < (maxLen-a[i].size()+(1-t))/2; j++){
            std::cout << ' ';
        }
        t ^= 1;
    }else{
        for(int j = 0; j < (maxLen-a[i].size())/2; j++){
            std::cout << ' ';
        }
        std::cout << a[i];
        for(int j = 0; j < (maxLen-a[i].size())/2; j++){
            std::cout << ' ';
        }
    }

    std::cout << "*\n";
  }

  for(int i = 0; i < maxLen+2; i++){
    std::cout << '*';
  }
  std::cout << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}