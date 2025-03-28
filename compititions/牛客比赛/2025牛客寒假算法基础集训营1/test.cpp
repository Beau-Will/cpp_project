#include<stdio.h>
#include<string.h>
int const maxx=30000010;
int ans[maxx];
int main()
{
    memset(ans,0,sizeof(ans));
    for(int i=1;i<maxx/2;i++)
    {
        for(int a=i+i;a<maxx;a=a+i)
        {
            int b=a^i;
            if((a-b)==i) ans[a]++;
        }
    }
    for(int i=1;i<maxx;i++)
        ans[i]=ans[i]+ans[i-1];
    int q,num=1;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",num++,ans[n]);
    }
    return 0;
}

