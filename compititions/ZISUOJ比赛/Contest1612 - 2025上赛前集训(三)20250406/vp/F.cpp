#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

void solve(){
    std::string s;
    std::cin >> s;

    std::map<char,int> cnt;
    for(int i = 0; i < s.size(); ++i){
        ++cnt[s[i]];
    }

    if(cnt.size()<2 || cnt.size()>4){
        std::cout << "No\n";
        return;
    }

    if(cnt.size()==2){
        for(auto &ele:cnt){
            if(ele.second<2){
                std::cout << "No\n";
                return;
            }
        }
    }
    if(cnt.size()==3){
        bool flag = true;
        for(auto &ele:cnt){
            if(ele.second>=2){
                flag = false;
                break;
            }
        }
        if(flag){
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
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