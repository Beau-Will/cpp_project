#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector g(n+1,std::vector<int>(n+1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            std::cin >> g[i][j];
        }
    }

    auto bfs = [&](int x,int y){
        std::array<int,4> dx = {-1,1,0,0};
        std::array<int,4> dy = {0,0,-1,1};
        std::queue<std::pair<int,int>> q;
        g[x][y] = 2;
        q.push({x,y});
        while(!q.empty()){
            auto [x1,y1] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int x2 = x1+dx[i],y2 = y1+dy[i];
                if(x2<1||x2>n||y2<1||y2>n||g[x2][y2]){
                    continue;
                }
                g[x2][y2] = 2;
                q.push({x2,y2});
            }
        }
    };

    bool flag = false;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(g[i][j]){
                continue;
            }
            int cnt = 0;
            for(int k = j-1; k >= 1; --k){
                if(g[i][k]){
                    ++cnt;
                    break;
                }
            }
            for(int k = j+1; k <= n; ++k){
                if(g[i][k]){
                    ++cnt;
                    break;
                }
            }
            for(int k = i-1; k >= 1; --k){
                if(g[k][j]){
                    ++cnt;
                    break;
                }
            }
            for(int k = i+1; k <= n; ++k){
                if(g[k][j]){
                    ++cnt;
                    break;
                }
            }
            if(cnt==4){
                bfs(i,j);
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            std::cout << g[i][j] << " \n"[j==n];
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