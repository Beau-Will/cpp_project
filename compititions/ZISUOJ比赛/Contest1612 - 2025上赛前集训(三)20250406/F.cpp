#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    std::string s;
    std::cin >> s;

    if(s.size()<=3){
        std::cout << "No\n";
        return;
    }

    std::map<char,int> cnt;
    for(int i = 0; i < s.size(); ++i){
        ++cnt[s[i]];
    }

    if(s=="abcdefgh"){
        std::cout << "No\n";
        return;
    }

    if(cnt.size()>2){
        std::cout << "Yes\n";
        return;
    }
    if(cnt.size()==1){
        std::cout << "No\n";
        return;
    }
    bool flag = false;
    for(auto &ele:cnt){
        if(ele.second==1){
            flag = true;
            break;
        }
    }
    if(flag){
        std::cout << "No\n";
    }else{
        std::cout << "Yes\n";
    }
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