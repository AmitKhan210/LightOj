#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,taka;
    string a;
    scanf("%lld",&t);
    for(long long i=1;i<=t;i++)
    {
        long long sum=0;
        scanf("%d",&n);
        printf("Case %lld:\n", i);

        for(long long j=1;j<=n;j++)
        {
            cin >> a;


           if(a == "donate")
           {
               scanf("%lld",&taka);
               sum=sum+taka;
           }
           else if(a == "report")
            printf("%lld\n",sum);

        }
    }
    return 0;
}
