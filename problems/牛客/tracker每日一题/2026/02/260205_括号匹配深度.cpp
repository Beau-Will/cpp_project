#include <iostream>
#include <vector>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::cin >> s;

  std::vector<char> stk;
  int ans = 0;
  for(const auto& c : s){
    if(c == '('){
      stk.push_back(c);
      ans = std::max(ans, static_cast<int>(stk.size()));
    }else{
      if(stk.size()){
        stk.pop_back();
      }
    }
  }

  std::cout << ans << "\n";

  return 0;
}