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
	i64 n,k;std::cin >> n >> k;
	//n是可以操作的次数，k是操作结束后的蛋糕的数量
	//让我们求吃蛋糕的次数
	//设吃蛋糕的次数为x，那么放蛋糕的次数就是n-x
	//那么次数蛋糕数量为k=(n-x)*(1+n-x)/2-x
	
	i64 low = 0,high = n;

	while(low<high){
		i64 mid = (low+high)/2;
		i64 cur_k = (n-mid)*(1+n-mid)/2-mid;
		if(cur_k <= k){
			high = mid;
		}else{
			low = mid+1;
		}
	}
	
	std::cout << low << '\n';
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