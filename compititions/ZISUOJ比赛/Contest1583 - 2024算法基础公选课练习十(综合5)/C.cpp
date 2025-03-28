#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 2e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n;
std::vector<int> a(N);
/*
// 4 1 3 2
// 4 2 3 1
1 4 2 3
*/

void solve(){
	std::cin >> n;
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	bool flag = true;
	int max_idx = -1,max = -1;
	for(int i = 1;i<=n;++i){
		if(a[i]>max){
			max = a[i];
			max_idx = i;
		}
	}
	int last = max;
	for(int i = max_idx-1;i>=1;--i){
		if(a[i]>last){
			flag = false;
			break;
		}
		last = a[i];
	}
	if(!flag){
		std::cout << "NO\n";
		return;
	}
	last = max;
	for(int i = max_idx+1;i<=n;++i){
		if(a[i]>last){
			flag = false;
			break;
		}
		last = a[i];
	}
	std::cout << (flag?"YES":"NO") << '\n';
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