#include <bits/stdc++.h>

//using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 200005,inf = 1000000000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr int P = 131;

struct Node{
	double cnt,sum;
	double avg;
};

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<Node> a(n);
	
	for(int i = 0; i < n; ++i){
		std::cin >> a[i].cnt;
	}

	for(int i = 0; i < n; ++i){
		std::cin >> a[i].sum;
	}
	
	for(int i = 0; i < n; ++i){
		a[i].avg = a[i].sum/a[i].cnt;
	}
	
	std::sort(a.begin(),a.end(),[&](auto &t1,auto &t2){
		return t1.avg > t2.avg;
	});
	
	int cur = 0;
	double ans = 0;
	for(int i = 0; i < n; ++i){
		if(cur+a[i].cnt<m){
			ans += a[i].sum;
			cur += a[i].cnt;
		}else{
			i64 rest = m-cur;
			ans += 1.0L*a[i].avg*rest;
			break;
		}
	}
	
	std::cout << std::fixed << std::setprecision(2) << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
