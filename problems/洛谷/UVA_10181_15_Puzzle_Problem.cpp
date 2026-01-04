#include <bits/stdc++.h>

void solve(){
  std::vector<int> v(16);
  std::string begin;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      int x;
      std::cin >> x;
      if(x < 10){
        begin += char('0'+x);
      }else{
        begin += char('a'+x-10);
      }
      v[i*4+j] = x;
    }
  }

  int cnt = 0;
  for(int i = 0; i < 16; i++){
    if(v[i] == 0){
      cnt += 3-i/4;
    }else{
      for(int j = i+1; j < 16; j++){
        if(v[j] && v[i]>v[j]){
          cnt++;
        }
      }
    }
  }

  if(cnt & 1){
    std::cout << "This puzzle is not solvable.\n";
    return;
  }

  std::string end = "123456789abcdef0";

  auto f = [&](std::string &state){
    int res = 0;
    for(int i = 0; i < 16; i++){
      if(state[i] == '0'){
        continue;
      }
      int x;
      if(state[i] >= 'a'){
        x = state[i]-'a'+10;
      }else{
        x = state[i]-'0';
      }
      int tar_row = (x-1)/4;
      int tar_col = (x-1)%4;
      res += std::abs((i/4)-tar_row)+std::abs((i%4)+tar_col);
    }
    return res;
  };

  std::vector<std::string> dir = {"R","L","D","U"};
  std::vector<int> dx = {0,0,1,-1};
  std::vector<int> dy = {1,-1,0,0};

  auto Astar = [&](){
    using PIS = std::pair<int,std::string>;
    std::unordered_map<std::string,int> dist;
    std::unordered_map<std::string,std::pair<std::string,std::string>> prev;
    std::priority_queue<PIS,std::vector<PIS>,std::greater<PIS>> heap;

    dist[begin] = 0;
    heap.push({dist[begin]+f(begin),begin});

    while(heap.size()){
      auto [_,state] = heap.top();
      heap.pop();

      if(state == end){
        break;
      }

      int x,y;
      for(int i = 0; i < 16; i++){
        if(state[i] == '0'){
          x = i/4;
          y = i%4;
          break;
        }
      }

      int step = dist[state];
      std::string tmp = state;
      for(int i = 0; i < 4; i++){
        int u = x+dx[i],v = y+dy[i];
        if(u<0 || u>=4 || v<0 || v>=4){
          continue;
        }
        std::swap(state[x*4+y],state[u*4+v]);
        if(!dist.count(state) || dist[state]>step+1){
          dist[state] = step+1;
          prev[state] = {tmp,dir[i]};
          heap.push({dist[state]+f(state),state});
        }
        std::swap(state[x*4+y],state[u*4+v]);
      }
    }

    std::string ans;
    while(end != begin){
      ans += prev[end].second;
      end = prev[end].first;
    }
    std::reverse(ans.begin(),ans.end());

    return ans;
  };

  std::cout << Astar() << "\n";
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

  return 0;
}