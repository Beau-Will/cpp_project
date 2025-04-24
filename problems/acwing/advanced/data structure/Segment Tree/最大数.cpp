#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

template<class T>
struct segment_tree{
  #define ls u<<1
  #define rs u<<1|1
  int _n;
  std::vector<T> tr;

  void build(int u,int l,int r){
    tr[u].l = l,tr[u].r = r;
    if(l==r){
      return;
    }

    int mid = (l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
  }

  segment_tree(int n = 200000){
    _n = n;
    tr.assign(_n<<2+1,T());
    build(1,1,_n);
  }

  void modify(int u,int pos,const T &x){
    if(tr[u].l==tr[u].r){
      tr[u] = x;
      return;
    }

    int mid = (tr[u].l+tr[u].r)>>1;
    if(pos<=mid){
      modify(ls,pos,x);
    }else{
      modify(rs,pos,x);
    }
    tr[u] = tr[ls]+tr[rs];
  }

  T query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r){
      return tr[u];
    }
    if(tr[u].l>r||tr[u].r<l){
      return T();
    }

    int mid = (tr[u].l+tr[u].r)>>1;

    return query(ls,l,r)+query(rs,l,r);
  }
};

struct Node{
  int l,r;
  int v;
};

Node operator + (const Node& t1,const Node& t2){
  Node res;
  res.l = t1.l;
  res.r = t2.r;
  res.v = std::max(t1.v,t2.v);
  return res;
}

using SGT = segment_tree<Node>;

void solve() {
  int m,p;
  std::cin >> m >> p;

  SGT sgt(m);

  int n = 0,last = 0;
  for(;m--;){
    std::string op;
    std::cin >> op;

    if(op=="A"){
      int x;
      std::cin >> x;
      x = (1LL*x+last)%p;

      ++n;
      sgt.modify(1,n,{n,n,x});
    }else{
      int l;
      std::cin >> l;

      last = sgt.query(1,n-l+1,n).v;
      std::cout << last << "\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}