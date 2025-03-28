#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e5+5;

int a[N];
double b[N];      //a数组减去假设平均值
double sum[N];    //b的前缀和

int n,L;

double judgeAve(int n, double mid, int f){
	
    for(int i = 1;i <= n;i++){
        b[i] = a[i] - mid;
        sum[i] = sum[i - 1] + b[i];
    }
    
    double min_val = 1e6, max_val = -1e6;
    
    for(int i = f;i <= n;i++){
        if(min_val > sum[i - f]) min_val = sum[i - f];
        if(max_val < sum[i]-min_val) max_val = sum[i]-min_val;
    }
    
    return max_val;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    const double eps = 1e-8;
    
    std::cin >> n >> L;
    for(int i = 1;i<=n;i++) std::cin >> a[i];
    
    double l = 1,r = 5e3;
    while(r-l>eps){
        double mid = (r+l)/2;
        if(judgeAve(n,mid,L)>0) l = mid; 
        else r = mid;
    }
    
    std::cout << std::fixed << std::setprecision(6) << l << '\n';
    
    return 0;
}