#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n),b(m);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    std::cin >> b[i];
  }

  std::priority_queue<int> heapa,heapb;
  for(int i = 0; i < n; i++){
    heapa.push(a[i]);
  }
  for(int i = 0; i < m; i++){
    heapb.push(b[i]);
  }

  int round = 1;
  while(heapa.size() && heapb.size()){
    int t1 = heapa.top();
    int t2 = heapb.top();

    if(round & 1){
      heapb.pop();
      if(t1 < t2){
        heapb.push(t2-t1);
      }
    }else{
      heapa.pop();
      if(t2 < t1){
        heapa.push(t1-t2);
      }
    }
    round++;
  }

  std::cout << (round&1 ? "Bob\n":"Alice\n");
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