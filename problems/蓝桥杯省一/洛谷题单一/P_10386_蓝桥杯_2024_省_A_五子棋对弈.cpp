#include <bits/stdc++.h>

using i64 = long long;

void solve(){

    std::cout << "3126376\n";

    // int n = 5;

    // int ans = 0;
    // for(int i = 0; i < (1<<(n*n)); ++i){
    //     //1是白棋
    //     if(__builtin_popcount(i)!=(n*n+1)/2){
    //         continue;
    //     }

    //     std::vector g(n,std::vector<int>(n));
    //     for(int j = 0; j < n; ++j){
    //         for(int k = 0; k < n; ++k){
    //             int t = j*n+k;
    //             if(i>>t&1){
    //                 g[j][k] = 1;
    //             }
    //         }
    //     }

    //     bool is_win = false,is_lose = false;
    //     auto check = [&](const std::vector<std::vector<int>> &arr){
    //         for(int i = 0; i < n; ++i){
    //             std::set<int> set;
    //             for(int j = 0; j < n; ++j){
    //                 set.insert(arr[i][j]);
    //             }
    //             if(set.size()==1){
    //                 if(*set.begin()==1){
    //                     is_win = true;
    //                 }else{
    //                     is_lose = true;
    //                 }
    //             }
    //         }

    //         for(int i = 0; i < n; ++i){
    //             std::set<int> set;
    //             for(int j = 0; j < n; ++j){
    //                 set.insert(arr[j][i]);
    //             }
    //             if(set.size()==1){
    //                 if(*set.begin()==1){
    //                     is_win = true;
    //                 }else{
    //                     is_lose = true;
    //                 }
    //             }
    //         }

    //         std::set<int> set;
    //         for(int i = 0; i < n; ++i){
    //             set.insert(arr[i][i]);
    //         }
    //         if(set.size()==1){
    //             if(*set.begin()==1){
    //                 is_win = true;
    //             }else{
    //                 is_lose = true;
    //             }
    //         }

    //         set.clear();
    //         for(int i = 0; i < n; ++i){
    //             set.insert(arr[i][n-1-i]);
    //         }
    //         if(set.size()==1){
    //             if(*set.begin()==1){
    //                 is_win = true;
    //             }else{
    //                 is_lose = true;
    //             }
    //         }
    //     };
    //     check(g);
    //     if(!is_win&&!is_lose){
    //         ++ans;
    //     }
    // }

    // std::cout << ans << "\n";
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