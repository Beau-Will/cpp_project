#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

struct Node {
  int lc, rc, par;
  int val;
  int cnt;
  int siz;
  int tag;
  void init(int p, int v) {
    par = p;
    val = v;
    cnt = siz = 1;
    tag = 0;
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

  void insert(int v) {
    int x = root, p = 0;
    while (x) {
      pushdown(x);
      p = x;
      if (v > tr[x].val) x = tr[x].rc;
      else if(v < tr[x].val) x = tr[x].lc;
      else break;
    }
    if (x) {
      tr[x].cnt++;
    } else {
      tr.push_back({});
      x = tr.size() - 1;
      if (p) {
        if (v > tr[p].val) tr[p].rc = x;
        else tr[p].lc = x;
      }
      tr[x].init(p, v);
    }
    splay(x, 0);
  }

  void find(int v) {
    int x = root;
    while (x && tr[x].val != v) {
      if (v > tr[x].val && tr[x].rc) x = tr[x].rc;
      else if (v < tr[x].val && tr[x].lc) x = tr[x].lc;
      else break;
    }
    splay(x, 0);
  }

  int getprev(int v) {
    find(v);
    int x = root;
    if (tr[x].val < v) return x;
    x = tr[x].lc;
    while (tr[x].rc) x = tr[x].rc;
    splay(x, 0);
    return x;
  }

  int getnext(int v) {
    find(v);
    int x = root;
    if (tr[x].val > v) return x;
    x = tr[x].rc;
    while (tr[x].lc) x = tr[x].lc;
    splay(x, 0);
    return x;
  }

  void erase(int v) {
    int prev = getprev(v);
    int next = getnext(v);
    splay(prev, 0);
    splay(next, prev);
    int del = tr[next].lc;
    if (tr[del].cnt > 1) {
      tr[del].cnt--;
      splay(del, 0);
    } else {
      tr[next].lc = 0;
      splay(next, 0);
    }
  }

  int getrank(int v) {
    insert(v);
    int res = tr[tr[root].lc].siz;
    erase(v);
    return res;
  }

  int getval(int k) {
    int x = root;
    while (true) {
      if (k <= tr[tr[x].lc].siz) {
        x = tr[x].lc;
      } else if (k <= tr[tr[x].lc].siz + tr[x].cnt) {
        break;
      } else {
        k -= tr[tr[x].lc].siz + tr[x].cnt;
        x = tr[x].rc;
      }
    }
    splay(x, 0);
    return tr[x].val;
  }

  int getnodebyrank(int k){
    int x = root;
    while(true){
      pushdown(x);
      if(k <= tr[tr[x].lc].siz){
        x = tr[x].lc;
      }else if(k <= tr[tr[x].lc].siz + tr[x].cnt){
        break;
      }else{
        k -= tr[tr[x].lc].siz + tr[x].cnt;
        x = tr[x].rc;
      }
    }
    return x;
  }

  void reverse(int l, int r){
    int left = getnodebyrank(l);
    int right = getnodebyrank(r + 2);
    splay(left, 0);
    splay(right, left);
    if(tr[right].lc){
      tr[tr[right].lc].tag ^= 1;
    }
  }

  void print(int x){
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

  void output(int x, int n){
    if(x == 0){
      return;
    }
    pushdown(x);
    output(tr[x].lc, n);
    if(tr[x].val >= 1 && tr[x].val <= n){
      std::cout << tr[x].val << " ";
    }
    output(tr[x].rc, n);
  }

  void output(int n){
    output(root, n);
    std::cout << "\n";
  }
};

void solve(){
  int n, m;
  std::cin >> n >> m;

  Splay<Node> splay(n);
  splay.insert(-inf1);
  splay.insert(inf1);
  for(int i = 1; i <= n; i++){
    splay.insert(i);
  }

  for(int i = 0; i < m; i++){
    int l, r;
    std::cin >> l >> r;

    splay.reverse(l, r);
  }

  splay.output(n);
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