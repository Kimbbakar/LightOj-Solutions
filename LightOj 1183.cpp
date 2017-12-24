#include<cstdio>
#include<vector>
using namespace std;
class my
{
    public:
    long long sum,lazy;
};
#define MAX 100009
vector<my>tree(MAX*3);

void build(int nod,int fast,int last)
{
    if(fast==last)
    {
        tree[nod].sum=0;
        tree[nod].lazy=-1;
        return;
    }
    int mid=(fast+last)/2;
    int left=2*nod;
    int right=2*nod+1;
    build(left,fast,mid);
    build(right,mid+1,last);
    tree[nod].sum=tree[left].sum+tree[right].sum;
    tree[nod].lazy=-1;
}

void update(int nod,int fast,int last,int i,int j,int value)
{
    if(fast>j || last<i) return ;
    if(fast<=i && last>=j)
    {
        tree[nod].lazy=value;
        tree[nod].sum=(j-i+1)*value;
        //printf("nod=%d sum=%lld lazy=%lld\n",nod,tree[nod].sum,tree[nod].lazy);
        return;
    }
    int mid=(i+j)/2;
    int left=2*nod;
    int right=2*nod+1;
    if(tree[nod].lazy!=-1){
        //printf("nod=%d l=%d r=%d lazy=%lld\n",nod,left,right,tree[nod].lazy);
        tree[left].lazy=tree[right].lazy=tree[nod].lazy;
        tree[left].sum=(mid-i+1)*tree[left].lazy;
        tree[right].sum=(j-mid)*tree[right].lazy;
        tree[nod].lazy=-1;
    }
    //if(last<=mid)update(left,fast,last,i,mid,value);
    //if(fast>mid)update(right,fast,last,mid+1,j,value);
    update(left,fast,last,i,mid,value);
    update(right,fast,last,mid+1,j,value);
    tree[nod].sum=tree[left].sum+tree[right].sum;
}
int query(int nod,int fast,int last,int i,int j)
{
    if(fast>j || last<i) return 0;
    else if(fast<=i && last>=j)
    {
        //printf("%d = %lld %d (%d %d),(%d,%d)\n",nod,tree[nod].sum,value,fast,last,i,j);
        return tree[nod].sum;
    }
    int mid=(i+j)/2;
    int left=2*nod;
    int right=2*nod+1;
    //if(fast>mid) query(right,fast,last,mid+1,j,tree[nod].lazy);
    //else if(last<=mid) query(left,fast,last,i,mid,tree[nod].lazy);
    if(tree[nod].lazy!=-1){
        tree[left].lazy=tree[right].lazy=tree[nod].lazy;
        tree[left].sum=(mid-i+1)*tree[left].lazy;
        tree[right].sum=(j-mid)*tree[right].lazy;
        tree[nod].lazy=-1;
    }
    long long r1=query(left,fast,last,i,mid);
    long long r2=query(right,fast,last,mid+1,j);
    tree[nod].sum=tree[left].sum+tree[right].sum;
    return r1+r2;
}
long long gcd( long long a, long long b )
{
    if( !b ) return a;
    return gcd( b, a%b );
}
int main()
{
    int i,j,t,tcase=1,m,n;
    scanf("%d",&t);
    int a,b,c,d;
    while(t--)
    {
        scanf("%d %d",&m,&n);
        printf("Case %d:\n",tcase++);
        build(1,0,m-1);
        while(n--)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(a==1){
                scanf("%d",&d);
                update(1,b,c,0,m-1,d);
            }
            else{
                long long result=query(1,b,c,0,m-1);
                if(result%(c-b+1)==0) printf("%lld\n",result/(c-b+1));
                else {
                    long long k=gcd(result,(long long)(c-b+1));
                    if((long long)(c-b+1)/k==1) printf("%lld\n",result/k);
                    else
                    printf("%lld/%lld\n",result/k,(c-b+1)/k);
                }
            }
        }
    }
    return 0;
}


