#include <iostream>
#include <vector>
#include <functional>
#include <string>

template<class Info, class Tag>
struct LazySegmentTree {
  int n;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LazySegmentTree() : n(0) {}
  LazySegmentTree(int n_, Info v_ = Info()) {
    init(n_, v_);
  }
  template<class T>
  LazySegmentTree(std::vector<T> init_) {
    init(init_);
  }
  void init(int n_, Info v_ = Info()) {
    init(std::vector(n_, v_));
  }
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
  void apply(int p, const Tag& v) {
    info[p].apply(v);
    tag[p].apply(v);
  }
  void push(int p) {
    apply(2 * p, tag[p]);
    apply(2 * p + 1, tag[p]);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info& v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    if (x < m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m, r, x, v);
    }
    pull(p);
  }
  void modify(int p, const Info& v) {
    modify(1, 0, n, p, v);
  }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
      return Info();
    }
    if (l >= x && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    push(p);
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
  }
  Info rangeQuery(int l, int r) {
    return rangeQuery(1, 0, n, l, r);
  }
  void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
    if (l >= y || r <= x) {
      return;
    }
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
  void rangeApply(int l, int r, const Tag& v) {
    return rangeApply(1, 0, n, l, r, v);
  }
};

struct Tag {
  bool flip = false;
  void apply(const Tag& t)& {
    if(t.flip){
      flip = !flip;
    }
  }
};

struct Info {
  int cnt = 0,len = 1;
  void apply(const Tag& t)& {
    if(t.flip){
      cnt = len-cnt;
    }
  }
};

Info operator+(const Info& a, const Info& b) {
  return {a.cnt+b.cnt,a.len+b.len};
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, q;
  std::cin >> n >> q;

  std::string s;
  std::cin >> s;

  std::vector<Info> init(n);
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '1'){
      init[i].cnt = 1;
    }else{
      init[i].cnt = 0;
    }
    init[i].len = 1;
  }

  LazySegmentTree<Info,Tag> lsgt(init);

  for (int qi = 0; qi < q; qi++) {
    int op, l, r;
    std::cin >> op >> l >> r;
    l--;

    if (op == 1) {
      lsgt.rangeApply(l,r,Tag{true});
    } else {
      std::cout << lsgt.rangeQuery(l,r).cnt << "\n";
    }
  }
}