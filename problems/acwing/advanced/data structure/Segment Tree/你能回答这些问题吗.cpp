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

  segment_tree(int n = 200000){
    _n = n;
    tr.assign(_n<<2+1,T());
  }

  segment_tree(const std::vector<T> &vec){
    _n = vec.size()-1;
    tr.assign(_n<<2+1,T());
    auto build = [&](auto &&self,int u,int l,int r)->void {
      if(l==r){
        tr[u] = vec[l];
        return;
      }
      int mid = (l+r)>>1;
      self(self,ls,l,mid);
      self(self,rs,mid+1,r);
      tr[u] = tr[ls]+tr[rs];
    };
    build(build,1,1,_n);
  }

  void modify(int u,int x,int y,int pos,const T &val){
    if(x==y){
      tr[u] = val;
      return;
    }

    int mid = (x+y)>>1;
    if(pos<=mid){
      modify(ls,x,mid,pos,val);
    }else{
      modify(rs,mid+1,y,pos,val);
    }
    tr[u] = tr[ls]+tr[rs];
  }
  void modify(int pos,const T &val){
    modify(1,1,_n,pos,val);
  }

  T query(int u,int x,int y,int l,int r){
    if(x>=l&&y<=r){
      return tr[u];
    }
    if(x>r||y<l){
      return T{-100000,-100000,-100000,-100000};
    }

    int mid = (x+y)>>1;

    return query(ls,x,mid,l,r)+query(rs,mid+1,y,l,r);
  }
  T query(int l,int r){
    return query(1,1,_n,l,r);
  }
};

struct Node{
  int sum;
  int lmax,rmax;
  int max;
};

Node operator + (const Node& t1,const Node& t2){
  Node res;
  res.sum = t1.sum+t2.sum;
  res.lmax = std::max(t1.lmax,t1.sum+t2.lmax);
  res.rmax = std::max(t2.rmax,t1.rmax+t2.sum);
  res.max = std::max({t1.max,t2.max,t1.rmax+t2.lmax});
  return res;
}

using SGT = segment_tree<Node>;

void solve() {
  int n,m;
  std::cin >> n >> m;

  std::vector<Node> a(n+1);
  for(int i = 1; i <= n; ++i){
    int x;
    std::cin >> x;
    a[i] = {x,x,x,x};
  }

  SGT sgt(a);

  for(;m--;){
    int op;
    std::cin >> op;

    if(op==1){
      int l,r;
      std::cin >> l >> r;

      if(l>r){
        std::swap(l,r);
      }

      std::cout << sgt.query(l,r).max << "\n";
    }else{
      int x;
      i64 y;
      std::cin >> x >> y;

      sgt.modify(x,Node{y,y,y,y});
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