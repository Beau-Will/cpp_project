// Problem: 5. 智商检测【算法赛】
// Contest: Lanqiao - 第 23 场 小白入门赛
// URL: https://www.lanqiao.cn/problems/20055/learning/?contest_id=224
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
constexpr int N = 1e5 + 10;
int n, k;
int a[N];
#define gcd std::__gcd
int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cin >> n >> k;
    for(int i = 1;i<=n;++i){
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(k+1,0));
    // dp[i][j] 从前i个元素中删除j个元素, 得到的最大 gcd
    for(int i = 1;i<=n;++i){
        dp[i][0] = gcd(dp[i-1][0],a[i]); // 初始化
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1; j<=std::min(i,k);++j){
            if(i-1>=j) dp[i][j] = gcd(dp[i-1][j],a[i]);//可以不删, 即选择 a[i]
            dp[i][j] = std::max(dp[i-1][j-1],dp[i][j]);//删去 a[i], 并从前i-1个中选择删除j-1个元素
        }
    }
    std::cout << dp[n][k] << '\n';
    return 0;
}