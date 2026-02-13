#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

// template<class Info, class Tag>
// struct LazySegmentTree {
//   int n;
//   std::vector<Info> info;
//   std::vector<Tag> tag;
//   LazySegmentTree() : n(0) {}
//   LazySegmentTree(int n_, Info v_ = Info()) {
//     init(n_, v_);
//   }
//   template<class T>
//   LazySegmentTree(std::vector<T> init_) {
//     init(init_);
//   }
//   void init(int n_, Info v_ = Info()) {
//     init(std::vector<Info>(n_ + 1, v_));
//   }
//   template<class T>
//   void init(std::vector<T> init_) {
//     n = init_.size() - 1;
//     info.assign(4 * (n + 5), Info());
//     tag.assign(4 * (n + 5), Tag());
//     std::function<void(int, int, int)> build = [&](int p, int l, int r) {
//       if (l == r) {
//         info[p] = init_[l];
//         return;
//       }
//       int m = (l + r) / 2;
//       build(p * 2, l, m);
//       build(p * 2 + 1, m + 1, r);
//       pull(p);
//     };
//     build(1, 1, n);
//   }
//   void pull(int p) {
//     info[p] = info[p * 2] + info[p * 2 + 1];
//   }
//   void apply(int p, const Tag& v) {
//     info[p].apply(v);
//     tag[p].apply(v);
//   }
//   void push(int p) {
//     apply(p * 2, tag[p]);
//     apply(p * 2 + 1, tag[p]);
//     tag[p] = Tag();
//   }
//   void modify(int p, int l, int r, int x, const Info& v) {
//     if (l == r) {
//       info[p] = v;
//       return;
//     }
//     int m = (l + r) / 2;
//     push(p);
//     if (x <= m) {
//       modify(p * 2, l, m, x, v);
//     } else {
//       modify(p * 2 + 1, m + 1, r, x, v);
//     }
//     pull(p);
//   }
//   void modify(int x, const Info& v) {
//     modify(1, 1, n, x, v);
//   }
//   Info rangeQuery(int p, int l, int r, int x, int y) {
//     if (l > y || r < x) {
//       return Info();
//     }
//     if (l >= x && r <= y) {
//       return info[p];
//     }
//     int m = (l + r) / 2;
//     push(p);
//     return rangeQuery(p * 2, l, m, x, y) + rangeQuery(p * 2 + 1, m + 1, r, x, y);  // 修改：右子区间从m+1开始
//   }
//   Info rangeQuery(int l, int r) {
//     return rangeQuery(1, 1, n, l, r);
//   }
//   void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
//     if (l > y || r < x) {
//       return;
//     }
//     if (l >= x && r <= y) {
//       apply(p, v);
//       return;
//     }
//     int m = (l + r) / 2;
//     push(p);
//     rangeApply(p * 2, l, m, x, y, v);
//     rangeApply(p * 2 + 1, m + 1, r, x, y, v);
//     pull(p);
//   }
//   void rangeApply(int l, int r, const Tag& v) {
//     return rangeApply(1, 1, n, l, r, v);
//   }
//   void half(int p, int l, int r) {
//     if (info[p].act == 0) {
//       return;
//     }
//     if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
//       apply(p, {-(info[p].min + 1) / 2});
//       return;
//     }
//     int m = (l + r) / 2;
//     push(p);
//     half(p * 2, l, m);
//     half(p * 2 + 1, m + 1, r);
//     pull(p);
//   }
//   void half() {
//     half(1, 1, n);
//   }

//   template<class F>
//   int findFirst(int p, int l, int r, int x, int y, F&& pred) {
//     if (l > y || r < x) {
//       return -1;
//     }
//     if (l >= x && r <= y && !pred(info[p])) {
//       return -1;
//     }
//     if (l == r) {
//       return l;
//     }
//     int m = (l + r) / 2;
//     push(p);
//     int res = findFirst(p * 2, l, m, x, y, pred);
//     if (res == -1) {
//       res = findFirst(p * 2 + 1, m + 1, r, x, y, pred);
//     }
//     return res;
//   }
//   template<class F>
//   int findFirst(int l, int r, F&& pred) {
//     return findFirst(1, 1, n, l, r, pred);
//   }
//   template<class F>
//   int findLast(int p, int l, int r, int x, int y, F&& pred) {
//     if (l > y || r < x) {
//       return -1;
//     }
//     if (l >= x && r <= y && !pred(info[p])) {
//       return -1;
//     }
//     if (l == r) {
//       return l;
//     }
//     int m = (l + r) / 2;
//     push(p);
//     int res = findLast(p * 2 + 1, m + 1, r, x, y, pred);
//     if (res == -1) {
//       res = findLast(p * 2, l, m, x, y, pred);
//     }
//     return res;
//   }
//   template<class F>
//   int findLast(int l, int r, F&& pred) {
//     return findLast(1, 1, n, l, r, pred);
//   }

//   void maintainL(int p, int l, int r, int pre) {
//     if (info[p].difl > 0 && info[p].maxlowl < pre) {
//       return;
//     }
//     if (l == r) {
//       info[p].max = info[p].maxlowl;
//       info[p].maxl = info[p].maxr = l;
//       info[p].maxlowl = info[p].maxlowr = -inf;
//       return;
//     }
//     int m = (l + r) / 2;
//     push(p);
//     maintainL(p * 2, l, m, pre);
//     pre = std::max(pre, info[p * 2].max);
//     maintainL(p * 2 + 1, m + 1, r, pre);
//     pull(p);
//   }
//   void maintainL() {
//     maintainL(1, 1, n, -1);
//   }
//   void maintainR(int p, int l, int r, int suf) {
//     if (info[p].difr > 0 && info[p].maxlowr < suf) {
//       return;
//     }
//     if (l == r) {
//       info[p].max = info[p].maxlowl;
//       info[p].maxl = info[p].maxr = l;
//       info[p].maxlowl = info[p].maxlowr = -inf;
//       return;
//     }
//     int m = (l + r) / 2;
//     push(p);
//     maintainR(p * 2 + 1, m + 1, r, suf);
//     suf = std::max(suf, info[p * 2 + 1].max);
//     maintainR(p * 2, l, m, suf);
//     pull(p);
//   }
//   void maintainR() {
//     maintainR(1, 1, n, -1);
//   }
// };

// struct Tag {

// };

// struct Info {

// };

// Info operator+(const Info& a, const Info& b) {

// }

int n;
std::vector<int> ls, rs, par;
std::vector<i64> dp;
std::vector<bool> vis;
int idx;

int build(int l, int r, int fa){
  int id = ++idx;
  ls.push_back(0);
  rs.push_back(0);
  par.push_back(fa);
  dp.push_back(0);
  vis.push_back(false);

  if(l == r){
    dp[id] = 1;
    vis[id] = true;
    return id;
  }

  int mid = (l + r) >> 1;
  int lc = build(l, mid, id);
  int rc = build(mid + 1, r, id);

  ls[id] = lc;
  rs[id] = rc;
  dp[id] = 1;
  vis[id] = 1;
  return id;
}

int get(int l, int r){
  int id = 1;
  int lo = 1, hi = n;
  while(true){
    if(lo == l && hi == r){
      return id;
    }
    int mid = (lo + hi) >> 1;
    if(r <= mid){
      id = ls[id];
      hi = mid;
    }else{
      id = rs[id];
      lo = mid + 1;
    }
  }
}

void update(int id){
  if(!vis[id]){
    return;
  }
  vis[id] = false;

  if(!ls[id] && !rs[id]){
    dp[id] = 0;
  }else{
    dp[id] = dp[ls[id]] + dp[rs[id]];
  }

  int fa = par[id];
  while(fa){
    if(vis[fa]){
      dp[fa] = 1;
      break;
    }else{
      if(!ls[fa] && !rs[fa]){
        dp[fa] = 0;
      }else{
        dp[fa] = dp[ls[fa]] + dp[rs[fa]];
      }
      fa = par[fa];
    }
  }
}

i64 query(int id, int l, int r, int left, int right){
  if(left <= l && r <= right){
    return dp[id];
  }

  i64 res = 0;
  if(vis[id]){
    res += 1;
  }

  int mid = (l + r) >> 1;
  if(left <= mid && ls[id]){
    res += query(ls[id], l, mid, left, right);
  }
  if(right > mid && rs[id]){
    res += query(rs[id], mid + 1, r, left, right);
  }

  return res;
}

void solve(){
  std::cin >> n;

  ls.reserve((n << 2) + 5);
  rs.reserve((n << 2) + 5);
  par.reserve((n << 2) + 5);
  dp.reserve((n << 2) + 5);
  vis.reserve((n << 2) + 5);

  ls.push_back(0);
  rs.push_back(0);
  par.push_back(0);
  dp.push_back(0);
  vis.push_back(false);

  build(1, n, 0);

  for(int i = 0; i < n; i++){
    int op, l, r;
    std::cin >> op >> l >> r;

    if(op == 1){
      update(get(l, r));
    }else{
      std::cout << query(1, 1, n, l, r) << "\n";
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}