#include <bits/stdc++.h>

using i64 = long long;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }

    template<class T>
    LazySegmentTree(std::vector<T> init_) { init(init_); }

    void init(int n_, Info v_ = Info()) { init(std::vector<Info>(n_, v_)); }

    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) modify(2 * p, l, m, x, v);
        else modify(2 * p + 1, m, r, x, v);
        pull(p);
    }

    void modify(int p, const Info &v) { modify(1, 0, n, p, v); }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return Info();
        if (l >= x && r <= y) return info[p];
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeApply(int l, int r, const Tag &v) { rangeApply(1, 0, n, l, r, v); }
};

struct Tag {
    i64 add = 0;
    i64 assign = 1e18;  // 初始化为不可能的值表示未赋值
    
    static constexpr i64 INVALID = 1e18;

    void apply(const Tag &t) {
        if (t.assign != INVALID) {  // 优先处理赋值操作
            assign = t.assign;
            add = 0;  // 赋值操作会覆盖之前的加法
        } else if (assign != INVALID) {  // 当前有未应用的赋值
            assign += t.add;  // 加法作用在赋值基础上
        } else {  // 普通加法
            add += t.add;
        }
    }
};

struct Info {
    i64 sum = 0;
    int size = 0;

    void apply(const Tag &t) {
        if (t.assign != Tag::INVALID) {  // 赋值操作
            sum = t.assign * size;
        } else {  // 加法操作
            sum += t.add * size;
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    return {a.sum + b.sum, a.size + b.size};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<Info> init(n);

    for (int i = 0; i < n; ++i) {
    	std::cin >> init[i].sum;
    	init[i].size = 1;
    }

    LazySegmentTree<Info, Tag> sgt(init);

    while (q--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if (op == 1) {  // 区间加
            int x;
            std::cin >> x;
            sgt.rangeApply(l-1, r, Tag{/*add=*/x, /*assign=*/Tag::INVALID});
        } else if (op == 2) {  // 区间查询
            Info res = sgt.rangeQuery(l-1, r);
            std::cout << res.sum << '\n';
        } else if (op == 3) {  // 区间赋值
            int x;
            std::cin >> x;
            sgt.rangeApply(l-1, r, Tag{/*add=*/0, /*assign=*/x});
        }
    }

    return 0;
}