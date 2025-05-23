// Problem: B. Transfusion
// Contest: Codeforces - Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/contest/2050/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 2e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

std::vector<int> a(N,0);
int n;
/*

*/
void solve(){
	std::cin >> n;
	i64 sum0 = 0,sum1 = 0;
	int cnt0 = 0,cnt1 = 0;
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
		// sum+=a[i];
		if(i&1) sum1+=a[i],++cnt1;
		else sum0+=a[i],++cnt0;
	}
	auto check = [&]()->bool{
		// if(sum%n!=0) return false;
		// return true;
		if(sum0%cnt0!=0) return false;
		if(sum1%cnt1!=0) return false;
		if(sum0/cnt0!=sum1/cnt1) return false;
		return true;
	};
	// auto check = [&]()->bool{
		// for(int i = 2;i<=n-1;++i){
			// if((a[i+1]-a[i-1])%2==1){
				// return false;
			// }
		// }
		// return true;
	// };
	std::cout << (check()?"YES\n":"NO\n");
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