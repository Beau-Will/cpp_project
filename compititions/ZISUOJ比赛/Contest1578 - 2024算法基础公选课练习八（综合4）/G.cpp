#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()

int n;
std::vector<int> a(N,0),b(N,0);

void solve(){
	std::cin >> n;
	for(int i = 1;i<=n;++i) std::cin >> a[i];
	for(int i = 1;i<=n;++i) std::cin >> b[i];
	bool flag = true;
	if(a[1]!=b[1]||a[n]!=b[n]){
		flag = false;
	}
	// for(int i = 2;i<=n-1;++i){
		// if(a[i-1]+a[i+1]==a[i]*2&&a[i]!=b[i]){
			// flag = false;
		// }
	// }
	
	std::cout << (flag?"Yes\n":"No\n");
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