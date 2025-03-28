struct ODT {
    struct node {
        int l, r;
        mutable ll v;
        node(int l, int r = -1, ll v = 0) : l(l), r(r), v(v) {}
        bool operator<(const node &o) const {
            return l < o.l;
        }
    };
    set<node> s;
    int sum = 0; // 区间一次和（特殊）

    ODT() {
        s.clear();
    }

    auto split(int pos) {
        auto it = s.lower_bound(node(pos));
        if (it != s.end() && it->l == pos) return it;
        it--;
        int l = it->l, r = it->r;
        ll v = it->v;
        s.erase(it);
        s.insert(node(l, pos - 1, v));
        return s.insert(node(pos, r, v)).first;
    }

    void assign(int l, int r, ll x) {
        auto itr = split(r + 1), itl = split(l), it = itl;
        for (; itl != itr; ++itl) {
            sum -= itl->v * (itl->r - itl->l + 1);
        }
        s.erase(it, itr);
        s.insert(node(l, r, x));
        sum += x * (r - l + 1);
    }

    ll kth(int l, int r, int k) {
        vector<pair<ll, int>> a;
        auto itr = split(r + 1), itl = split(l);
        for (auto it = itl; it != itr; ++it) {
            a.emplace_back(it->v, it->r - it->l + 1);
        }
        sort(a.begin(), a.end());
        for (auto &x : a) {
            k -= x.second;
            if (k <= 0) return x.first;
        }
        return 0;
    }
};