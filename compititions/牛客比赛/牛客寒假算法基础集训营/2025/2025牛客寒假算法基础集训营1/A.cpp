// Problem: 茕茕孑立之影
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

// std::vector<int> minp, primes;
// 
// void sieve(int n) {
    // minp.assign(n + 1, 0);
    // primes.clear();
//     
    // for (int i = 2; i <= n; i++) {
        // if (minp[i] == 0) {
            // minp[i] = i;
            // primes.push_back(i);
        // }
//         
        // for (auto p : primes) {
            // if (i * p > n) {
                // break;
            // }
            // minp[i * p] = p;
            // if (p == minp[i]) {
                // break;
            // }
        // }
    // }
// }
// 
// bool isprime(int n) {
    // return minp[n] == n;
// }

void solve(){
	int n;std::cin >> n;
	
	bool flag = true;
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
		if(a[i]==1){
			flag = false;
		}
	}
	
	if(!flag){
		std::cout << "-1\n";
		return;
	}
	std::cout << "1000000007\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	// sieve(int(1e6+5));
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}