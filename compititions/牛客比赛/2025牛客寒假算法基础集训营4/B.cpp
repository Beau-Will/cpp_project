// Problem: Tokitsukaze and Balance String (easy)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95336/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	std::string s;std::cin >> s;
	
	i64 ans = 0;
	
	int cnt = 0;
	for(int i = 0;i<n;++i){
		if(s[i]=='?'){
			++cnt;
		}
	}
	
	std::vector<int> b(cnt);
	auto dfs = [&](auto &&self,int u)->void{
		if(u==cnt){
			std::string tmp = s;
			int cnt2 = 0;
			for(int i = 0;i<tmp.size();++i){
				if(tmp[i]=='?'){
					tmp[i] = (b[cnt2]^48);
					++cnt2;
				}
			}
			int res = 0;//cnt01 = 0,cnt10 = 0;
			// for(int i = 0;i<tmp.size()-1;++i){
				// if(tmp[i]=='0'&&tmp[i+1]=='1'){
					// ++cnt01;
				// }else if(tmp[i]=='1'&&tmp[i+1]=='0'){
					// ++cnt10;
				// }
			// }
			// if(cnt01==cnt10){
				// ++res;
			// }
			for(int i = 0;i<tmp.size();++i){
				char c = tmp[i];
				if(tmp[i]=='0'){
					tmp[i] = '1';
				}else{
					tmp[i] = '0';
				}
				
				int cnt01 = 0,cnt10 = 0;
				for(int j = 0;j<tmp.size()-1;++j){
					if(tmp[j]=='0'&&tmp[j+1]=='1'){
						++cnt01;
					}else if(tmp[j]=='1'&&tmp[j+1]=='0'){
						++cnt10;
					}
				}
				
				if(cnt01==cnt10){
					++res;
				}
				tmp[i] = c;
			}
			
			ans += res;
			
			return;
		}
		
		b[u] = 0;
		self(self,u+1);
		b[u] = 1;
		self(self,u+1);
	};
	
	dfs(dfs,0);
	
	std::cout << ans << "\n";
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