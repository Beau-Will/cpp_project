#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

struct Node {
  int lc, rc, par;
  i64 val;
  int cnt;
  int siz;
  int tag;
  i64 add;
  int idx;
  void init(int p, i64 v, int i) {
    par = p;
    val = v;
    cnt = siz = 1;
    tag = 0;
    add = 0;
    idx = i;
  }
};

template<class T>
struct Splay{
  std::vector<Node> tr;
  int root;

  Splay(){}

  Splay(int n){
    root = 0;
    tr.reserve(n + 3);
    tr.push_back({});
  }

  void pushup(int x) {
    tr[x].siz = tr[tr[x].lc].siz + tr[tr[x].rc].siz + tr[x].cnt;
  }

  void pushdown(int x){
    if(tr[x].add){
      if(tr[x].lc){
        tr[tr[x].lc].val += tr[x].add;
        tr[tr[x].lc].add += tr[x].add;
      }
      if(tr[x].rc){
        tr[tr[x].rc].val += tr[x].add;
        tr[tr[x].rc].add += tr[x].add;
      }
      tr[x].add = 0;
    }
    if(tr[x].tag){
      std::swap(tr[x].lc, tr[x].rc);
      if(tr[x].lc){
        tr[tr[x].lc].tag ^= 1;
      }
      if(tr[x].rc){
        tr[tr[x].rc].tag ^= 1;
      }
      tr[x].tag = 0;
    }
  }

  void rotate(int x) {
    int y = tr[x].par, z = tr[y].par;
    int k = (tr[y].rc == x) ? 1 : 0;

    if (z) {
      if (tr[z].lc == y) tr[z].lc = x;
      else tr[z].rc = x;
    }
    tr[x].par = z;

    if (k == 0) {
      tr[y].lc = tr[x].rc;
      if (tr[x].rc) tr[tr[x].rc].par = y;
      tr[x].rc = y;
    } else {
      tr[y].rc = tr[x].lc;
      if (tr[x].lc) tr[tr[x].lc].par = y;
      tr[x].lc = y;
    }
    tr[y].par = x;

    pushup(y);
    pushup(x);
  }

  void splay(int x, int k) {
    std::vector<int> path;
    for(int i = x; i; i = tr[i].par){
      path.push_back(i);
    }
    std::reverse(path.begin(), path.end());
    for(int i : path){
      pushdown(i);
    }
    while (tr[x].par != k) {
      int y = tr[x].par, z = tr[y].par;
      if (z != k) {
        if ((tr[y].lc == x) != (tr[z].lc == y)) rotate(x);
        else rotate(y);
      }
      rotate(x);
    }
    if (k == 0) root = x;
  }

  void insert(i64 v, int idx) {
    int x = root, p = 0;
    while (x) {
      pushdown(x);
      p = x;
      if (v >= tr[x].val) x = tr[x].rc;
      else x = tr[x].lc;
    }
    tr.push_back({});
    x = tr.size() - 1;
    if(p){
      if(v >= tr[p].val){
        tr[p].rc = x;
      }else{
        tr[p].lc = x;
      }
    }
    tr[x].init(p, v, idx);
    splay(x, 0);
  }

  int lower_bound(i64 v){
    int x = root;
    int res = 0;
    while(x){
      pushdown(x);
      if(tr[x].val >= v){
        res = x;
        x = tr[x].lc;
      }else{
        x = tr[x].rc;
      }
    }
    return res;
  }

  void update(i64 x){
    int u = lower_bound(x);
    if(!u){
      return;
    }

    splay(u, 0);
    tr[u].val += x;
    if(tr[u].rc){
      tr[tr[u].rc].val += x;
      tr[tr[u].rc].add += x;
    }
  }

  void collect(std::vector<i64>& ans){
    std::vector<int> stk;
    int u = root;
    while(u || stk.size()){
      while(u){
        pushdown(u);
        stk.push_back(u);
        u = tr[u].lc;
      }
      u = stk.back();
      stk.pop_back();
      ans[tr[u].idx] = tr[u].val;
      u = tr[u].rc;
    }
  }

  void print(i64 x){
    if(tr[x].lc){
      print(tr[x].lc);
    }
    std::cout << tr[x].val << " ";
    if(tr[x].rc){
      print(tr[x].rc);
    }
  }

  void print(){
    print(root);
    std::cout << "\n";
  }
};

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  Splay<Node> splay(n);
  for(int i = 1; i <= n; i++){
    splay.update(a[i]);
    splay.insert(a[i], i);
  }

  std::vector<i64> ans(n + 1);
  splay.collect(ans);

  for(int i = 1; i <= n; i++){
    std::cout << ans[i] << " \n"[i == n];
  }
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