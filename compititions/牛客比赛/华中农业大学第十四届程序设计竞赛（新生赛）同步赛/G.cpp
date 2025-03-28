// Problem: 爱龙人士
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95480/G
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 3e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,m;
i64 x;
std::vector<i64> a(N),b(N),c(N);
std::vector<i64> pre_a(N,0);

void solve(){
	std::cin >> m >> n;
	for(int i = 1;i<=m;++i){
		std::cin >> a[i];
	}
	for(int i = 1;i<=n;++i){
		std::cin >> b[i];
	}
	for(int i = 1;i<=n;++i){
		std::cin >> c[i];
	}
	std::cin >> x;
	
	std::sort(a.begin()+1,a.begin()+1+m);
	
	for(int i = 1;i<=m;++i){
		pre_a[i] = pre_a[i-1]+a[i];
	}
	
	i64 sum = 0;
	bool flag = true;
	for(int i = 1;i<=n;++i){
		if(c[i]>m){
			flag = false;
			break;
		}
		sum+=a[1]*(b[i]-c[i]);
		sum+=pre_a[c[i]];
	}
	if(!flag){
		std::cout << "No" << '\n';
		return;
	}
	std::cout << (sum<=x?"Yes":"No") << '\n';
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