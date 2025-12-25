#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

constexpr int N = 2e5+5;

struct node{
  int max,min;
};

std::vector<node> treex(N*4),treey(N*4);
std::vector<int> x(N),y(N);

node merge(node &left,node &right){
  return {std::max(left.max,right.max),std::min(left.min,right.min)};
}

void build(const std::vector<int> &v,std::vector<node> &tree,int rt,int left,int right){
  if(left == right){
    tree[rt].max = v[left];
    tree[rt].min = v[left];
    return;
  }
  int mid = left+(right-left)/2;
  build(v,tree,rt*2,left,mid);
  build(v,tree,rt*2+1,mid+1,right);
  tree[rt] = merge(tree[rt*2],tree[rt*2+1]);
}

void update(std::vector<node> &tree,int rt,int left,int right,int idx,int value){
  if(left == right){
    tree[rt].max = value;
    tree[rt].min = value;
    return;
  }
  int mid = left+(right-left)/2;
  if(idx <= mid){
    update(tree,rt*2,left,mid,idx,value);
  }else{
    update(tree,rt*2+1,mid+1,right,idx,value);
  }
  tree[rt] = merge(tree[rt*2],tree[rt*2+1]);
}

node queryRange(std::vector<node> &tree,int rt,int left,int right,int ql,int qr){
  if(ql==left && qr==right){
    return tree[rt];
  }
  int mid = left+(right-left)/2;
  if(qr<=mid){
    return queryRange(tree,rt*2,left,mid,ql,qr);
  }else if(ql>mid){
    return queryRange(tree,rt*2+1,mid+1,right,ql,qr);
  }else{
    auto leftNode = queryRange(tree,rt*2,left,mid,ql,mid);
    auto rightNode = queryRange(tree,rt*2+1,mid+1,right,mid+1,qr);
    return merge(leftNode,rightNode);
  }
}

void solve() {
  int n,q;
  std::cin >> n >> q;
  
  for(int i = 1; i <= n; i++){
    int a,b;
    std::cin >> a >> b;
    x[i] = a+b;
    y[i] = a-b;
  }

  build(x,treex,1,1,n);
  build(y,treey,1,1,n);

  for(int qi = 0; qi < q; qi++){
    int op;
    std::cin >> op;

    if(op==1){
      int i,ua,ub;
      std::cin >> i >> ua >> ub;
      int ux = ua+ub,uy = ua-ub;
      update(treex,1,1,n,i,ux);
      update(treey,1,1,n,i,uy);
    }else{
      int l,r,qa,qb;
      std::cin >> l >> r >> qa >> qb;

      i64 qx = qa+qb,qy = qa-qb;
      auto queryx = queryRange(treex,1,1,n,l,r);
      auto queryy = queryRange(treey,1,1,n,l,r);

      i64 ansx = std::max(std::abs(qx-queryx.max),std::abs(qx-queryx.min));
      i64 ansy = std::max(std::abs(qy-queryy.max),std::abs(qy-queryy.min));
      std::cout << std::max(ansx,ansy) << "\n";
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