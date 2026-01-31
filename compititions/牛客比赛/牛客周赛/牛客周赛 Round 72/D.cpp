// Problem: 小红的01串（四）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/98256/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

void solve(){
	int n,x,y;std::cin >> n >> x >> y;
	std::string s;std::cin >> s;

	std::vector<int> map0(n,-1),map1(n,-1);
	// int last0 = -1,last1 = -1;
	// for(int i = 0;i<n;++i){
		// if(s[i]=='0'){
			// map0[i] = last0;
			// map1[i] = last1;
			// last0 = i;
		// }else{
			// map0[i] = last0;
			// map1[i] = last1;
			// last1 = i;
		// }
	// }
	for(int i = 0;i<n;++i){
		for(int j = i+1;j<n;++j){
			if(s[j]=='0'){
				map0[i] = j;
				break;
			}
		}
		for(int j = i+1;j<n;++j){
			if(s[j]=='1'){
				map1[i] = j;
				break;
			}
		}
	}
	// for(int i = 0;i<n;++i) std::cout << map0[i] << " \n"[i==n-1];
	// for(int i = 0;i<n;++i) std::cout << map1[i] << " \n"[i==n-1];
	
	std::vector<i64> dp(n,INF);
	dp[0] = 0;
	for(int i = 0;i<n-1;++i){
		if(map0[i]!=-1){
			dp[map0[i]] = std::min(dp[map0[i]],dp[i]+(s[i]=='0'?x:y));
		}
		if(map1[i]!=-1){
			dp[map1[i]] = std::min(dp[map1[i]],dp[i]+(s[i]=='1'?x:y));
		}
	}
	std::cout << dp[n-1] << '\n';
	// for(int i = 1;i<n;++i){
		// if(s[i]==s[i-1]){
			// dp[i] = dp[i-1]+x;
			// continue;
		// }
		// if(s[i]=='1'){
			// if(map0[i]==-1) dp[i]=dp[map1[i]]+x;
			// else if(map1[i]==-1) dp[i]=dp[map0[i]]+y;
			// else dp[i] = std::min(dp[map1[i]]+x,dp[map0[i]]+y);
		// }else{
			// if(map0[i]==-1) dp[i]=dp[map1[i]]+y;
			// else if(map1[i]==-1) dp[i]=dp[map0[i]]+x;
			// else dp[i] = std::min(dp[map1[i]]+y,dp[map0[i]]+x);
			// // dp[i] = std::min(dp[map1[i]]+y,dp[map0[i]]+x);
		// }
	// }
	// for(int i = 0;i<n;++i) std::cout << dp[i] << " \n"[i==n-1];
	// std::cout << dp[n-1] << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}