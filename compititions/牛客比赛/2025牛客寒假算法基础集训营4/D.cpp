// Problem: Tokitsukaze and Concatenate‌ Palindrome
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95336/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;std::cin >> n >> m;
	
	std::string a,b;std::cin >> a >> b;
	
	std::map<char,int> mapa,mapb;
	for(int i = 0;i<n;++i){
		++mapa[a[i]];
	}
	for(int i = 0;i<m;++i){
		++mapb[b[i]];
	}
	
	for(auto &[u,v]:mapa){
		if(mapb.find(u)!=mapb.end()){
			int min = std::min(v,mapb[u]);
			v-=min,mapb[u]-=min;
		}
	}
	
	// for(auto [u,v]:mapa){
		// if(v==0){
			// mapa.erase(u);
		// }
	// }
	// for(auto [u,v]:mapb){
		// if(v==0){
			// mapb.erase(u);
		// }
	// }
	
	int cnta = 0,cntb = 0;
	for(auto &[u,v]:mapa){
		cnta+=v;
	}
	for(auto &[u,v]:mapb){
		cntb+=v;
	}
	
	// std::cout << "cnta,cntb:" << cnta << "," << cntb << "\n";
	
	if(cnta==cntb){
		std::cout << cnta << "\n";
	}else if(cnta<cntb){
		// int ans = cnta;
		int cnt2 = 0;
		for(auto &[u,v]:mapb){
			if(v>1){
				int tmp = v/2;
				cnt2+=tmp*2;
				// v-=tmp*2;
			}
		}
		
		// for(auto &[u,v]:mapb){
			// std::cout << "[u,v]:" << u << "," << v << "\n";
		// }
		
		int diff = cntb-cnta;
		if(diff&1){
			--diff;
		}
		// std::cout << "diff:" << diff << "\n";
		
		int min = std::min(diff,cnt2);
		
		// std::cout << "min:" << min << "\n";
		if(min==cnt2){
			for(auto &[u,v]:mapb){
				if(v>1){
					int tmp = v/2;
					// cnt2+=tmp*2;
					v-=tmp*2;
				}
			}
		}else{
			for(auto &[u,v]:mapb){
				if(v>1){
					int tmp = v/2;
					int tmpmin = std::min(tmp*2,min);
					v-=tmpmin;
					min-=tmpmin;
				}
			}
		}
		
		// for(auto [u,v]:mapb){
			// if(v==0){
				// mapb.erase(u);
			// }
		// }
		
		int res = 0;
		for(auto &[u,v]:mapa){
			res += v;
		}
		for(auto &[u,v]:mapb){
			res += v;
		}
		
		std::cout << res/2 << "\n";
	}else{
		int cnt2 = 0;
		for(auto &[u,v]:mapa){
			if(v>1){
				int tmp = v/2;
				cnt2 += tmp*2;
			}
		}
		
		int diff = cnta-cntb;
		if(diff&1){
			--diff;
		}
		
		int min = std::min(diff,cnt2);
		if(min==cnt2){
			for(auto &[u,v]:mapa){
				if(v>1){
					int tmp = v/2;
					v-=tmp*2;
				}
			}
		}else{
			for(auto &[u,v]:mapa){
				if(v>1){
					int tmp = v/2;
					int tmpmin = std::min(min,tmp*2);
					v-=tmpmin;
					min-=tmpmin;
				}
			}
		}
		
		// for(auto [u,v]:mapa){
			// if(v==0){
				// mapa.erase(u);
			// }
		// }
		
		int res = 0;
		for(auto &[u,v]:mapa){
			res += v;
		}
		for(auto &[u,v]:mapb){
			res += v;
		}
		
		std::cout << res/2 << "\n";
	}
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