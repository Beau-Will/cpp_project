#include <iostream>
#include <string>

void solve(){
    std::string s;
    std::cin >> s;

    if(s.size()==1){
        std::cout << "Yes\n";
        return;
    }

    std::string t = s;

    for(int i = 0; i+1 < t.size(); i++){
        if(t[i] == '0'){
            t[i] = '1';
            if(t[i+1]=='0'){
                t[i+1] = '1';
            }else{
                t[i+1] = '0';
            }
        }
    }

    if(t.back() != '0'){
        std::cout << "Yes\n";
        return;
    }

    t = s;

    for(int i = 0; i+1 < t.size(); i++){
        if(t[i] == '1'){
            t[i] = '0';
            if(t[i+1] == '1'){
                t[i+1] = '0';
            }else{
                t[i+1] = '1';
            }
        }
    }

    std::cout << (t.back()!='1'?"Yes\n":"No\n");
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