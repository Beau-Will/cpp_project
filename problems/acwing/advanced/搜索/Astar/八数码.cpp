#include <bits/stdc++.h>

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  std::string begin;
  char c;
  for(int i = 0; i < 9; i++){
    std::cin >> c;
    begin += c;
  }
  
  int cnt = 0;
  for(int i = 0; i < 9; i++){
    if(begin[i] == 'x'){
      continue;
    }
    for(int j = i+1; j < 9; j++){
      if(begin[j] == 'x'){
        continue;
      }
      if(begin[i] > begin[j]){
        cnt++;
      }
    }
  }
  
  if(cnt & 1){
    std::cout << "unsolvable\n";
    return 0;
  }
  
  auto f = [&](std::string &state){
    int res = 0;
    for(int i = 0; i < 9; i++){
      if(state[i] == 'x'){
        continue;
      }
      int diff = state[i]-'1';
      res += std::abs(diff/3-i/3)+std::abs(diff%3-i%3);
    }
    return res;
  };
  
  std::string end = "12345678x";
  std::vector<int> dx = {-1,0,1,0};
  std::vector<int> dy = {0,1,0,-1};
  std::vector<std::string> dir = {"u","r","d","l"};
  auto bfs = [&](){
    using PIS = std::pair<int,std::string>;
    std::unordered_map<std::string,int> dist;
    std::unordered_map<std::string,std::pair<std::string,std::string>> prev;
    
    std::priority_queue<PIS,std::vector<PIS>,std::greater<PIS>> heap;
    dist[begin] = 0;
    heap.push({dist[begin]+f(begin),begin});
    
    while(heap.size()){
      auto [w,state] = heap.top();
      heap.pop();
      if(state == end){
        break;
      }
      
      int x,y;
      for(int i = 0; i < 9; i++){
        if(state[i] == 'x'){
          x = i/3,y = i%3;
          break;
        }
      }
      
      int step = dist[state];
      std::string tmp = state;
      for(int i = 0; i < 4; i++){
        int u = x+dx[i],v = y+dy[i];
        if(u<0 || u>=3 || v<0 || v>=3){
          continue;
        }
        std::swap(state[x*3+y],state[u*3+v]);
        if(!dist.count(state) || dist[state] > step+1){
          prev[state] = {tmp,dir[i]};
          dist[state] = step+1;
          heap.push({dist[state]+f(state),state});
        }
        std::swap(state[x*3+y],state[u*3+v]);
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
  
  std::cout << bfs() << "\n";
}