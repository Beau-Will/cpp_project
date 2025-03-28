#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()

/*
f(0) = 0;
f(2·x) = f(x);
f(2·x + 1) = f(x)+1

f(0) = 0;

f(1) = 1;

f(2) = 1;
f(3) = 2;

f(4) = 1;

f(5) = 2;
f(6) = 2;
f(7) = 3;

f(8) = 1;

f(9) = 2;
f(10) = 2;
f(11) = 3;
f(12) = 2;

f(11) = ?
11-1 = 10,++cnt;
10/=2 => 5;
5-1 = 4,++cnt;
*/

int n;
std::vector<int> a(N,0);
std::vector<int> cal(N,0);
std::vector<int> cnt(N,0);
std::vector<int> fac;

void pre(){
	int t = 1;
	while(t<=int(1e9)){
		fac.pb(t);
		t*=2;
	}
}

int f(int x){
	int cnt = 0;
	while(*std::lower_bound(all(fac),x)!=x){//O(logn*logn)
		if(x&1){
			x-=1;
			++cnt;
		}else{
			x/=2;
		}
	}
	return ++cnt;
}

void solve(){
	std::cin >> n;
	for(int i = 1;i<=n;++i) std::cin >> a[i];
	// for(int i = 0;i<fac.size();++i) std::cout << fac[i] << '\n';
	// for(int i = 1;i<100;++i){
		// std::cout << f(i) << '\n';
	// }
	for(int i = 1;i<=n;++i){
		cal[i] = f(a[i]);
		++cnt[cal[i]];
	}
	i64 ans = 0;
	for(int i = 1;i<N;++i){
		if(cnt[i]>1){
			ans+=1LL*cnt[i]*(cnt[i]-1)/2;
		}
	}
	std::cout << ans << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	pre();
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}