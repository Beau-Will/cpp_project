// Problem: C. Uninteresting Number
// Contest: Codeforces - Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/contest/2050/problem/C
// Memory Limit: 256 MB
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
#define all(v) v.begin(),v.end()
#define push emplace

void solve(){
	std::string num;std::cin >> num;
	i64 sum = 0;
	for(int i = 0;i<num.size();++i){
		sum+=num[i]^48;
	}

	if(sum%9==0){
		std::cout << "YES\n";
		return;
	}

	int cnt2 = 0,cnt3 = 0;
	for(int i = 0;i<num.size();++i){
		if((num[i]^48)==2) ++cnt2;
		else if((num[i]^48)==3) ++cnt3;
	}
	std::vector<std::vector<int>> dp(105,std::vector<int>(105,0));
	int t = sum%9;
	//dp[i][j]表示使用了i个2，j个3可以变成的数
	for(int i = 0;i<=std::min(cnt2,100);++i){
		for(int j = 0;j<=std::min(cnt3,100);++j){
			dp[i][j]=t+i*2+j*6;
			if(dp[i][j]%9==0){
				std::cout << "YES\n";
				return;
			}
		}
	}
	std::cout << "NO\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}