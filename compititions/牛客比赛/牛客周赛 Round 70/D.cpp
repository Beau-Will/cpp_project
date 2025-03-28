// Problem: 小苯的能量项链
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97017/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 5e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

void solve(){
	int n,k;std::cin >> n >> k;
	std::vector<int> a(n+5,0);
	
	for(int i = 1;i<=n;++i) std::cin >> a[i];
	
	if(n<3){
		int ans = 0;
		for(int i = 1;i<=n;++i) ans+=a[i];
		std::cout << ans << '\n';
		return;
	}
	if(k>=n-2){
		std::sort(a.begin()+1,a.begin()+1+n);
		std::cout << a[n-1]+a[n] << '\n';
		return;
	}
	
	std::vector<int> pre(n+5,0);
	std::vector<int> suf(n+5,0);
	for(int i = 1;i<=n;++i) pre[i] = std::max(pre[i-1],a[i]);
	for(int i = n;i>=1;--i) suf[i] = std::max(suf[i+1],a[i]);
	
	// for(int i = 1;i<=n;++i) std::cout << pre[i] << " \n"[i==n];
	// for(int i = 1;i<=n;++i) std::cout << suf[i] << " \n"[i==n];
	
	int ans = a[1]+a[n];
	for(int i = k,j = 0;i>=0;--i,++j){
		// std::cout << "i j:" << i << ' ' << j << '\n';
		ans = std::max(ans,pre[1+i]+suf[n-j]);
		// std::cout << "pre[i+k],suf[n-j]:" << pre[i+k] << ' ' << suf[n-j] << '\n';
		// std::cout << "ans:" << ans << '\n';
	}
	std::cout << ans << '\n';
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