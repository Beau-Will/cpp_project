template<class Info, class Tag> struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(std::vector<Info> init) {
        n = init.size();
        info.assign(4 * n, Info());
        tag.assign(4 * n, Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                info[p] = init[l - 1];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 1, n);
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
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l > y || r < x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        push(p);
        int m = (l + r) / 2;
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 1, n, l, r, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y || r < x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        push(p);
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m + 1, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 1, n, l, r);
    }
};
struct Tag {
    i64 x;
    Tag(i64 x = 0) {
        this->x = x;
    }
    void apply(const Tag &t) {
        x += t.x;
    }
};
struct Info {
    i64 x, l, r;
    Info(i64 x = 0, i64 l = 0, i64 r = 0) {
        this->x = x;
        this->l = l;
        this->r = r;
    }
    void apply(const Tag &t) {
        if (t.x) {
            x += t.x * (r - l + 1);
        }
    }
};
Info operator+(const Info &a, const Info &b) {
    return Info(a.x + b.x, a.l, b.r);
}