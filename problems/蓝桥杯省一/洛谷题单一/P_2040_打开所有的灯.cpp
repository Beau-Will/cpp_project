#include <bits/stdc++.h>

using i64 = long long;

using Matrix = std::array<std::array<int,3>,3>;

void solve(){
    Matrix a;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            std::cin >> a[i][j];
        }
    }

    std::map<Matrix,bool> vis;
    std::map<Matrix,int> dist;
    auto bfs = [&](){
        std::vector<int> dx = {0,0,-1,1};
        std::vector<int> dy = {-1,1,0,0};
        auto work = [&](const Matrix &matrix,int x,int y){
            Matrix res = matrix;
            res[x][y] ^= 1;
            for(int i = 0; i < 4; ++i){
                int u = x+dx[i],v = y+dy[i];
                if(u<0||u>=3||v<0||v>=3){
                    continue;
                }
                res[u][v] ^= 1;
            }
            return res;
        };
        auto check = [&](const Matrix &matrix){
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if(matrix[i][j]==0){
                        return false;
                    }
                }
            }
            return true;
        };
        std::queue<Matrix> q;
        q.push(a);
        vis[a] = true;
        dist[a] = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(check(t)){
                std::cout << dist[t] << "\n";
                return;
            }
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    auto t1 = work(t,i,j);
                    if(vis[t1]){
                        continue;
                    }
                    vis[t1] = true;
                    dist[t1] = dist[t]+1;
                    q.push(t1);
                }
            }
        }
    };

    bfs();
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