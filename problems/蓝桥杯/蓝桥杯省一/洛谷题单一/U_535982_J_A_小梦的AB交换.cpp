#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::string t1,t2;
    for(int i = 0; i < n; ++i){
        t1 += "AB";
        t2 += "BA";
    }
    
    int cnt1 = 0,cnt2 = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i]!=t1[i]){
            ++cnt1;
        }
        if(s[i]!=t2[i]){
            ++cnt2;
        }
    }

    std::cout << std::min(cnt1/2,cnt2/2) << "\n";
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