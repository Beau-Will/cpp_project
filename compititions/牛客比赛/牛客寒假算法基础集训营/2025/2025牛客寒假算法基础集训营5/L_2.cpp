// Problem: 小L的构造
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/L
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> minp, primes;

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

struct Node{
	int x,y,z;
};

void solve(){
	int n;std::cin >> n;
	
	std::vector<Node> ans;
	int idx = 1;
	for(int i = 2;i+2<=n;i+=4){
		ans.push_back({i,i+2,primes[idx]});
		++idx;
	}
	
	std::cout << ans.size() << "\n";
	for(auto &[x,y,z]:ans){
		std::cout << x << " " << y << " " << z << "\n";
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	sieve(1e6+5);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}