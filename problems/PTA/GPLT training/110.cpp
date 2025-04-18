#include <bits/stdc++.h>

//using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 200005,inf = 1000000000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr int P = 131;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> post(n+1),in(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> post[i];
	}
	for(int i = 1; i <= n; ++i){
		std::cin >> in[i];
	}
	
	std::vector<int> ans(100001,-1);
	
	auto dfs = [&](auto &&self,int u,int l,int r,int idx) ->void {
		if(l>r){
			return;
		}
		int i = l;
		while(i<r&&in[i]!=post[u]){
			++i;
		}
		ans[idx] = post[u];
		self(self,u-(r-i+1),l,i-1,idx*2);
		self(self,u-1,i+1,r,idx*2+1);
	};
	
	dfs(dfs,n,1,n,1);
	
	bool flag = false;
	for(int i = 1; i <= 100000; ++i){
		if(ans[i]!=-1){
			if(flag){
				std::cout << " ";
			}
			std::cout << ans[i];
			if(!flag){
				flag = true;
			}
		}
	}
	std::cout << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
