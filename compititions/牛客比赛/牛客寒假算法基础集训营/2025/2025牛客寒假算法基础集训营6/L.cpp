// Problem: 变鸡器
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95338/L
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

std::string t = "CHICKEN";

void solve(){
	int n;std::cin >> n;
	
	std::string s;
	std::cin >> s;

	if(s.size()<7){
		std::cout << "NO\n";
		return;
	}
	if(s.size()==7){
		std::cout << (s==t?"YES\n":"NO\n");
		return;
	}
	if((s.size()-7)%2==1){
		std::cout << "NO\n";
		return;
	}
	int idx = 0;
	std::vector<bool> vis(n);
	for(int i = 0;i<n;++i){
		if(idx==7){
			break;
		}
		if(s[i]==t[idx]){
			vis[i] = true;
			++idx;
		}
	}
	if(idx!=7){
		std::cout << "NO\n";
		return;
	}
	
	// std::cout << "---\n";
	std::map<char,int> cnt;
	for(int i = 0;i<n;++i){
		if(!vis[i]){
			++cnt[s[i]];
		}
	}
	std::vector<int> a;
	for(auto &[u,v]:cnt){
		a.push_back(v);
	}
	int max = *std::max_element(a.begin(),a.end());
	int sum = std::accumulate(a.begin(),a.end(),0);
	std::cout << (max<=sum/2?"YES\n":"NO\n");
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