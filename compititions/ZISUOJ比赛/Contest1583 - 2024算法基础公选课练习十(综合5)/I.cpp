#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,k,q;
std::vector<int> light(N,0);
std::vector<int> pre(N,0);
void solve(){
	std::cin >> n >> k;
	for(int i = 1;i<=k;++i){
		for(int j = i;j<=n;j+=i){
			light[j] = 1-light[j];
		}
	}
	// for(int i = 1;i<=n;++i){
		// std::cout << light[i] << " \n"[i==n];
	// }
	for(int i = 1;i<=n;++i){
		pre[i] = pre[i-1]+light[i];
	}
	std::cin >> q;
	while(q--){
		int l,r;std::cin >> l >> r;
		if(l>r) std::swap(l,r);
		std::cout << pre[r]-pre[l-1] << '\n';
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