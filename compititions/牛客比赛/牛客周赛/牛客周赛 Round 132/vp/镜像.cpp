#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int a, b, k;
  std::cin >> a >> b >> k;

  int lena = std::to_string(a).size();
  int lenb = std::to_string(b).size();

  auto reverse = [&](int x){
    std::string s = std::to_string(x);
    std::reverse(s.begin(), s.end());
    return std::stoi(s);
  };

  auto bfs = [&](){
    std::vector<int> vis(std::pow(10, std::max(lena, lenb)) + 1);
    std::vector<int> dist(std::pow(10, std::max(lena, lenb)) + 1, inf1);
    std::queue<int> q;

    vis[a] = true;
    dist[a] = 0;
    q.push(a);

    while(q.size()){
      auto u = q.front();
      q.pop();

      if(u == b){
        return dist[u];
      }

      if(u % 10){
        auto v = reverse(u);
        if(!vis[v]){
          vis[v] = true;
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }

      int v = u + k;
      if(std::to_string(v).size() <= lenb && !vis[v]){
        vis[v] = true;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }

    return -1;
  };

  std::cout << bfs() << "\n";
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