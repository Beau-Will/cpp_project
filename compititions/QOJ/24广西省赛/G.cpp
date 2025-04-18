#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

void solve(){
  i64 L,R;
  std::cin >> L >> R;

  i64 ans = 0;
  for(i64 i = 1; i <= 1000000; ++i){
  	if(i!=0){
  		i64 t1 = (L-1)/i;
	    i64 t2 = R/i;
	    if(t2>t1+1){
	      ans = std::max(ans,i);
	    }
	}
    if((R/i)!=0){
    	i64 t3 = (L-1)/(R/i);
	    i64 t4 = R/(R/i);
	    if(t4>t3+1){
	      ans = std::max(ans,R/i);
	    }
	}
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while(t--){
    solve();
  }

  return 0;
}

