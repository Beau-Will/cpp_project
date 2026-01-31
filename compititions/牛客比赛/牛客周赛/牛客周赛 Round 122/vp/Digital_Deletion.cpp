#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin(),a.end());

  i64 mex = 0;

  for(int i = 0; i < n; i++){
    if(a[i] <= mex+1){
      mex += a[i];
    }else{
      break;
    }
  }

  std::priority_queue<i64> pq;
  i64 sum = 0;
  int idx = 0,cnt = 0;
  
  while(sum < mex){
    while((idx<n) && (a[idx]<=sum+1)){
      pq.push(a[idx++]);
    }

    auto t = pq.top();
    pq.pop();
    sum += t;
    cnt++;
  }

  std::cout << n-cnt << "\n";
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