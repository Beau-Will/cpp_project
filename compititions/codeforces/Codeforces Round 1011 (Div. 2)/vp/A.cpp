#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    

    if(k==0){
        std::string t = s;
        std::reverse(t.begin(),t.end());
        auto check = [&](){
            if(s==t){
                return false;
            }
            for(int i = 0; i < s.size(); ++i){
                if(s[i]<t[i]){
                    return true;
                }else if(s[i]>t[i]){
                    return false;
                }
            }
            return false;
        };
        std::cout << (check()?"YES\n":"NO\n");
        return;
    }

    std::set<char> set;
    for(auto &c:s){
        set.insert(c);
    }

    std::cout << (set.size()!=1?"YES\n":"NO\n");
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}