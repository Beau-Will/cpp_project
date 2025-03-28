#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e5+5;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n,m;
    std::cin >> n >> m;//n个数，m个查询
    //a为原数组，diff为a的差分数组
    std::vector<i64> a(N,0),diff1(N,0),diff2(N,0);
    Fenwick<i64> fenwick1(N),fenwick2(N);
    for(int i = 1;i<=n;++i) {
        std::cin >> a[i];
        diff1[i] = a[i]-a[i-1];
        diff2[i] = i*diff1[i];
    }
    //fenwick1保存diff，fenwick2保存i*diff[i]，用于后续的区间查询的计算
    for(int i = 1;i<=n;++i) {
        fenwick1.add(i-1,diff1[i]);
        fenwick2.add(i-1,diff2[i]);
    }
    while(m--) {
        int op,l,r,x;
        std::cin >> op;
        if(op==1) {//区间修改[l,r]都+d
            std::cin >> l >> r;
            fenwick1.add(l-1,1);
            fenwick2.add(l-1,l);
            fenwick1.add(r,-1);
            fenwick2.add(r,(r+1)*(-1));
        }else {//op==2 查询[l,r]的数字之和
            std::cin >> x;
            int stat = fenwick1.sum(x);
            if(stat==0){
            	std::cout << 0 << '\n';
            	continue;
            }
            i64 pre = fenwick1.sum(x)*(x+1)-fenwick2.sum(x);
            
            // i64 pre2 = fenwick1.sum(l-1)*l-fenwick2.sum(l-1);
            std::cout << pre << '\n';
        }
    }
    
    return 0;
}
