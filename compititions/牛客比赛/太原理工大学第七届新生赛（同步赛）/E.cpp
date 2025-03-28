// Problem: BF* I
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99073/E
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

std::vector<i64> a(2*N,0);

void solve(){
	int n;std::cin >> n;
	std::string s;std::cin >> s;
	int pos = int(1e6+5);
	i64 sum = 0;
	bool flag = false;
	for(const auto &c:s){
		if(c=='.'){
			flag = true;
			sum+=a[pos];
		}else if(c=='+'){
			++a[pos];
		}else if(c=='-'){
			--a[pos];
		}else if(c=='<'){
			--pos;
		}else if(c=='>'){
			++pos;
		}
		std::cout << (flag?std::to_string(sum):"z") << '\n';
	}
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