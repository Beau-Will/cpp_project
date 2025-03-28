// Problem: 小苯的优雅好序列
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97017/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 5e4+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace
int n,k;
std::vector<int> a(N,0);
void solve(){
	std::cin >> n >> k;
	for(int i = 1;i<=n;++i) std::cin >> a[i];
	if(n==1){
		std::cout << k << ' ' << 1LL*(1+k)*k/2 << '\n';
		return;
	}
	std::sort(a.begin()+1,a.begin()+1+n);
	bool flag = true;
	for(int i = 1;i<=n-1;++i){
		if(a[i]+1==a[i+1]){
			flag = false;
			break;
		}
	}
	if(!flag){
		std::cout << 0 << ' ' << 0 << '\n';
		return;
	}
	
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