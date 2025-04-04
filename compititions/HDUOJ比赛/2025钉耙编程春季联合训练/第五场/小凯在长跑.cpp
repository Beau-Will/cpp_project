#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
    int d,r,x,y;
    std::cin >> d >> r >> x >> y;

    auto dist = [&](int x1,int y1,int x2,int y2){
        return int(std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))+0.5);
    };
    int ans = inf;

    if(y>=d){
        int d1 = dist(x,y,0,d);
        if(d1>=r){
            ans = std::min(ans,d1-r);
        }else{
            ans = std::min(ans,r-d1);
        }
    }else if(y>-d){
        ans = std::min(ans,std::abs(x+r));
        ans = std::min(ans,std::abs(x-r));
    }else{
        int d2 = dist(x,y,0,-d);
        if(d2>=r){
            ans = std::min(ans,d2-r);
        }else{
            ans = std::min(ans,r-d2);
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