// Problem: D - Cubes
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;
 
std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}
 
i128 toi128(const std::string &s) {
    i128 n = 0;
    for (auto c : s) {
        n = n * 10 + (c - '0');
    }
    return n;
}
 
i128 sqrti128(i128 n) {
    i128 lo = 0, hi = 1E16;
    while (lo < hi) {
        i128 x = (lo + hi + 1) / 2;
        if (x * x <= n) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    return lo;
}

i128 gcd(i128 a, i128 b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve(){
	i64 n;std::cin >> n;
	
	//		x^3-y^3=N
	//==>	(y+i)^3-y^3=N
	//==>	枚举i
	
	for(i64 i = 1;i<=1e6;++i){
		i64 low = 1,high = 1e12;
		while(low<high){
			i64 mid = (low+high)>>1;
			i128 B = mid;
			i128 A = mid+i;
			i128 ans = A*A*A-B*B*B;
			if(ans==n){
				std::cout << A << " " << B << "\n";
				return;
			}
			if(ans>=n){
				high = mid;
			}else{
				low = mid+1;
			}
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