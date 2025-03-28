// Problem: D - Cubes
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
/*
	x^3-y^3=N
	(x-y)*(x^2+x*y+y^2)=N
	
	令d=x-y，则x=y+d
	d*((y+d)^2+(y+d)*y+y^2)=N
	d*(y^2+2*d*y+d^2+y^2+d*y+y^2)=N
	d*(3*y^2+3*d*y+d^2)=N
	3*y^2+3*d*y+d^2-(N/d)=0
	
	令a=3,b=3*d,c=d*d-N/d
*/
void solve(){
	i64 n;std::cin >> n;
	
	for(i64 d = 1;d*d*d<=n;++d){
		if(n%d!=0) continue;
		i64 a=3,b=3*d,c=d*d-n/d;
		
		auto f = [&](i64 a,i64 b,i64 c){
			i64 lo = 1,hi = 1e9;
			while(lo < hi){
				i64 mid = (lo+hi)>>1;
				if(a*mid*mid+b*mid+c>=0){
					hi = mid;
				}else{
					lo = mid+1;
				}
			}
			return a*lo*lo+b*lo+c==0?lo:-1;
		};
		
		i64 y = f(a,b,c);
		if(y!=-1){
			std::cout << y+d << " " << y << "\n";
			return;
		}
	}
	std::cout << -1 << "\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}