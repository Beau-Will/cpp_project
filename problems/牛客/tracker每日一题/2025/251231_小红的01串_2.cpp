#include <iostream>
#include <string>
#include <algorithm>

void solve(){
    std::string s;
    std::cin >> s;

    int cnt0 = std::count(s.begin(),s.end(),'0');
    int cnt1 = s.size()-cnt0;

    std::cout << (((cnt0&1)&&(cnt1&1))?"No\n":"Yes\n");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T = 1;
    std::cin >> T;
    for(; T--;){
        solve();
    }

    return 0;
}