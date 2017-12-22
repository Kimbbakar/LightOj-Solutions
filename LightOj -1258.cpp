#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#define B 31
#define mod 9999991
using namespace std;

int mod_value(int a)
{
    return (a%mod+mod)%mod;
}

int main()
{
    string s1,s2;
    int pow_value,t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            cin>>s1;
            pow_value=1;
            s2=s1;
            reverse(s2.begin(),s2.end());
            int h1=0,h2=0;
            long long len=0;
            long long sz=s1.size();
            int i=sz-1,j=0;
            while(i>=0)
            {

                h1=mod_value(h1*B);
                h1=mod_value(h1+s1[i]);
                h2=mod_value(h2+mod_value(s2[j]*pow_value));
                pow_value=((pow_value%mod)*(B%mod))%mod;
                //printf("%d %d\n",h1,h2);
                if(h1==h2) len=j;
                i--,j++;
            }
            sz=sz+(sz-len-1);
            printf("Case %d: %lld\n",tcase++,sz);
        }
    }

    return 0;
}
