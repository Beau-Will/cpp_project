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
	
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	
	bool ismirror = false;
	std::vector<int> ans;
	
	auto dfs = [&](auto &&self,int l,int r) ->void {
		if(l>r){
			return;
		}
		int i = l+1,j = r;
		if(!ismirror){
			while(i<=r&&a[i]<a[l]){
				++i;
			}
			while(j>l&&a[j]>=a[l]){
				--j;
			}
		}else{
			while(i<=r&&a[i]>=a[l]){
				++i;
			}
			while(j>l&&a[j]<a[l]){
				--j;
			}
		}
		
		if(i-j!=1){
			return;
		}
		
		self(self,l+1,j);
		self(self,i,r);
		
		ans.push_back(a[l]);
	};
	
	dfs(dfs,1,n);
	
	if(ans.size()!=n){
		ismirror = true;
		ans.clear();
		dfs(dfs,1,n);
	}
	
	if(ans.size()!=n){
		std::cout << "NO\n";
		return;
	}
	
	std::cout << "YES\n";
	for(int i = 0; i < ans.size(); ++i){
		std::cout << ans[i] << " \n"[i+1==ans.size()];
	}
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
