// Problem: B. Outstanding Impressionist
// Contest: Codeforces - Good Bye 2024: 2025 is NEAR
// URL: https://codeforces.com/contest/2053/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n;std::cin >> n;
	
	std::vector<int> l(n),r(n);
	for(int i = 0;i<n;++i){
		std::cin >> l[i] >> r[i];
	}

	std::map<int,int> cnt;
	for(int i = 0;i<n;++i){
		if(l[i]==r[i]){
			++cnt[l[i]];
		}
	}
	
	std::string ans;
	for(int i = 0;i<n;++i){
		if(l[i]==r[i]&&cnt[l[i]]>=2){
			ans+='0';
		}else if(l[i]==r[i]&&cnt[l[i]]==1){
			ans+='1';
		}else{
			if(r[i]-l[i]>cnt.size()){
				ans+='1';
			}else{
				bool flag = false;
				for(int j = l[i];j<=r[i];++j){
					if(!cnt[j]){
						ans+='1';
						flag = true;
						break;
					}
				}
				if(!flag){
					ans+='0';
				}
			}
		}
	}
	
	std::cout << ans << '\n';
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