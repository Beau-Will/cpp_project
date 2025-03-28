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
	i64 a,b,c,x,y,z;
	std::cin >> a >> b >> c;
	std::cin >> x >> y >> z;
	i64 sum = 0;
	i64 rest = 0;
	i64 t = std::min(a,x);
	a-=t;
	sum+=a/2;
	x-=t;
	rest+=x;
	t = std::min(b,y);
	b-=t;
	sum+=b/2;
	y-=t;
	rest+=y;
	t = std::min(c,z);
	c-=t;
	sum+=c/2;
	z-=t;
	rest+=z;
	if(x==0&&y==0&&z==0){
		std::cout << "Yes\n";
		return;
	}
	std::cout << (sum>=rest?"Yes\n":"No\n");
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