#include <bits/stdc++.h>

using i64 = long long;

template<typename T = i64,bool is_i64 = true>
struct linear_basis{
    std::vector<T> d;
    int len;
    linear_basis(){
        d.assign(is_i64?64:32,T{});
        len = is_i64?62:30;
    }

    template<typename Q>
    void insert(Q x){
        for(int i = len; i >= 0; --i){
            if(x&(1LL<<i)){
                if(d[i]){
                    x ^= d[i];
                }else{
                    d[i] = x;
                    break;
                }
            }
        }
    }
    T find_max(){
        T res {};
        for(int i = len; i >= 0; --i){
            if(res^d[i]>res){
                res ^= d[i];
            }
        }
        return res;
    }
    int count(){
        int res = 0;
        for(int i = len; i >= 0; --i){
            if(d[i]){
                ++res;
            }
        }
        return res;
    }
};