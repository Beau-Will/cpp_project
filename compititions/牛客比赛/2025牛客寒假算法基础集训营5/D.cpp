// Problem: 小L的字符串翻转
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/D
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	std::string s;std::cin >> s;
	s = " "+s;
	
	std::vector<int> pre0(n+5),pre1(n+5);
	
	for(int i = 1;i<=n;++i){
		pre0[i] = pre0[i-1]+(s[i]=='0'?1:0);
		pre1[i] = pre1[i-1]+(s[i]=='1'?1:0);
	}
	
	int ans = 0;
	for(int i = 1;i<=n;++i){
		int t = 1;
		for(int j = 1;j<=n;j+=i){
			//[j,j+i-1]
			int cnt0 = pre0[std::min(n,j+i-1)]-pre0[j-1];
			int cnt1 = pre1[std::min(n,j+i-1)]-pre1[j-1];
			if(cnt0==0||cnt1==0){
				continue;
			}else{
				++t;
			}
		}
		ans ^= t;
	}
	std::cout << ans << "\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}