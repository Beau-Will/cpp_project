// Problem: D - Meta-set
// Contest: Virtual Judge - 25上ACM综合训练(一)
// URL: https://vjudge.net/contest/704285#problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,k;
	std::cin >> n >> k;
	
	std::vector<std::string> a(n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < k; ++j){
			int x;std::cin >> x;
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
				std::array<std::string,3> tmp {a[i],a[j],t};
				std::sort(tmp.begin(),tmp.end());
				set.insert(tmp);
			}
		}
	}
	
	std::map<std::string,int> cnt;
	for(auto &[s1,s2,s3]:set){
		++cnt[s1];
		++cnt[s2];
		++cnt[s3];
	}
	
	i64 ans = 0;
	for(auto &[s1,s2,s3]:set){
		ans += cnt[s1]-1;
		ans += cnt[s2]-1;
		ans += cnt[s3]-1;
	}
	
	std::cout << ans/2 << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}