#include<cstdio>
#include<vector>

using namespace std;

vector<long long>num;
vector<long long>pro;

void input(long long n)
{
    num.clear();
    pro.clear();
    long long i,j,p=n-1;
    for(i=1;i<=n;i++){
        scanf("%lld",&j);
        num.push_back(j);
        pro.push_back(p);
        p-=2;
    }
}


long long quary()
{
    long long i,j,k;
    long long sum=0;
    for(i=0;i<num.size();i++){
        sum+=(num[i]*pro[i]);
    }
    return sum;
}

int main()
{
    long long a,b,c,i,j,m,n,t,tcase=1,sum;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&m,&n);
        input(m);
        sum=quary();
        printf("Case %lld:\n",tcase++);
        while(n--){
            scanf("%d",&a);
            if(a==0){
                scanf("%lld %lld",&b,&c);
                sum-=num[b]*pro[b];
                num[b]=c;
                sum+=num[b]*pro[b];
            }
            else printf("%lld\n",sum);
        }
    }
    return 0;
}
