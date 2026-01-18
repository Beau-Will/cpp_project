#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9 + 7, P2 = 998'244'353;

struct Node {
  bool isBlack;
  char cntB;
  char siz;
  int rt[4];
  char cnt[4];
  Node() : isBlack(false), cntB(0), siz(0) {}
};

constexpr int dx4[4] = {-1, 1, 0, 0};
constexpr int dy4[4] = {0, 0, -1, 1};
constexpr int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

using namespace std;

void solve() {
  // using namespace std;

  int n;
  cin >> n;
  vector<string> g(n);
  for(int i = 0; i < n; ++i) cin >> g[i];

  int N = n * n;
  vector<Node> c(N);

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      int id = i * n + j;
      c[id].isBlack = (g[i][j] == '1');
    }
  }

  auto bfs = [&](int x,int y){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
      int u = x+dx4[i],v = y+dy4[i];
      if(u < 0 || u >= n || v < 0 || v >= n){
        continue;
      }
      cnt += (g[u][v] == '1');
    }
 
    if(cnt >= 3){
      g[x][y] = '1';
    }else if(cnt == 2){
      std::vector<int> idx;
 
      for(int i = 0; i < 4; i++){
        int u = x+dx4[i],v = y+dy4[i];
        if(u < 0 || u >= n || v < 0 || v >= n){
          continue;
        }
        if(g[u][v] == '1'){
          idx.push_back(i);
        }
      }
 
      std::sort(idx.begin(),idx.end());
 
      if(idx.front() == 0 && idx.back() == 1 || idx.front() == 2 && idx.back() == 3){
        return;
      }
 
      g[x][y] = '1';
    }
  };

  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < n; j++){
  //     if(g[i][j] == '0'){
  //       bfs(i,j);
  //     }
  //   }
  // }

  vector<int> fa(N);
  vector<int> rk(N, 0);

  std::iota(fa.begin(), fa.end(), 0);

  function<int(int)> find = [&](int x) {
    if(fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
  };

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      int id = i * n + j;
      if(!c[id].isBlack) continue;

      for(int d = 0; d < 8; ++d) {
        int ni = i + dx8[d], nj = j + dy8[d];

        if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        int nid = ni * n + nj;

        if(c[nid].isBlack) {
          int r1 = find(id), r2 = find(nid);

          if(r1 != r2) {
            if(rk[r1] < rk[r2]) swap(r1, r2);

            fa[r2] = r1;
            if(rk[r1] == rk[r2]) ++rk[r1];
          }
        }
      }
    }
  }

  // std::cout << "?1\n";

  unordered_map<int, unordered_map<int, int>> rtW;
  vector<bool> inc(N, false);
  vector<int> can;

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {

      int id = i * n + j;
      if(c[id].isBlack) continue;

      for(int d = 0; d < 4; ++d) {
        int ni = i + dx4[d], nj = j + dy4[d];

        if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        int nid = ni * n + nj;

        if(c[nid].isBlack) {
          c[id].cntB++;
          int root = find(nid);
          int pos = -1;

          for(int k = 0; k < c[id].siz; ++k) {
            if(c[id].rt[k] == root) {
              pos = k;
              break;
            }
          }

          if(pos >= 0) {
            c[id].cnt[pos]++;
          } else {
            c[id].rt[c[id].siz] = root;
            c[id].cnt[c[id].siz] = 1;
            c[id].siz++;
          }
        }
      }

      // cout << "case 1\n";

      if(c[id].cntB >= 2) {
        bool ok = false;

        for(int k = 0; k < c[id].siz; ++k) {
          if(c[id].cnt[k] >= 2) {
            ok = true;
            break;
          }
        }
        if(ok) {
          can.push_back(id);
          inc[id] = true;
        }
      }

      for(int k = 0; k < c[id].siz; ++k) {
        int root = c[id].rt[k];
        int cnt = c[id].cnt[k];
        rtW[root][id] += cnt;
      }
    }
  }

  // std::cout << "?2\n";

  while (!can.empty()) {
    vector<int> cur = can;
    can.clear();
    vector<int> next_can;

    auto merge_components = [&](int root1, int root2) {
      if(root1 == root2) return;

      int new_root, old_root;

      if(rk[root1] < rk[root2]) {
        fa[root1] = root2;
        new_root = root2;
        old_root = root1;
      } else {
        fa[root2] = root1;
        new_root = root1;
        old_root = root2;

        if(rk[root1] == rk[root2]) ++rk[root1];
      }

      auto& new_map = rtW[new_root];
      auto& old_map = rtW[old_root];

      for(auto& [white_id, cnt] : old_map) {
        if(c[white_id].isBlack) continue;

        new_map[white_id] += cnt;
        Node& tmp = c[white_id];

        int old_pos = -1;

        for(int k = 0; k < tmp.siz; ++k) {
          if(tmp.rt[k] == old_root) {
            old_pos = k;
            break;
          }
        }

        if(old_pos == -1) continue;

        int old_count = tmp.cnt[old_pos];
        int new_pos = -1;

        for(int k = 0; k < tmp.siz; ++k) {
          if(tmp.rt[k] == new_root) {
            new_pos = k;
            break;
          }
        }

        if(new_pos >= 0) {
          tmp.cnt[new_pos] += old_count;
        } else {
          tmp.rt[tmp.siz] = new_root;
          tmp.cnt[tmp.siz] = old_count;
          tmp.siz++;
        }

        tmp.siz--;

        if(old_pos < tmp.siz) {
          tmp.rt[old_pos] = tmp.rt[tmp.siz];
          tmp.cnt[old_pos] = tmp.cnt[tmp.siz];
        }
        if(tmp.cntB >= 2 && !inc[white_id]) {
          for(int k = 0; k < tmp.siz; ++k) {
            if(tmp.cnt[k] >= 2) {
              next_can.push_back(white_id);
              inc[white_id] = true;
              break;
            }
          }
        }
      }

      rtW.erase(old_root);
    };

    // cout << "case 2\n";

    for(int id : cur) {
      if(c[id].isBlack) continue;

      int i = id / n, j = id % n;

      for(int k = 0; k < c[id].siz; ++k) {
        int root = c[id].rt[k];

        auto it = rtW.find(root);

        if(it != rtW.end()) {
          it->second.erase(id);
        }
      }

      c[id].isBlack = true;
      g[i][j] = '1';

      for(int d = 0; d < 8; ++d) {
        int ni = i + dx8[d], nj = j + dy8[d];

        if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        int nid = ni * n + nj;

        if(c[nid].isBlack) {
          int root1 = find(id);
          int root2 = find(nid);

          if(root1 != root2) {
            merge_components(root1, root2);
          }
        }
      }

      for(int d = 0; d < 4; ++d) {
        int ni = i + dx4[d], nj = j + dy4[d];

        if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        int nid = ni * n + nj;

        if(!c[nid].isBlack) {
          c[nid].cntB++;
          int root_cur = find(id);

          int pos = -1;
          for(int k = 0; k < c[nid].siz; ++k) {
            if(c[nid].rt[k] == root_cur) {
              pos = k;
              break;
            }
          }

          if(pos >= 0) {
            c[nid].cnt[pos]++;
          }else {
            c[nid].rt[c[nid].siz] = root_cur;
            c[nid].cnt[c[nid].siz] = 1;
            c[nid].siz++;
          }

          rtW[root_cur][nid]++;

          if(c[nid].cntB >= 2 && !inc[nid]) {
            for(int k = 0; k < c[nid].siz; ++k) {
              if(c[nid].cnt[k] >= 2) {
                next_can.push_back(nid);
                inc[nid] = true;
                break;
              }
            }
          }
        }
      }
    }

    can = next_can;
  }

  // std::cout << "?3\n";

  for(int i = 0; i < n; ++i) {
    cout << g[i] << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;) {
    solve();
  }
}