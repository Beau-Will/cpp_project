// Problem: 小L的构造
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/L
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

struct Node{
	int x,y,z;
};

// std::vector<Node> a;
std::vector<int> b;
std::vector<bool> vis(1e6+5);

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

void solve(){
	int n;std::cin >> n;

	std::vector<Node> ans;
	for(int i = 4;i<=n;i+=4){
		ans.push_back({i-2,i-1,i});
	}
	
	int t = ans.size();
	
	for(int i = 0;i<b.size();++i){
		if(b[i]>n||1LL*b[i]*b[i]>n){
			break;
		}
		
		ans.push_back({b[i],b[i]*b[i],-1});
	}
	
	int idx = std::upper_bound(b.begin(),b.end(),n)-b.begin()-1;
	for(int i = t;i<ans.size();++i){
		while(isprime(b[idx])==false){
			--idx;
		}
		ans[i].z = b[idx];
		--idx;
	}
	std::cout << ans.size() << "\n";
	for(int i = 0;i<ans.size();++i){
		std::cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << "\n";
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	for(int i = 2;i<=1e6;i+=4){
		// a.push_back({i,i+1,i+2});
		b.push_back(i+3);
	}
	
	sieve(int(1e6));
	
	// for(int i = 0;i<=100;++i){
		// std::cout << b[i] << "\n";
	// }
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}