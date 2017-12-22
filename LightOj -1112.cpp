#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
//vector<int>v(100005,0);
int v[100005]={0};
void update(int i,int value)
{
    while(i<=n)
    {
        v[i]+=value;
        i+=(i & -i);
    }
}
int query(int f,int l)
{
    int sum1 = 0;
    int sum2=0;
	while (l > 0){
		sum1 += v[l];
		l -= (l & -l);
	}
    f--;
	while (f > 0){
		sum2 += v[f];
		f -= (f & -f);
	}

	return (sum1-sum2);
}
int main()
{
    int test,t,m,i,j,sq,x,q,pos1,pos2,sum,I,J;
    //cin>>test;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        printf("Case %d:\n",t);
        scanf("%d %d",&n,&m);
        //vector<int>s(100005);
        int s[100005]={0};
        memset(v, 0, sizeof(v));
        for(i=1;i<=n;i++)
        {
                int y;
                //cin>>y;
                scanf("%d",&y);
                s[i]=y;
                update(i,y);
        }
        /*for(i=1;i<=n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;*/
        for(i=0;i<m;i++)
        {
            //cin>>q;
            scanf("%d",&q);
            if(q==1)
            {
                scanf("%d",&I);
                I++;
                x=-s[I];
                printf("%d\n",s[I]);
                s[I]=0;
                update(I,x);
                /*for(j=1;j<=n;j++)
                {
                     cout<<v[j]<<" ";
                }
                cout<<endl;*/
            }
            else if(q==2)
            {
                scanf("%d %d",&I,&J);
                I++;
                s[I]+=J;
                update(I,J);
                /*for(j=1;j<=n;j++)
                {
                     cout<<v[j]<<" ";
                }
                cout<<endl;*/
            }
            else if(q==3)
            {
                scanf("%d %d",&I,&J);
                I++;
                J++;
                sum=query(I,J);
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}
