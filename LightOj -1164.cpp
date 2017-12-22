#include<cstdio>
#include<vector>
#include<map>
#include<utility>
#include<cmath>
using namespace std;

vector< long long>num(100009);
vector<long long>sum(100009);
vector<long long>s_sum(100009);
vector<long long>count(100009);
map<long long,pair<long long,long long> >maps;
vector<long long>color(100009);
void clr(long long m)
{
    maps.clear();
    num.clear();
    long long i;
    for(i=0;i<=m;i++){
        sum[i]=0;
        num[i]=0;
        color[i]=0;
        s_sum[i]=0;
        count[i]=0;
    }
}
void input(long long m)
{
    long long i,a,j=0,fst=0;
    long long c=1;
    long long srt=sqrt(m);
    clr(m);
    for(i=0;i<m;i++)
    {
        color[i]=c;
        j++;
        if(j==srt)
        {
            maps[c]=make_pair(fst,i);
            count[c]=j;
            fst=i+1;
            j=0;
            c++;
        }

    }
    if(j!=srt)
    {
        maps[c]=make_pair(fst,i-1);
        count[c]=j;
    }
}
void update(long long a,long long b,long long n)
{
    long long i,j;
    if(a==b) num[a]+=n,s_sum[color[a]]+=n;
    else if(color[a]==color[b] || color[a]+1==color[b])
    {
        for(i=a;i<=b;i++)
        {
            num[i]+=n;
            s_sum[color[i]]+=n;
        }
    }
    else
    {
        //printf("test\n");
        for(i=a;i<=maps[color[a]].second;i++)
        {
            num[i]+=n;
            s_sum[color[i]]+=n;
        }
        //printf("%d\n",s);
        for(i=color[a]+1;i<color[b];i++){
            sum[i]+=n;
        }
        //printf("%d\n",s);
        for(i=maps[color[b]].first;i<=b;i++)
        {
            num[i]+=n;
            s_sum[color[i]]+=n;
        }
        //printf("%d\n",s);
    }
    /*for(i=0;i<10;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    */
}

long long task(long long a,long long b,long long m)
{
    long long i,j;
    long long s=0;
    if(a==b) return (num[a]+sum[color[a]]);
    else if(color[a]==color[b] || color[a]+1==color[b])
    {
        for(i=a;i<=b;i++)
        {
           s+=(num[i]+sum[color[i]]);
        }
        return s;
    }
    else
    {
        //printf("test\n");
        for(i=a;i<=maps[color[a]].second;i++)
        {
            s+=(num[i]+sum[color[i]]);
        }
        //printf("%d\n",s);
        for(i=color[a]+1;i<color[b];i++){
            s+=(count[color[i]]*sum[i]+s_sum[i]);
        }
        //printf("%d\n",s);
        for(i=maps[color[b]].first;i<=b;i++)
        {
            s+=(num[i]+sum[color[i]]);
        }
        //printf("%d\n",s);
        return s;
    }
}

int main()
{
    long long i,j,t,tcase=1,m,n,x,y,z,a;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&m,&n);
        input(m);
        long long srt=sqrt(m);
        printf("Case %lld:\n",tcase++);
        while(n--)
        {
            //for(i=0;i<m;i++)printf("%d ",num[i]);
            //printf("\n");
            scanf("%lld",&x);
            if(x==0)
            {
                scanf("%lld %lld %lld",&y,&z,&a);
                update(y,z,a);

            }
            else{
                scanf("%lld %lld",&y,&z);
                printf("%lld\n",task(y,z,m));
            }
        }
    }
    return 0;
}
