#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int num[30009];
int tree[4*30009];
int i,t,tcase=1,n;
int ans;
int u,v;
void build(int nod,int l,int r)
{
    if(l==r)
    {
        tree[nod]=l;
        return;
    }

    int mid=(l+r)>>1;
    int left=nod<<1;
    int right=left|1;

    build(left,l,mid);
    build(right,mid+1,r);

    if(num[tree[left]]<=num[tree[right] ] )
        tree[nod]=tree[left];
    else
        tree[nod]=tree[right];
}

void qu(int nod,int l,int r)
{
    if(l>v || r<u) return;
    if(u<=l && r<=v)
    {
        if(num[tree[nod]]<=num[ans ] )
            ans=tree[nod];
        return;
    }

    int mid=(l+r)>>1;
    int left=nod<<1;
    int right=left|1;

    qu(left,l,mid);
    qu(right,mid+1,r);


}

int area;
void find_area(int first,int last)
{

    if(first==last){
        if(area<num[first])
            area=num[first];
    }
    else if(first<last)
    {
        ans=first;
        u=first;
        v=last;
        qu(1,0,n-1);
        int mn_idx=ans;
        int len=last-first+1;
        area=max(area, len* num[mn_idx]);
        find_area(first,mn_idx-1);
        find_area(mn_idx+1,last);
    }

}
template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}



int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        area=0;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);

        build(1,0,n-1);
        find_area(0,n-1);
        printf("Case %d: %d\n",tcase++,area);
    }
    return 0;
}
