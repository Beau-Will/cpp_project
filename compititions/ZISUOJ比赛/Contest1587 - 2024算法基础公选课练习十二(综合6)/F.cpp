#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, mod = 998244353;
queue <int> q;
vector <int> e[N];
int f[N];
int T, n, m, cnt1, cnt2;
long long ans;
long long p(int x)
{   long long res=1,kk=2;
    while(x)
    {   if(x & 1) { res*=kk; res%=mod;}
        kk*=kk;
        kk%=mod;
        x=x>>1;
    }
    return res;
}
int main()
{
    cin>>T;
    while(T--)
    {   scanf("%d%d",&n,&m);
        ans=1;
        for(int i=1;i<=n;i++)
        {   f[i]=-1; e[i].clear();  }
        for(int i=1;i<=m;i++)
        {   int x,y;
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {   if(f[i]!=-1) continue;
            cnt1=1;cnt2=0; f[i]=1;
            q.push(i);
            while(!q.empty())
            {   int u=q.front(); 
                q.pop();
                for(int j=0;j<e[u].size();j++)
                {   int v=e[u][j];
                    if(f[v]==-1)
                    {   f[v]=3-f[u];
                        if(f[v]==1) cnt1++;
                            else cnt2++;
                        q.push(v);
                    }
                    else if(f[v]!=3-f[u])
                            { ans=0; break;     }
                }
                  
            }
            if(ans==0) break;
            ans=ans*(p(cnt1)%mod+p(cnt2)%mod)%mod;
        }
        printf("%lld\n",ans);       
    }
 return 0;
}