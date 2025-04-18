#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

struct Node{
  int id;
  int siz;
  int cnt;
  int square;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> fa(100001),siz(100001,1),cnt(100001);
  std::vector<i64> square(100001);
  std::iota(fa.begin(),fa.end(),0);

  auto find = [&](auto &&self,int u) ->int {
    if(u!=fa[u]){
      fa[u] = self(self,fa[u]);
    }
    return fa[u];
  };

  auto merge = [&](int u,int v){
    int u_fa = find(find,u);
    int v_fa = find(find,v);
    if(u_fa==v_fa){
      return false;
    }
    fa[v_fa] = u_fa;
    siz[u_fa] += v_fa;
    cnt[u_fa] += v_fa;
    square[u_fa] += v_fa;
    return true;
  };
  
  std::set<int> set;

  for(int i = 0; i < n; ++i){
    int id,p1,p2,k;
    std::cin >> id >> p1 >> p2 >> k;
    std::vector<int> son(k);
    for(int j = 0; j < k; ++j){
      std::cin >> son[j];
    }
    int _cnt,num;
    std::cin >> _cnt >> num;

    int min = 10000;
    min = std::min(min,find(find,id));
    if(p1!=-1) min = std::min(min,find(find,p1));
    if(p2!=-1) min = std::min(min,find(find,p2));
    for(int j = 0; j < k; ++j){
      min = std::min(min,find(find,son[j]));
    }

    merge(min,id);
    merge(min,p1);
    merge(min,p2);
    for(int j = 0; j < k; ++j){
      merge(min,son[j]);
    }

    cnt[min] += _cnt;
    square[min] += num;

    set.insert(min);
    std::cout << min << "\n";
  }

  std::set<int> bak;
  for(auto &ele:set){
    bak.insert(find(find,ele));
  }
  std::vector<Node> ans;
  for(auto &ele:bak){
    Node t;
    int _fa = find(find,ele);
    t.id = _fa;
    t.siz = siz[_fa];
    t.cnt = cnt[_fa];
    t.square = square[_fa];

    ans.push_back(t);
  }

  std::sort(ans.begin(),ans.end(),[&](Node &t1,Node &t2){
    //1.0*s1/siz1 > 1.0*s2/siz2
    if(t1.square*t2.siz != t2.square*t1.siz) return t1.square*t2.siz > t2.square*t1.siz;
    return t1.id < t2.id;
  });

  std::cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); ++i){
    std::cout << ans[i].id << " " << ans[i].siz << " ";
    std::cout << std::fixed << std::setprecision(3) << 1.0*ans[i].cnt/ans[i].siz << " " << 1.0*ans[i].square/ans[i].siz << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}