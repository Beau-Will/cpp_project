// Problem: 三角谜题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97443/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e6+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n;
std::vector<i64> l(N),a(N);

void solve(){
	std::cin >> n;
	for(int i = 1;i<=n;++i){
		std::cin >> l[i] >> a[i];
	}
	std::map<i64,i64> map;
	for(int i = 1;i<=n;++i){
		map[l[i]]+=a[i];
	}
	double ans = 0;
	bool flag = false;
	for(auto &[u,v]:map){
		if(v>1) flag=true;
		if(v>=3){
			double t = 1.0*(3*u)/2;
			double square = std::sqrt(t)*std::sqrt(t-u)*std::sqrt(t-u)*std::sqrt(t-u);
			ans = std::max(ans,square);
		}
	}
	if(!flag){
		// std::cout << "flag is false\n";
		std::cout << -1 << '\n';
		return;
	}
	bool flag2 = false;
	for(auto &[u,v]:map){
		if(v>=2){
			for(auto &[u1,v1]:map){
				if(u1>2*u) break;
				else{
					if(u1==u&&v==2){
						continue;
					}
					// std::cout << "*******\n";
					flag2 = true;
					double t = 1.0*(2*u+u1)/2;
					double square = std::sqrt(t)*std::sqrt(t-u)*std::sqrt(t-u)*std::sqrt(t-u1);
					ans = std::max(ans,square);
				}
			}
		}
	}
	if(!flag2){
		// std::cout << "flag2 is false\n";
		std::cout << -1 << '\n';
		return;
	}
	std::cout << std::fixed << std::setprecision(20) << ans << '\n';
	// for(auto it = map.rbegin();it!=map.rend();++it){
		// auto &u = it->first;
		// auto &v = it->second;
		// if(v>1){
			// for(auto it2 = map.rbegin();it2!=map.rend();++it2){
				// if(it2->first>2*u) continue;
				// if(it2->first==u&&it2->second==2) continue;
				// double t = 1.0*(u+u+it2->first)/2;
				// ans = std::sqrt(t)*std::sqrt(t-u)*std::sqrt(t-u)*std::sqrt(t-it2->first);
				// std::cout << std::fixed << std::setprecision(20) << ans << '\n';
				// return;
			// }
		// }
	// }
	// std::cout << -1 << '\n';
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