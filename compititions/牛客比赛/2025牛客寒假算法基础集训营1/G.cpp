// Problem: 井然有序之衡
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	i64 n;std::cin >> n;
	
	i64 res = (1+n)*n/2,sum = 0;
	std::vector<i64> a(n);
	
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
		sum += a[i];
	}
	
	if(sum!=res){
		std::cout << -1 << '\n';
		return;
	}
	
	std::sort(a.begin(),a.end());
	
	std::vector<i64> b(n);
	std::iota(b.begin(),b.end(),1);
	i64 ans = 0;
	for(int i = n-1;i>=0;--i){
		if(a[i]<b[i]){
			break;
		}else{
			ans += a[i]-b[i];
		}
	}
	std::cout << ans << '\n';
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