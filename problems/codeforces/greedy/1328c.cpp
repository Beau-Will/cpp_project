#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::string x;
    std::cin >> x;

    std::string a(n,'?'),b(n,'?');
    bool flag = false;
    for(int i = 0; i < n; ++i){
        if(!flag){
            if(x[i]=='0'){
                a[i] = b[i] = '0';
            }else if(x[i]=='1'){
                flag = true;
                a[i] = '1';
                b[i] = '0';
            }else if(x[i]=='2'){
                a[i] = b[i] = '1';
            }
        }else{
            if(x[i]=='0'){
                a[i] = b[i] = '0';
            }else if(x[i]=='1'){
                a[i] = '0';
                b[i] = '1';
            }else if(x[i]=='2'){
                a[i] = '0';
                b[i] = '2';
            }
        }
    }

    std::cout << a << "\n" << b << "\n";
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