#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::unordered_map<std::string,int>> cnt(n);
  std::unordered_set<std::string> all;

  for(int i = 0; i < n; i++){
    int len;
    std::cin >> len;

    for(int j = 0; j < len; j++){
      std::string s;
      std::cin >> s;
      cnt[i][s]++;
      all.insert(s);
    }
  }

  std::unordered_map<std::string,std::vector<int>> map;

  for(const auto &s:all){
    for(int i = 0; i < n; i++){
      if(cnt[i][s]){
        map[s].push_back(i+1);
      }
    }
  }

  int m;
  std::cin >> m;

  for(int i = 0; i < m; i++){
    std::string s;
    std::cin >> s;

    for(int j = 0; j < map[s].size(); j++){
      std::cout << map[s][j] << " \n"[j+1==map[s].size()];
    }
  }
}