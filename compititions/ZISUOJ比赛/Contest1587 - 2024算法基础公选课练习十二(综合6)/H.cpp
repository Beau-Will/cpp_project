#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

void solve(){
	int n;std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	bool flag1 = true;
	for(int i = 1;i<n;++i){
		if(a[i]!=a[0]){
			flag1 = false;
			break;
		}
	}
	if(flag1){
		std::cout << "YES\n";
		std::cout << 1 << ' ' << a[0]-1 << ' ';
		for(int i = 0;i<n-2;++i){
			std::cout << 0 << " \n"[i==n-3];
		}
		return;
	}
	bool flag2 = true;
	for(int i = 2;i<n;++i){
		if(a[i-1]-a[i-2]!=a[i]-a[i-1]){
			flag2 = false;
			break;
		}
	}
	if(flag2){
		std::cout << "YES\n";
		std::cout << a[0] << ' ';
		for(int i = 1;i<n;++i){
			std::cout << a[i]-a[0] << " \n"[i==n-1];
		}
	}else{
		std::cout << "NO\n";
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