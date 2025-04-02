#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::string s,t;
    std::cin >> s >> t;

    if(s==t){
        std::cout << "0\n";
        return;
    }

    std::vector<std::vector<int>> adj(26);
    for(int i = 0; i < n; ++i){
        adj[t[i]-'a'].push_back(i);
    }

    std::vector<int> vis(26);
    int ans = 0;
    bool flag = false;
    for(int i = 0; i < 26; ++i){
        std::set<int> set;
        for(auto &j:adj[i]){
            set.insert(s[j]-'a');
        }
        for(auto &j:set){
            if(vis[j]){
                std::cout << "-1\n";
                return;
            }
            vis[j] = true;
        }
        if(set.size()>1){
            flag = true;
        }
        ans += set.size();
    }

    if(!flag){
        std::set<int> a,b;
        for(int i = 0; i < n; ++i){
            a.insert(s[i]-'a');
            b.insert(t[i]-'a');
        }
        if(a==b){
            ++ans;
        }
    }

    std::cout << ans << "\n";
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