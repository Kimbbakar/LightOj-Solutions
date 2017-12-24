#include<cstdio>
#include<string>
#include<iostream>


using namespace std;

int main()
{
    int t,tcase;
    long long num;
    string s;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        long long sum;
        while(t--)
        {
            cin>>s>>num;
            if(s[0]=='-')
                s.erase(s.begin());
            if(num<0)
                num*=-1;
            sum=0;
            for(int i=0;i<s.size();i++)
            {
                sum=sum*10+(s[i]-48);
                //printf("%d\n",sum);
                if(sum>=num)
                    sum=sum%num;
            }
            printf("Case %d: ",tcase++);
            if(sum==0)
                printf("divisible\n");
            else
                printf("not divisible\n");
        }
    }
    return 0;
}
