#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

i64 n,k;

void solve(){
	std::cin >> n >> k;
	i64 cnt = 0;
	while(n){
		if(n%k==0&&n!=1){
			++cnt;
			n/=k;
		}else if(n==1){
			++cnt;
			n = 0;
		}else{
			cnt+=(n-(n/k)*k);
			n-=(n-(n/k)*k);
		}
	}
	std::cout << cnt << '\n';
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