#include <bits/stdc++.h>

using i64 = long long;

template<typename T> 
struct Map{
    std::vector<T> nums;
 
    Map() {}
 
    void add(T x){
        nums.push_back(x);
    }
 
    void build(){
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
    }
 
    int get(T x){
        return int(lower_bound(nums.begin(), nums.end(), x) - nums.begin()) + 1;
    }
 
    T val(int x){
        return nums[x - 1];
    }
 
    int size(){
        return (int)nums.size();
    }
};

int main(){
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	Map<int> mp;
    for(int i = 1; i <= n; i++){
        std::cin >> a[i];
        mp.add(a[i]);
    }
    mp.build();
    for(int i = 1; i <= n; i++){
        a[i] = mp.get(a[i]);
    }
}