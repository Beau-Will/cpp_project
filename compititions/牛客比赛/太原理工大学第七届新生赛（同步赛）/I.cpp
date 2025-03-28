// Problem: lucky number
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99073/I
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e6+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

std::vector<int> cnt(N,0);

void preprocess(int n){
	for(int i = 1;i<=n;++i){
		bool flag = true;
		int t = i,last = 10;
		while(t){
			if(t%10<last){
				last = t%10;
			}else{
				flag = false;
				break;
			}
			t/=10;
		}
		cnt[i] = cnt[i-1]+(flag?1:0);
	}
}

void solve(){
	int l,r;std::cin >> l >> r;
	
	preprocess(int(1e6));
	
	std::cout << cnt[r]-cnt[l-1] << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}