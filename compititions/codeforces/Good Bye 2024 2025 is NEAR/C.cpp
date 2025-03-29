#include <iostream>
#include <vector>

using namespace std;

// 处理单个测试用例
long long processCase(long long n, long long k) {
    long long luckyValue = 0;
    vector<pair<long long, long long>> segments;
    segments.push_back({1, n});
    
    while (!segments.empty()) {
        auto [l, r] = segments.back();
        segments.pop_back();
        
        if (r - l + 1 < k) {
            continue;
        }
        
        long long m = (l + r) / 2;
        if((r-l+1)%2==1) luckyValue += m;
        
        // 添加新的段
        if (m - 1 >= l) {
            segments.push_back({l, m - 1});
        }
        if (m + 1 <= r) {
            segments.push_back({m + 1, r});
        }
    }
    
    return luckyValue;
}

int main() {
    int t;
    cin >> t;
    vector<long long> results(t);
    
    for (int i = 0; i < t; ++i) {
        long long n, k;
        cin >> n >> k;
        results[i] = processCase(n, k);
    }
    
    for (const auto &res : results) {
        cout << res << endl;
    }
    
    return 0;
}
