// Problem: 逆转！
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95480/M
// Memory Limit: 2048 MB
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
	int n;std::cin >> n;
	std::vector<int> a(15,0);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	std::vector<int> pre1(15,0),pre0(15,0);
	for(int i = 1;i<=n;++i){
		pre1[i] = pre1[i-1]+(a[i]==1);
		pre0[i] = pre0[i-1]+(a[i]==0);
	}
	int l = 1,r = 1;
	int ans = pre1[n];//Alice发动技能后可以获胜的最大次数
	for(l = 1;l<=n;++l){
		for(r = l;r<=n;++r){
			int len = r-l+1;//区间长度
			ans = std::max(ans,pre1[n]-pre1[r]+pre1[l-1]+pre0[r]-pre0[l-1]);
		}
	}
	// std::cout << ans << '\n';
	if(n&1){
		std::cout << (ans>=(n+1)/2?"Yes":"No") << '\n';
	}else{
		std::cout << (ans>n/2?"Yes":"No") << '\n';
	}
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