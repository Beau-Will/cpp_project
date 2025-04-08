#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    std::string s;
    std::cin >> s;

    int pos = -1;
    for(int i = s.size()-1; i >= 0; --i){
        if(s[i]!='0'){
            pos = i;
            break;
        }
    }

    int ans = s.size()-1-pos;
    for(int i = 0; i < pos; ++i){
        if(s[i]!='0'){
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
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}