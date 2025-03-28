#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()

/*
1 => 1
1 2 => 1
1 2 3 => 0
1 2 3 4 => 1
1 2 3 4 5 => 1
1 2 3 4 5 6 => 1
1 2 3 4 5 6 7 => 0
1 2 3 4 5 6 7 8 => 0
1 ... 9 => 1
*/

void solve(){
	int n;std::cin >> n;
	std::cout << (n%4==1||n%4==2?1:0) << '\n';
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