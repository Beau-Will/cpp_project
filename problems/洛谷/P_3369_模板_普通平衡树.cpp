#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9 + 7, P2 = 998'244'353;

struct Node {
  int lc, rc, par;
  int val;
  int cnt;
  int siz;
  void init(int p, int v) {
    par = p;
    val = v;
    cnt = siz = 1;
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
    while (x && tr[x].val != v) {
      p = x;
      if (v > tr[x].val) x = tr[x].rc;
      else x = tr[x].lc;
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
};

void solve() {
  int n;
  std::cin >> n;

  Splay<Node> splay(n);
  splay.insert(-inf1);
  splay.insert(inf1);

  for (int i = 0; i < n; ++i) {
    int op, x;
    std::cin >> op >> x;
    if (op == 1) {
      splay.insert(x);
    } else if (op == 2) {
      splay.erase(x);
    } else if (op == 3) {
      std::cout << splay.getrank(x) << '\n';
    } else if (op == 4) {
      std::cout << splay.getval(x + 1) << '\n';
    } else if (op == 5) {
      std::cout << splay.tr[splay.getprev(x)].val << '\n';
    } else {
      std::cout << splay.tr[splay.getnext(x)].val << '\n';
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for (int Ti = 0; Ti < T; ++Ti) {
    solve();
  }

  return 0;
}