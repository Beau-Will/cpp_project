// Problem: 而后单调
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99458/E
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
	int n,m;std::cin >> n >> m;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	std::set<int> set;
	for(int i = 0;i<n;++i){
		set.insert(a[i]);
	}
	if(set.size()!=n){
		std::cout << "NO\n";
		return;
	}
	
	int cnt = 0;
	int direction = (a[1]>a[0]);//1表示前面单增，0表示前面单减
	for(int i = 2;i<n;++i){
		if((a[i]>a[i-1])!=direction){
			direction = 1-direction;
			++cnt;
		}
	}
	// std::cout << cnt << '\n';

	if(std::is_sorted(all(a))){
		std::cout << "YES\n";
	}else{
		if(n==m){
			std::cout << "NO\n";
			return;
		}
		if(n==m+1){
			std::cout << "YES\n";
			return;
		}
		if(m<=n/2){
            std::cout << "YES\n";
            return;
        }
        if(cnt>=2){
        	std::cout << "NO\n";
        }else{
        	std::cout << "YES\n";
        }
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