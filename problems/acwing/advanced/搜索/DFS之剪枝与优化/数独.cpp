#include <bits/stdc++.h>
#include <bit>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  constexpr int N = 9;

  auto lowbit = [&](int x){
    return x & (-x);
  };

  std::string s;
  while(std::cin >> s){
    if(s == "end"){
      break;
    }

    std::vector<int> row(N),col(N);
    auto cell = std::vector(3,std::vector<int>(3));
    
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        row[i*3+j] = (1<<N)-1;
        col[i*3+j] = (1<<N)-1;
        cell[i][j] = (1<<N)-1;
      }
    }

    auto get = [&](int x,int y){
      return row[x] & col[y] & cell[x/3][y/3];
    };

    auto update = [&](int x,int y,int t,bool isSet){
      if(isSet){
        s[x*N+y] = '1'+t;
      }else{
        s[x*N+y] = '.';
      }

      int dt = 1<<t;
      if(!isSet){
        dt = -dt;
      }

      row[x] -= dt;
      col[y] -= dt;
      cell[x/3][y/3] -= dt;
    };

    int cnt = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(s[i*N+j] != '.'){
          int t = s[i*N+j]-'1';
          update(i,j,t,true);
        }else{
          cnt++;
        }
      }
    }

    auto dfs = [&](auto &&self,int cnt)->bool {
      if(cnt == 0){
        return true;
      }

      int x = -1,y = -1,min = N+1;

      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          if(s[i*N+j] == '.'){
            int state = get(i,j);
            if(std::__popcount(state) < min){
              min = std::__popcount(state);
              x = i;
              y = j;
            }
          }
        }
      }

      int state = get(x,y);
      for(int i = state; i; i -= lowbit(i)){
        int t = std::__countr_zero(i);
        update(x,y,t,true);
        if(self(self,cnt-1)){
          return true;
        }
        update(x,y,t,false);
      }

      return false;
    };

    dfs(dfs,cnt);

    std::cout << s << "\n";
  }
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
  
  return 0;
}