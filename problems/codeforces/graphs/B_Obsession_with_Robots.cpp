#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  int x = 0,y = 0;
  auto dist = std::vector(202,std::vector<int>(202,inf1));
  auto vis = std::vector(202,std::vector<bool>(202,false));

  dist[x+100][y+100] = 0;
  vis[x+100][y+100] = true;

  std::unordered_map<char,int> dx = {{'L',-1},{'R',1},{'U',0},{'D',0}};
  std::unordered_map<char,int> dy = {{'L',0},{'R',0},{'U',1},{'D',-1}};
  
  for(auto c:s){
    int u = x+dx[c],v = y+dy[c];

    if(vis[u+100][v+100]){
      std::cout << "BUG\n";
      return;
    }

    vis[u+100][v+100] = true;
    dist[u+100][v+100] = dist[x+100][y+100]+1;
    x = u;
    y = v;
  }

  for(int i = -99; i <= 99; i++){
    for(int j = -99; j <= 99; j++){
      for(auto c:"LRUD"){
        int u = i+dx[c],v = j+dy[c];
        if(dist[i+100][j+100]!=inf1 && dist[u+100][v+100]!=inf1 && std::abs(dist[u+100][v+100]-dist[i+100][j+100])>1){
          std::cout << "BUG\n";
          return;
        }
      }
    }
  }

  std::cout << "OK\n";
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