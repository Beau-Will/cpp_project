// Problem: 好伙计猜拳
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95338/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

using pii = std::pair<int,int>;

#define fi first
#define se second

void solve(){
	int n,c1,c2;std::cin >> n >> c1 >> c2;
	
	std::vector<pii> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i].first >> a[i].second;
	}
	i64 ans = 0;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> q;
	for(int i = 0;i<n;++i){
		if(q.empty()){
			q.push(a[i]);
		}else{
			auto t = q.top();
			if(a[i].fi>=t.fi&&a[i].se>=t.se){
				q.push(a[i]);
			}else{
				int t1 = a[i].se,t2 = a[i].fi;
				if(c1<=c2){
					ans += c1;
				}else{
					if(t1>=t.fi&&t2>=t.se){
						q.push({t1,t2});
						ans += c2;
					}else{
						q.pop();
						ans -= c2;
						ans += c1;
						while(!q.empty()){
							t = q.top();
							if(t1>=t.fi&&t2>=t.se){
								break;
							}else{
								q.pop();
								ans -= c2;
								ans += c1;
							}
						}
					}
				}
			}
		}
	}
	
	// i64 ans = 0;
	// std::pair<i64,i64> last = a[0];
	// for(int i = 1;i<n;++i){
		// if(a[i].first>=last.first&&a[i].second>=last.second){
			// last = a[i];
		// }else{
			// int tmp1 = a[i].second,tmp2 = a[i].first;
			// if(c1<=c2){
				// ans += c1;
			// }else{
				// if(tmp1>=last.first&&tmp2>=last.second){
					// ans += c2;
					// last = {tmp1,tmp2};
					// // if(i<n-1&&(tmp1>a[i+1].first||tmp2>a[i+1].second)){
						// // ans += c1;
					// // }else{
						// // ans += c2;
						// // last = {tmp1,tmp2};
					// // }
				// }else{
					// ans += c1;
				// }
			// }
		// }
	// }
	// std::cout << ans << "\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}