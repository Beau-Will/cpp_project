// Problem: 小L的位运算
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;i64 x,y;
	std::cin >> n >> x >> y;
	std::string a,b,c;
	std::cin >> a >> b >> c;
	
	int cnt = 0;
	// std::map<std::tuple<int,int>,int> map;
	std::vector<int> map(4);
	for(int i = 0;i<n;++i){
		int ai = (a[i]^48);
		int bi = (b[i]^48);
		int ci = (c[i]^48);
		if((ai^bi)!=ci){
			++cnt;
			//[0,0]->0
			//[0,1]->1
			//[1,0]->2
			//[1,1]->3
			if(ai==0&&bi==0){
				++map[0];
			}else if(ai==0&&bi==1){
				++map[1];
			}else if(ai==1&&bi==0){
				++map[2];
			}else{
				++map[3];
			}
		}
	}
	
	// for(auto &[u,v]:map){
		// auto [ai,bi] = u;
		// std::cout << "[[ai,bi],v]:" << ai << "," << bi << "," << v << "\n";
	// }
	
	if(x*2<=y){
		std::cout << x*cnt << "\n";
	}else{
// 		if(map.size()==0){
// 			std::cout << 0 << "\n";
// 		}else if(map.size()==1){
// 			std::cout << x*cnt << "\n";
// 		}else{
			int tmp = 0;
			// for(auto &[u1,v1]:map){
				// if(v1==0) continue;
				// for(auto &[u2,v2]:map){
					// if(u1==u2){
						// continue;
					// }
					// if(v2==0) continue;
					// int min = std::min(v1,v2);
					// tmp += min;
					// v1-=min,v2-=min;
				// }
			// }
			std::sort(map.begin(),map.end());
			for(int i = 3;i>=0;--i){
				if(map[i]==0){
					continue;
				}
				for(int j = 0;j<i;++j){
					if(map[j]==0){
						continue;
					}
					
				}
			}
			// for(int i = 0;i<4;++i){
				// for(int j = 3;j>i;--j){
					// int min = std::min(map[i],map[j]);
					// map[i] -= min,map[j] -= min;
					// tmp += min;
				// }
			// }
			int rest = 0;
			for(int i = 0;i<4;++i){
				rest += map[i];
			}
			// for(auto &[u,v]:map){
				// rest += v;
			// }
			// std::cout << "rest:" << rest << "\n";
			std::cout << std::min(y*tmp+x*rest,x*cnt) << "\n";
// 		}
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}