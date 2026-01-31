// Problem: sequence
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99073/J
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
	int n;i64 p;std::cin >> n >> p;
	
	std::vector<i64> a(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	i64 ans = 0;
	for(int i = 1;i<=n;++i){
		i64 &x = a[i];
		for(int j = 1;j<=n;++j){
			if(i==j) continue;
			i64 &y = a[j];
			i64 tmp = x%p*x%p*y%p;
			i64 t1 = 2*tmp%p;
			i64 t2 = -2*tmp;
			while(t2<0){
				t2+=p;
			}
			if(t1==(t2+1)%p) ++ans;
		}
	}
	
	std::cout << ans << '\n';
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