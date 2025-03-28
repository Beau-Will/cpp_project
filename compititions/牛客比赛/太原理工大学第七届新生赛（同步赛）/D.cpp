// Problem: 快来帮芙芙吧* I
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99073/C
// Memory Limit: 1024 MB
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
	int n,l;std::cin >> n >> l;
	
	std::vector<int> a(n+1);
	std::iota(all(a),0);
	
	int x = 1,y = 1+l;//y=x+l
	i64 ans = 0;
	
	if(l>n){
		x = (n+1)/2;
		y = x+l;
		for(int i = 1;i<=n;++i){
			ans+=std::min(std::abs(a[i]-x),std::abs(a[i]-y));
		}
	}else{
		for(int xi = 1;xi+l<=n;++xi){
			if(std::max(xi-1,n-(xi+l))<=std::max(x-1,n-y)){
				x = xi,y = xi+l;
			}
		}
		
		for(int i = 1;i<=n;++i){
			ans+=std::min(std::abs(a[i]-x),std::abs(a[i]-y));
		}
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