#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

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
  i64 add = 0;
  void apply(const Tag &t) {
      add += t.add;
  }
};
struct Info {
  i64 sum = 0,len = 0;
  void apply(const Tag &t) {
      sum += len*t.add;
  }
};
Info operator+(const Info &a, const Info &b) {
  return Info{a.sum+b.sum,a.len+b.len};
}

using SGT = LazySegmentTree<Info,Tag>;

void solve() {
  int n,q;
  std::cin >> n >> q;

  std::vector<Info> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i].sum;
    a[i].len = 1;
  }

  SGT sgt(a);

  for(int qi = 0; qi < q; qi++){
    std::string op;
    int l,r;
    std::cin >> op >> l >> r;

    if(op=="C"){
      i64 d;
      std::cin >> d;

      sgt.rangeApply(l,r,Tag{d});
    }else{
      std::cout << sgt.rangeQuery(l,r).sum << "\n";
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}