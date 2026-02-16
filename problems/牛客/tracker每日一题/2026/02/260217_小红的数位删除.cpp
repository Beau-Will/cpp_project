#include <iostream>
#include <queue>
#include <array>
#include <map>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b;
  std::cin >> a >> b;

  auto bfs = [&](){
    std::queue<std::array<int, 2>> q;
    std::map<std::array<int, 2>, int> dist;
    q.push({a, b});
    dist[{a, b}] = 0;

    while(q.size()){
      auto [cura, curb] = q.front();
      q.pop();

      if(cura % curb == 0 || curb % cura == 0){
        return dist[{cura, curb}];
      }

      std::string sa = std::to_string(cura);
      if(sa.size() > 1){
        std::string tmpsa;
        for(int i = 0; i < sa.size(); i++){
          tmpsa = sa.substr(0, i) + sa.substr(i + 1);
          int tmpa = std::stoi(tmpsa);
          if(!dist[{tmpa, curb}]){
            q.push({tmpa, curb});
            dist[{tmpa, curb}] = dist[{cura, curb}] + 1;
          }
        }
      }

      std::string sb = std::to_string(curb);
      if(sb.size() > 1){
        std::string tmpsb;
        for(int i = 0; i < sb.size(); i++){
          tmpsb = sb.substr(0, i) + sb.substr(i + 1);
          int tmpb = std::stoi(tmpsb);
          if(!dist[{cura, tmpb}]){
            q.push({cura, tmpb});
            dist[{cura, tmpb}] = dist[{cura, curb}] + 1;
          }
        }
      }
    }

    return -1;
  };
  
  std::cout << bfs() << "\n";

  return 0;
}
