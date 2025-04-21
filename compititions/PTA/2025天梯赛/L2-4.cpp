#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1000000000;
constexpr int P = 131,N = 100000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr i64 inf2 = 1000000000000000000;

void solve(){
	int n;
	i64 l,r;
	std::cin >> n >> l >> r;
	
	int cnt = 0;
	std::vector<i64> ans;
	for(i64 i = l; i <= r; ++i){
		std::vector<int> tmp;
		int t = i;
		while(t){
			tmp.push_back(t%10);
			t/=10;
		}
		std::reverse(tmp.begin(),tmp.end());
		int j = 1;
		bool flag = true;
		i64 base = 0;
		for(int i = 0; i < tmp.size(); ++i){
			base = base*10+tmp[i];
			if(base%j!=0){
				flag = false;
				break;
			}
			++j;
		}
		if(flag){
			++cnt;
			ans.push_back(i);
		}
	}
	
//	std::cout << cnt << "\n";
	for(int i = 0; i < ans.size(); ++i){
		std::cout << ans[i] << "\n";
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
