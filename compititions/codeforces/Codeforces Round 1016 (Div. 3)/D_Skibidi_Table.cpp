#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,q;
    std::cin >> n >> q;

    
    while(q--){
        std::string op;
        std::cin >> op;

        i64 x,y;
        if(op=="->"){
            std::cin >> x >> y;

            i64 x0 = 1,y0 = 1;
            i64 cur_n = std::pow(2,n);
            std::vector<i64> sz,pos;
            while(cur_n>=2){
                sz.push_back(cur_n/2);
                if(x>=x0+cur_n/2){
                    if(y>=y0+cur_n/2){
                        x0 += cur_n/2;
                        y0 += cur_n/2;
                        pos.push_back(2);
                    }else{
                        x0 += cur_n/2;
                        pos.push_back(3);
                    }
                }else{
                    if(y>=y0+cur_n/2){
                        y0 += cur_n/2;
                        pos.push_back(4);
                    }else{
                        pos.push_back(1);
                    }
                }
                cur_n /= 2;
            }
            i64 ans = 0;
            for(int i = sz.size()-1; i >= 0; --i){
                i64 cur_sz = sz[i],cur_pos = pos[i];
                // std::cout << "i,sz,pos:" << i << "," << cur_sz << "," << cur_pos << "\n";
                ans += cur_sz*cur_sz*(pos[i]-1);
                if(i==sz.size()-1){
                    ++ans;
                }
            }
            std::cout << ans << "\n";
        }else{
            std::cin >> x;
            
            i64 res_x = 1,res_y = 1;
            std::vector<i64> sz,pos;
            i64 t = std::pow(2,n);
            i64 cur_sz = 2;
            // if(x%4==0){
                while(cur_sz!=t*2){
                    sz.push_back(cur_sz/2);
                    int t1 = x%4;
                    if(t1==0){
                        pos.push_back(4);
                    }else if(t1==1){
                        pos.push_back(1);
                    }else if(t1==2){
                        pos.push_back(2);
                    }else{
                        pos.push_back(3);
                    }
                    cur_sz *= 2;
                    if(t1!=0) x += (4-t1);
                    // x -= t1;
                    x /= 4;
                }
            // }else{
            //     while(cur_sz!=t*2){
            //         sz.push_back(cur_sz/2);
            //         int t1 = x%4;
            //         if(cur_sz==2){
            //             if(t1==0){
            //                 pos.push_back(4);
            //             }else if(t1==1){
            //                 pos.push_back(1);
            //             }else if(t1==2){
            //                 pos.push_back(2);
            //             }else{
            //                 pos.push_back(3);
            //             }
            //         }else{
            //             if(t1==0){
            //                 pos.push_back(1);
            //             }else if(t1==1){
            //                 pos.push_back(2);
            //             }else if(t1==2){
            //                 pos.push_back(3);
            //             }else{
            //                 pos.push_back(4);
            //             }
            //         }
            //         cur_sz *= 2;
            //         x -= t1;
            //         x /= 4;
            //     }
            // }
            

            for(int i = sz.size()-1; i >= 0; --i){
                if(pos[i]==1){
                    continue;
                }else if(pos[i]==2){
                    res_x += sz[i];
                    res_y += sz[i];
                }else if(pos[i]==3){
                    res_x += sz[i];
                }else if(pos[i]==4){
                    res_y += sz[i];
                }
            }

            std::cout << res_x << " " << res_y << "\n";
        }
    }
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