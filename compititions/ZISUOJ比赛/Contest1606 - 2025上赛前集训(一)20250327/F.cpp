#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,k;
	std::cin >> n >> k;
	
	std::vector<std::string> a(n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < k; ++j){
			int x;
			std::cin >> x;
			if(x==0){
				a[i] += '0';
			}else if(x==1){
				a[i] += '1';
			}else if(x==2){
				a[i] += '2';
			}
		}
	}
	
	std::map<std::string,int> map;
	for(int i = 0; i < n; ++i){
		++map[a[i]];
	}
	
	std::set<std::array<std::string,3>> set;
	
	int res = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			std::string t;
			for(int l = 0; l < k; ++l){
				if(a[i][l]==a[j][l]){
					t += a[i][l];
				}else{
					t += '0'+'1'+'2'-a[i][l]-a[j][l];
				}
			}
			if(map[t]){
				++res;
				std::array<std::string,3> v {a[i],a[j],t};
				std::sort(v.begin(),v.end());
				set.insert(v);
			}
		}
	}
	
	res /= 3;
	
	// std::cout << res << "\n";
	// for(auto v:set){
		// for(int i = 0; i < 3; ++i){
			// std::cout << v[i] << " \n"[i==2];
		// }
	// }
	
	int ans = 0;
	
	std::map<std::string,int> cnt;
	for(auto &v:set){
		for(int i = 0; i < 3; ++i){
			++cnt[v[i]];
		}
	}
	
	for(auto &v:set){
		for(int i = 0; i < 3; ++i){
			ans += cnt[v[i]]-1;
		}
	}
	
	std::cout << ans/2 << "\n";
	
	// for(auto &v1:set){
		// for(int i = 0; i < 3; ++i){
			// for(auto &v2:set){
				// if(v1==v2){
					// continue;
				// }
				// for(int j = 0; j < 3; ++j){
					// if(v1[i]==v2[j]){
						// ++ans;
					// }
				// }
			// }
		// }
	// }
// 	
	// std::cout << ans/2 << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	// std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}