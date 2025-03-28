#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
constexpr int N=1e5+5,M=1e2+5,INF=0x3f3f3f3f,MOD=1e9+7,P=131;
string s;
void solve(){
    cin >> s;
    int cnt_0_before_first_2=0,cnt_1=0;
    if(s.find_first_of('2')==string::npos){
        cout << s << '\n';
        return;
    }
    int idx = s.find_first_of('2');
    for(int i = 0;i<idx;i++){
        if(s[i]=='0') cnt_0_before_first_2++;
    }
    for(int i = 0;i<s.size();i++) if(s[i]=='1') cnt_1++;
    for(int i = 0;i<cnt_0_before_first_2;i++) cout << '0';
    for(int i = 0;i<cnt_1;i++) cout << '1';
    for(int i = idx;i<s.size();i++){
        if(s[i]=='1') continue;
        else cout << (char)s[i];
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int T = 1;
//  cin >> T;
    while(T--) solve();
    return 0;
}