#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,k;
  std::cin >> n >> k;

  auto bfs = [&](){
    std::unordered_map<int,bool> vis;
    std::unordered_map<int,int> dist;
    std::queue<int> q;
    q.push(n);
    vis[n] = true;
    dist[n] = 0;

    while(q.size()){
      auto t = q.front();
      q.pop();

      if(t == k){
        std::cout << dist[t] << "\n";
        return;
      }

      if(t & 1){
        if(!vis[t/2+1]){
          dist[t/2+1] = dist[t]+1;
          vis[t/2+1] = true;
          q.push(t/2+1);
        }
      }
      if(!vis[t/2]){
        dist[t/2] = dist[t]+1;
        vis[t/2] = true;
        q.push(t/2);
      }
    }

    std::cout << "-1\n";
  };

  bfs();
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }
}