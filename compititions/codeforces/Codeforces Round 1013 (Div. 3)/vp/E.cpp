// Problem: E. Interesting Ratio
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/contest/2091/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> minp, primes;
std::vector<int> pre;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}
/*
F(a,b) = a*b/((gcd(a,b))*(gcd(a,b)))
*/
void solve(){
	int n;
	std::cin >> n;
	
	i64 ans = 0;
	for(int i = 1; i <= n/2; ++i){
		ans += pre[n/i];
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	sieve(10000000);
	pre.assign(10000000,0);
	for(int i = 1; i <= 10000000; ++i){
		pre[i] = pre[i-1]+(isprime(i)?1:0);
	}
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}