//Segment tree with lazy popagretion
// Ai code korte voi lagtese :P
//kichukkon por GF aisa kaner kache pen pen korbe -_-

#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>
#define MAX 200007

using namespace std;


class my
{
    public:
        int color;
};

vector<my>tree(3*MAX);
vector<int>point(3*MAX);
vector<int>data(3*MAX);

void build()
{
    for(int i=0;i<3*MAX;i++)
    {
        tree[i].color=-1;
        point[i]=0;
        data[i]=0;
    }
}

void insert_segment(int nod,int i,int j,int mn,int mx,int color)
{
    if(i<=mn && mx<=j)
    {
        tree[nod].color=color;
        return;
    }
    else if(mn>j || mx<i)
        return;
    int mid=(mn+mx)/2;
    int left=2*nod;
    int right=2*nod+1;
    if(tree[nod].color!=-1)
    {
        tree[left].color=tree[nod].color;
        tree[right].color=tree[nod].color;
        tree[nod].color=-1;
    }
    insert_segment(left,i,j,mn,mid,color);
    insert_segment(right,i,j,mid+1,mx,color);
}

int get_1(int x,int mn,int mx)
{
    int mid;
    while(mn<=mx)
    {
        mid=(mx+mn)/2;
        if(data[mid]==x)return mid;
        else if(data[mid]>x)
            mx=mid-1;
        else
            mn=mid+1;
    }
}

void get_2(int nod,int mn,int mx)
{
    if(tree[nod].color!=-1)
        point[tree[nod].color]=1;
    else
    {
        int mid=(mn+mx)/2;
        int left=2*nod;
        int right=2*nod+1;
        if(tree[nod].color!=-1)
            point[tree[nod].color]=1;
        get_2(left,mn,mid);
        get_2(right,mid+1,mx);
    }
}


int main()
{
    int t,tcase,n;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d",&n);
            vector<pair<int,int> >segment(n);
            int c1=0,c2=0;
            build();
            for(int i=0;i<n;i++)
            {
                scanf("%d %d",&segment[i].first,&segment[i].second);
                point[c1++]=segment[i].first;
                point[c1++]=segment[i].second;
            }
            sort(point.begin(),point.begin()+c1);
            data[c2++]=point[0];
            for(int i=1;i<c1;i++)
            {
                if(point[i]!=point[i-1])
                {
                    data[c2++]=point[i];
                }
            }
            for(int i=0;i<n;i++)
            {
                insert_segment(1,get_1(segment[i].first,0,c2-1),get_1(segment[i].second,0,c2-1),0,c2-1,i+1);
            }
            for(int i=0;i<c1;i++)
            {
                point[i]=0;
            }
            get_2(1,0,c2-1);
            int ans=0;
            for(int i=0;i<3*MAX;i++)
                ans+=point[i];
            printf("Case %d: %d\n",tcase++,ans);
        }
    }
    return 0;
}
