#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector vx(n + 1, std::vector<int>()), vy = vx;
  std::vector vr(n + 1, std::vector<std::pair<int, int>>());
  std::map<std::pair<int, int>, int> id;
  std::vector<std::pair<int, int>> node(m + 3);

  for(int i = 1; i <= m + 2; i++){
    int u, v;
    std::cin >> u >> v;
    if(i > 2 && std::pair(u, v) == node[1]){
      continue;
    }
    if(i > 2 && std::pair(u, v) == node[2]){
      continue;
    }
    vx[u].push_back(v);
    vy[v].push_back(u);
    int r = std::min({u, v, n - u + 1, n - v + 1});
    vr[r].push_back({u, v});
    id[{u, v}] = i;
    node[i] = {u, v};
  }

  int sz = (m + 3) * 3;
  std::vector ve(sz, std::vector<std::pair<int, int>>());
  for(int i = 1; i <= m + 2; i++){
    ve[i * 3].push_back({i * 3 + 1, 1});
    ve[i * 3].push_back({i * 3 + 2, 1});
    ve[i * 3 + 1].push_back({i * 3, 1});
    ve[i * 3 + 1].push_back({i * 3 + 2, 1});
    ve[i * 3 + 2].push_back({i * 3, 1});
    ve[i * 3 + 2].push_back({i * 3 + 1, 1});
  }

  auto get = [&](auto pr){
    auto& [x, y] = pr;
    int l = std::min({x, y, n - x + 1, n - y + 1});
    int ans = 0;
    int r = n - l + 1;
    int len = r - l;
    if(x == l){
      ans += y - l;
    }else if(x == r){
      ans += len * 2 + r - y;
    }else{
      if(y == r){
        ans += len + x - l;
      }else{
        ans += len * 3 + r - x;
      }
    }
    return ans;
  };

  auto link = [&](int x1, int y1, int x2, int y2, int t){
    int u = id[{x1, y1}] * 3 + t;
    int v = id[{x2, y2}] * 3 + t;
    int d = 1E9;
    if(t != 2){
      d = (std::abs(x1 - x2) + std::abs(y1 - y2)) * 2;
    }else{
      auto d0 = get(std::pair(x1, y1));
      auto d1 = get(std::pair(x2, y2));
      int len = std::min({x1, y1, n - x1 + 1, n - y1 + 1});
      int M = (n - len + 1 - len) * 4;
      d = std::min((d1 - d0 + M) % M, (d0 - d1 + M) % M) * 2;
      ve[u].push_back({v, d});
      ve[v].push_back({u, d});
    }
    ve[u].push_back({v, d});
    ve[v].push_back({u, d});
  };

  for(int i = 1; i <= n; i++){
    std::sort(vx[i].begin(), vx[i].end());
    std::sort(vy[i].begin(), vy[i].end());
    std::sort(vr[i].begin(), vr[i].end(), [&](auto& l, auto& r){
      return get(l) < get(r);
    });

    for(int j = 0; j < vx[i].size(); j++){
      if(j > 0){
        link(i, vx[i][j], i, vx[i][j - 1], 0);
      }
      if(j + 1 < vx[i].size()){
        link(i, vx[i][j], i, vx[i][j + 1], 0);
      }
    }
    for(int j = 0; j < vy[i].size(); j++){
      if(j > 0){
        link(vy[i][j], i, vy[i][j - 1], i, 1);
      }
      if(j + 1 < vy[i].size()){
        link(vy[i][j], i, vy[i][j + 1], i, 1);
      }
    }
    if(vr[i].size() > 1){
      auto& v = vr[i];
      int M = v.size();
      for(int j = 0; j < M; j++){
        int f = (j - 1 + M) % M;
        link(v[j].first, v[j].second, v[f].first, v[f].second, 2);
        int b = (j + 1) % M;
        link(v[j].first, v[j].second, v[b].first, v[b].second, 2);
      }
    }
  }

  std::vector<int> dis(sz, inf1), vis(sz), pre(sz);
  dis[3] = 0;
  dis[4] = 0;
  dis[5] = 0;
  std::set<std::pair<int, int>> st;
  st.insert({0, 3});
  st.insert({0, 4});
  st.insert({0, 5});
  while(st.size()){
    auto [d, u] = *st.begin();
    st.erase(st.begin());
    if(vis[u]){
      continue;
    }
    vis[u] = 1;
    for(auto& [v, w] : ve[u]){
      if(dis[v] <= d + w){
        continue;
      }
      dis[v] = d + w;
      st.insert({dis[v], v});
      pre[v] = u;
    }
  }

  std::pair<int, int> res = {inf1, inf1};
  auto& [x, y] = res;
  res = std::min(res, {dis[6], 6});
  res = std::min(res, {dis[7], 7});
  res = std::min(res, {dis[8], 8});
  if(x >= 9E8){
    std::cout << "Impossible!\n";
    return;
  }

  std::cout << x << "\n";
  std::vector<std::array<int, 3>> v;
  for(int i = y; i; i = pre[i]){
    v.push_back({node[i / 3].first, node[i / 3].second, i % 3});
  }
  std::reverse(v.begin(), v.end());
  int fx = 0, fy = 0;
  std::vector<std::pair<int, int>> ans;
  std::string s;
  for(auto& [x, y, t] : v){
    ans.push_back({x, y});
    if(std::pair(x, y) != node[2]){
      s += "RCO"[t];
    }
    while(s.size() >= 2 && s.back() == s[s.size() - 2]){
      s.pop_back();
      ans.pop_back();
    }
    fx = x;
    fy = y;
  }

  std::cout << s.size() << "\n";
  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i].first << " " << ans[i].second << "\n";
    if(i + 1 < ans.size()){
      char ch = '#';
      if(s[i] == 'R'){
        if(ans[i + 1].second > ans[i].second){
          ch = 'E';
        }else{
          ch = 'W';
        }
      }
      if(s[i] == 'C'){
        if(ans[i + 1].first > ans[i].first){
          ch = 'S';
        }else{
          ch = 'N';
        }
      }
      if(s[i] == 'O'){
        int d0 = get(ans[i]);
        int d1 = get(ans[i + 1]);
        int in = std::min({ans[i].first, ans[i].second, n - ans[i].first + 1, n - ans[i].second + 1});
        int len = n - in + 1 - in;
        if(d1 > d0){
          if(d1 - d0 <= len * 2){
            ch = 'C';
          }else{
            ch = 'I';
          }
        }else{
          if(d0 - d1 <= len * 2){
            ch = 'I';
          }else{
            ch = 'C';
          }
        }
      }
      std::cout << ch << "\n";
    }
  }
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