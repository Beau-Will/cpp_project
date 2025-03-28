#include <bits/stdc++.h>
using namespace std;
int arr[1000005],n,k; 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&arr[i]);
    scanf("%d",&k);
    int left=1,right=n,mid;
    while(left<right)
    {
         mid=(left+right)/2;
         if(k<=arr[mid])
         right=mid;
         else
         left=mid+1;
    }
    if(arr[left]==k)
    cout<<left;
    else
    cout<<-1;
}