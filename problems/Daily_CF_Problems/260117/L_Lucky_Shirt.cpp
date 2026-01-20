#include <iostream>
#include <cmath>
#include <iomanip>

using d128 = long double;

int main(){
    int n,i,k;
    std::cin >> n >> i >> k;

    d128 ans = 0;
    
    ans += std::pow(1.L*(i-1)/n,k)*i;

    for(int j = i; j <= n; j++){
        ans += (std::pow(1.L*j/n,k)-std::pow(1.L*(j-1)/n,k))*(j+1)/2;
    }

    std::cout << std::fixed << std::setprecision(20) << ans << "\n";
}