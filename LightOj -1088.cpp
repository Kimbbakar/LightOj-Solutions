#include<cstdio>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>


using namespace std;

vector<int>v;
int n,q;

int main()
{
    int t,tcase;
    int num,a,b;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d %d",&n,&q);
            v.clear();
            for(int i=0;i<n;i++)
            {
                scanf("%d",&num);
                v.push_back(num);
            }
            printf("Case %d:\n",tcase++);
            vector<int>::iterator x,y;
            while(q--)
            {
                scanf("%d %d",&a,&b);
                x=lower_bound(v.begin(),v.end(),a);
                y=upper_bound(v.begin(),v.end(),b);
                    printf("%d\n",(y-v.begin())-(x-v.begin()) );
            }
        }
    }

    return 0;
}
