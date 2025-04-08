#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::iota(a.begin(),a.end(),1);

    std::vector<char> b(n-1,'?');
    std::vector<char> op = {' ','+','-'};
    auto dfs = [&](auto &self,int u)->void{
        if(u==n-1){
            int ans = 0,t = a[0];
            for(int i = 0; i < n-1; ++i){
                if(b[i]=='+'){
                    ans += t;
                    t = a[i+1];
                }else if(b[i]=='-'){
                    ans += t;
                    t = -a[i+1];
                }else if(b[i]==' '){
                    if(t>0){
                        t = t*10+a[i+1];
                    }else{
                        t = t*10-a[i+1];
                    }
                }
            }
            if(t){
                ans += t;
                t = 0;
            }
            if(ans==0){
                for(int i = 0; i < n; ++i){
                    std::cout << a[i];
                    if(i<n-1){
                        std::cout << b[i];
                    }
                }
                std::cout << "\n";
            }
            return;
        }
        for(int i = 0; i < 3; ++i){
            b[u] = op[i];
            self(self,u+1);
            b[u] = '?';
        }
    };

    dfs(dfs,0);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}