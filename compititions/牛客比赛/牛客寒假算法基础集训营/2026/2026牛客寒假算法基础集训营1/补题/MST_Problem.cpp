#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr int inf = 2E9 + 10;

/*
 * 修改后的懒标记线段树是1-based的，用于构造的init_数组也是1-based
 * 区间查询和区间修改的区间[l,r]皆为左闭右闭，为1-based
 */
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
    init(std::vector<Info>(n_ + 1, v_));  // 注意：这里创建n+1个元素，下标0不使用
  }
  template<class T>
  void init(std::vector<T> init_) {
    n = init_.size() - 1;  // 因为init_是1-based，下标0不使用，所以实际元素个数是size()-1
    info.assign(4 * (n + 5), Info());  // 多分配一些空间
    tag.assign(4 * (n + 5), Tag());
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (l == r) {  // 修改：左闭右闭，叶子节点条件是l==r
        info[p] = init_[l];
        return;
      }
      int m = (l + r) / 2;
      build(p * 2, l, m);
      build(p * 2 + 1, m + 1, r);  // 修改：右子区间从m+1开始
      pull(p);
    };
    build(1, 1, n);  // 修改：从[1,n]开始构建
  }
  void pull(int p) {
    info[p] = info[p * 2] + info[p * 2 + 1];
  }
  void apply(int p, const Tag& v) {
    info[p].apply(v);
    tag[p].apply(v);
  }
  void push(int p) {
    apply(p * 2, tag[p]);
    apply(p * 2 + 1, tag[p]);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info& v) {
    if (l == r) {  // 修改：左闭右闭，叶子节点条件是l==r
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    if (x <= m) {  // 修改：根据x与m的关系判断向左还是向右
      modify(p * 2, l, m, x, v);
    } else {
      modify(p * 2 + 1, m + 1, r, x, v);
    }
    pull(p);
  }
  void modify(int x, const Info& v) {  // 修改：参数名改为x更清晰
    modify(1, 1, n, x, v);
  }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l > y || r < x) {  // 修改：区间不重叠的条件
      return Info();
    }
    if (l >= x && r <= y) {  // 区间完全包含
      return info[p];
    }
    int m = (l + r) / 2;
    push(p);
    return rangeQuery(p * 2, l, m, x, y) + rangeQuery(p * 2 + 1, m + 1, r, x, y);  // 修改：右子区间从m+1开始
  }
  Info rangeQuery(int l, int r) {
    return rangeQuery(1, 1, n, l, r);
  }
  void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
    if (l > y || r < x) {  // 修改：区间不重叠的条件
      return;
    }
    if (l >= x && r <= y) {  // 区间完全包含
      apply(p, v);
      return;
    }
    int m = (l + r) / 2;
    push(p);
    rangeApply(p * 2, l, m, x, y, v);
    rangeApply(p * 2 + 1, m + 1, r, x, y, v);  // 修改：右子区间从m+1开始
    pull(p);
  }
  void rangeApply(int l, int r, const Tag& v) {
    return rangeApply(1, 1, n, l, r, v);
  }
  void half(int p, int l, int r) {
    if (info[p].act == 0) {
      return;
    }
    if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
      apply(p, {-(info[p].min + 1) / 2});
      return;
    }
    int m = (l + r) / 2;
    push(p);
    half(p * 2, l, m);
    half(p * 2 + 1, m + 1, r);  // 修改：右子区间从m+1开始
    pull(p);
  }
  void half() {
    half(1, 1, n);
  }

  template<class F>
  int findFirst(int p, int l, int r, int x, int y, F&& pred) {
    if (l > y || r < x) {  // 修改：区间不重叠的条件
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (l == r) {  // 修改：叶子节点条件是l==r
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findFirst(p * 2, l, m, x, y, pred);
    if (res == -1) {
      res = findFirst(p * 2 + 1, m + 1, r, x, y, pred);  // 修改：右子区间从m+1开始
    }
    return res;
  }
  template<class F>
  int findFirst(int l, int r, F&& pred) {
    return findFirst(1, 1, n, l, r, pred);
  }
  template<class F>
  int findLast(int p, int l, int r, int x, int y, F&& pred) {
    if (l > y || r < x) {  // 修改：区间不重叠的条件
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (l == r) {  // 修改：叶子节点条件是l==r
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findLast(p * 2 + 1, m + 1, r, x, y, pred);  // 修改：右子区间从m+1开始
    if (res == -1) {
      res = findLast(p * 2, l, m, x, y, pred);
    }
    return res;
  }
  template<class F>
  int findLast(int l, int r, F&& pred) {
    return findLast(1, 1, n, l, r, pred);
  }

  void maintainL(int p, int l, int r, int pre) {
    if (info[p].difl > 0 && info[p].maxlowl < pre) {
      return;
    }
    if (l == r) {  // 修改：叶子节点条件是l==r
      info[p].max = info[p].maxlowl;
      info[p].maxl = info[p].maxr = l;
      info[p].maxlowl = info[p].maxlowr = -inf;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    maintainL(p * 2, l, m, pre);
    pre = std::max(pre, info[p * 2].max);
    maintainL(p * 2 + 1, m + 1, r, pre);  // 修改：右子区间从m+1开始
    pull(p);
  }
  void maintainL() {
    maintainL(1, 1, n, -1);
  }
  void maintainR(int p, int l, int r, int suf) {
    if (info[p].difr > 0 && info[p].maxlowr < suf) {
      return;
    }
    if (l == r) {  // 修改：叶子节点条件是l==r
      info[p].max = info[p].maxlowl;
      info[p].maxl = info[p].maxr = l;
      info[p].maxlowl = info[p].maxlowr = -inf;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    maintainR(p * 2 + 1, m + 1, r, suf);  // 修改：右子区间从m+1开始
    suf = std::max(suf, info[p * 2 + 1].max);
    maintainR(p * 2, l, m, suf);
    pull(p);
  }
  void maintainR() {
    maintainR(1, 1, n, -1);
  }
};

struct Tag {
  int v = inf;
  void apply(const Tag& t)& {
    v = std::min(v, t.v);
  }
};

struct Info {
  int min, k, v, i;
  void apply(const Tag& t)& {
    if(t.v != inf && min != inf && t.v + min < v){
      v = t.v + min;
      i = k;
    }
  }
};

Info operator+(const Info& a, const Info& b) {
  Info c;
  if(a.min < b.min){
    c.min = a.min;
    c.k = a.k;
  }else{
    c.min = b.min;
    c.k = b.k;
  }
  if(a.v < b.v){
    c.v = a.v;
    c.i = a.i;
  }else{
    c.v = b.v;
    c.i = b.i;
  }
  return c;
}

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  LazySegmentTree<Info, Tag> seg(n);
  for(int i = 1; i <= n; i++){
    seg.modify(i, {a[i], i, inf, -1});
  }
  seg.modify(1, {0, 1, 0, 1});

  i64 ans = 0;
  for(int _ = 1; _ <= n; _++){
    auto [_1, _2, v, i] = seg.rangeQuery(1, n);
    if(v == inf){
      ans = -1;
      break;
    }
    ans += v;
    seg.modify(i, {inf, -1, inf, -1});

    std::sort(adj[i].begin(), adj[i].end());
    adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
    adj[i].push_back(n + 1);

    int last = 0;
    for(auto j : adj[i]){
      if(last + 1 <= j - 1){
        seg.rangeApply(last + 1, j - 1, {a[i]});
      }
      last = j;
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}