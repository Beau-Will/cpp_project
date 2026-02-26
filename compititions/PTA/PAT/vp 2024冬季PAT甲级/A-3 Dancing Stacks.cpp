#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9 + 7, P2 = 998'244'353;

struct Node {
  int val, pri, sz, rev, l, r;
};

std::vector<Node> tr(200001);

int cnt = 0;

int new_node(int v) {
  ++cnt;
  tr[cnt].val = v;
  tr[cnt].pri = rand();
  tr[cnt].sz = 1;
  tr[cnt].rev = 0;
  tr[cnt].l = tr[cnt].r = 0;
  return cnt;
}

void push(int t) {
  if (t && tr[t].rev) {
    tr[t].rev = 0;
    std::swap(tr[t].l, tr[t].r);
    if (tr[t].l) {
      tr[tr[t].l].rev ^= 1;
    }
    if (tr[t].r) {
      tr[tr[t].r].rev ^= 1;
    }
  }
}

void update(int t) {
  if (t) {
    tr[t].sz = tr[tr[t].l].sz + tr[tr[t].r].sz + 1;
  }
}

void split(int t, int k, int& a, int& b) {
  if (!t) {
    a = b = 0;
    return;
  }
  push(t);
  int leftSize = tr[tr[t].l].sz;
  if (k <= leftSize) {
    split(tr[t].l, k, a, tr[t].l);
    b = t;
  } else {
    split(tr[t].r, k - leftSize - 1, tr[t].r, b);
    a = t;
  }
  update(t);
}

int merge(int a, int b) {
  if (!a) return b;
  if (!b) return a;
  push(a);
  push(b);
  if (tr[a].pri > tr[b].pri) {
    tr[a].r = merge(tr[a].r, b);
    update(a);
    return a;
  } else {
    tr[b].l = merge(a, tr[b].l);
    update(b);
    return b;
  }
}

int pop_front(int& root) {
  push(root);
  int left, right;
  split(root, 1, left, right);
  int val = tr[left].val;
  root = right;
  return val;
}

int pop_back(int& root) {
  push(root);
  int sz = tr[root].sz;
  int left, right;
  split(root, sz - 1, left, right);
  root = left;
  return right;
}

void solve() {
  int q;
  std::cin >> q;

  int E = 0, O = 0;
  int n = 0;

  for (int qi = 0; qi < q; qi++) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int x;
      std::cin >> x;

      int newnode = new_node(x);
      int newE = merge(newnode, O);
      O = E;
      E = newE;
      n++;
    } else if (op == 1) {
      if (n == 0) {
        std::cout << "-1\n";
      } else {
        int val = pop_front(E);
        std::cout << val << "\n";
        int oldO = O;
        O = E;
        E = oldO;
        n--;
      }
    } else if (op == 2) {
      if (n == 0) continue;
      if (E) tr[E].rev ^= 1;
      if (O) tr[O].rev ^= 1;
      if (n % 2 == 0) {
        std::swap(E, O);
      }
    } else {
      if (n == 0) continue;
      if (n % 2 == 0) {
        std::swap(E, O);
      } else {
        int last = pop_back(E);
        int newE = merge(O, last);
        O = E;
        E = newE;
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for (int Ti = 0; Ti < T; Ti++) {
    solve();
  }

  return 0;
}