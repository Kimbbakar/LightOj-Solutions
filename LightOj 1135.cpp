#include<cstdio>
#include<vector>
using namespace std;

#define MAX 100009
class nods
{
    public:
    long long lazy,ara[3];
};
vector<nods>tree(MAX*4);
void move(int nod)
{
    long long temp=tree[nod].ara[2];
    tree[nod].ara[2]=tree[nod].ara[1];
    tree[nod].ara[1]=tree[nod].ara[0];
    tree[nod].ara[0]=temp;
}
void prop(int nod,int n)
{
    int left=2*nod;
    int right=left+1;
    tree[left].lazy+=tree[nod].lazy;
    tree[right].lazy+=tree[nod].lazy;
    while(n--)
    {
        move(left);
        move(right);
    }
    tree[nod].ara[0]=tree[left].ara[0]+tree[right].ara[0];
    tree[nod].ara[1]=tree[left].ara[1]+tree[right].ara[1];
    tree[nod].ara[2]=tree[left].ara[2]+tree[right].ara[2];
    tree[nod].lazy=0;
}

void build(int nod,int fast,int last)
{
    if(fast==last)
    {
        tree[nod].ara[0]=1;
        tree[nod].ara[1]=tree[nod].ara[2]=tree[nod].lazy=0;
        return;
    }
    int left=nod*2;
    int right=left+1;
    int mid=(fast+last)/2;
    build(left,fast,mid);
    build(right,mid+1,last);
    tree[nod].ara[0]=tree[left].ara[0]+tree[right].ara[0];
    tree[nod].ara[1]=tree[left].ara[1]+tree[right].ara[1];
    tree[nod].ara[2]=tree[left].ara[2]+tree[right].ara[2];
    tree[nod].lazy=0;
}
void update(int nod,int fast,int last,int i,int j)
{
    if(fast>j || last<i) return;
    else if(fast<=i && last>=j)
    {
        tree[nod].lazy++;
        if(i==j)
        {
            move(nod);
            tree[nod].lazy=0;
        }
        else{
            prop(nod,tree[nod].lazy%3);
        }
        return;
    }
    int mid=(i+j)/2;
    int left=nod*2;
    int right=left+1;
    if(tree[nod].lazy!=0)
    {
        prop(nod,tree[nod].lazy%3);
    }
    update(left,fast,last,i,mid);
    update(right,fast,last,mid+1,j);
    tree[nod].ara[0]=tree[left].ara[0]+tree[right].ara[0];
    tree[nod].ara[1]=tree[left].ara[1]+tree[right].ara[1];
    tree[nod].ara[2]=tree[left].ara[2]+tree[right].ara[2];
}

long long query(int nod,int fast,int last,int i,int j)
{
    if(fast>j || last<i) return 0;
    else if(fast<=i && last>=j)
    {
        if(i!=j && tree[nod].lazy!=0){
            prop(nod,tree[nod].lazy%3);
        }

        return tree[nod].ara[0];
    }
    int mid=(i+j)/2;
    int left=nod*2;
    int right=left+1;
    if(tree[nod].lazy!=0)
    {
        prop(nod,tree[nod].lazy%3);
    }
    long long r1=query(left,fast,last,i,mid);
    long long r2=query(right,fast,last,mid+1,j);
    return r1+r2;
}

int main()
{
    int i,j,m,n,t,tcase=1;
    int a,b,c;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d %d",&m,&n);
            build(1,0,m-1);
            printf("Case %d:\n",tcase++);
            while(n--)
            {
                scanf("%d %d %d",&a,&b,&c);
                if(a==0)
                {
                    update(1,b,c,0,m-1);
                }
                else{
                    printf("%lld\n",query(1,b,c,0,m-1));
                }
            }
        }
    }
    return 0;
}
