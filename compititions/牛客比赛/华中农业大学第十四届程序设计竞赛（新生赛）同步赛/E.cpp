// Problem: 烤馍片
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95480/E
// Memory Limit: 2048 MB
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

int n,m;
std::vector<int> a(N);
std::vector<char> s(N);
std::string t;

void solve(){
	std::cin >> n;
	for(int i = 1;i<=n;++i){
		std::cin >> a[i] >> s[i];
	}
	std::cin >> m >> t;
	i64 ans = 0;
	if(m==1){
		for(int i = 1;i<=n;++i){
			if(t[0]==s[i]){
				ans+=a[i];
			}
		}
	}else{
		if(t[0]==t[1]){
			for(int i = 1;i<=n;++i){
				if(i>1&&t[0]==s[i-1]&&t[0]==s[i]) ++ans;
				if(t[0]==s[i]){
					ans+=a[i]-1;
				}
			}
		}else{
			for(int i = 2;i<=n;++i){
				if(t[0]==s[i-1]&&t[1]==s[i]) ++ans;
			}
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