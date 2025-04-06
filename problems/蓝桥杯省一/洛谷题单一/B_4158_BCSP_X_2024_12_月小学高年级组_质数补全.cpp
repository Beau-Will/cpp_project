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

void solve(){
    std::string s;
    std::cin >> s;

    std::vector<int> id;
    for(int i = 0; i < s.size(); ++i){
        if(s[i]=='*'){
            id.push_back(i);
        }
    }
    
    bool flag = false;
    auto dfs = [&](auto &&self,int u) ->void {
        if(u==id.size()){
            int x = std::stoi(s);
            if(isprime(x)){
                std::cout << x << "\n";
                flag = true;
            }
            return;
        }
        for(int i = 0; i < 10; ++i){
            s[id[u]] = '0'+i;
            self(self,u+1);
            if(flag){
                return;
            }
            s[id[u]] = '?';
        }
    };

    dfs(dfs,0);
    if(!flag){
        std::cout << "-1\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    sieve(100000001);

    int t = 1;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}