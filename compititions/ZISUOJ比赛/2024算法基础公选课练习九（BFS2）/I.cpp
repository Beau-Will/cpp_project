#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
using ll = long long;
#define push_back emplace_back
#define push emplace
int a[N];
int n,m,s,k;
vector<int> g[N];
int ans[N][105];
int vis[N][105];
struct node{
    int dis,id,idx;//距离，国家，种类
    bool operator < (const node &b)const{
        return dis>b.dis;
    }
};
queue<node> q;
void bfs(){
    while(q.size()){
        auto t=q.front();
        q.pop();
        int dis=t.dis,id=t.id,idx=t.idx;
        if(vis[id][idx]) continue;
        vis[id][idx]=1;
        for(int v:g[id]){
            if(ans[id][idx]+1<ans[v][idx]){
                ans[v][idx]=ans[id][idx]+1;
                q.push(ans[v][idx],v,idx);
            }
        }
    }
}
void solve(){
    cin >> n >> m >> k >> s;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++){
        int x,y;cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(ans,INF,sizeof ans);
    for(int i=1;i<=n;i++){
        ans[i][a[i]]=0;//源点为0
        q.push(0,i,a[i]);//压入队列
    }
    bfs();
    for(int i=1;i<=n;i++){
        sort(ans[i]+1,ans[i]+k+1);//排序
        ll sum=0;
        for(int j=1;j<=s;j++){
            sum+=ans[i][j];//累加求和
        }
        cout << sum << ' '; 
    }
}
int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
//  cin >> t;
    while(t--) solve(); 
    return 0;
}