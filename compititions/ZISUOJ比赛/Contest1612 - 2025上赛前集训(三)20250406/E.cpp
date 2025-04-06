#include <bits/stdc++.h>

using i64 = long long;

struct Node{
    int x,y,w;
};

struct Point{
    int x,y;
};

void solve(){
    int n;
    std::cin >> n;

    std::vector<Node> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i].x >> a[i].y >> a[i].w;
    }

    std::vector<Point> b;
    b.push_back({1,0});
    for(int i = 0; i < n; ++i){
        b.push_back({a[i].x,a[i].y});
        b.push_back({a[i].x+a[i].w,a[i].y});
    }

    std::sort(b.begin(),b.end(),[&](auto &t1,auto &t2){
        if(t1.x!=t2.x){
            return t1.x < t2.x;
        }
        return t1.y > t2.y;
    });

    std::vector<Point> ans1;
    Point last = {0,0};
    for(int i = 0; i < b.size(); ++i){
        if(b[i].x > last.x){
            if(b[i].y < last.y){
                continue;
            }
            ans1.push_back({b[i].x,b[i].y});
        }
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