// Problem: 双生双宿之探
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	i64 ans = 0;
	
	for(int i = 0;i<n;++i){
		int j = i+1;
		std::set<int> set;
		int x = a[i],y;
		set.insert(a[i]);
		while(j<n){
			set.insert(a[j]);
			if(set.size()>2){
				break;
			}
			if(a[j]!=x){
				y = a[j];
			}
			++j;
		}
		if(set.size()<2){
			break;
		}
		int sum = 0;
		std::map<int,int> cnt;
		cnt[0] = 1;
		for(int k = i;k<j;++k){
			if(a[k]==x){
				sum += 1;
			}else{
				sum -= 1;
			}
			cnt[sum]++;
		}
		for(auto &[u,v]:cnt){
			ans += 1LL*(v-1)*v/2;
		}
		for(int k = j-1;k>=i;--k){
			if(a[k]!=a[j-1]){
				i = k;
				break;
			}
		}
	}
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