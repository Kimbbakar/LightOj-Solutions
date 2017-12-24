#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define X 112345
using namespace std;

bool arr[X+10],mark[X+10];
vector<int>prime;
int length;

void sieve()
{
    int i,j;
    arr[0]=1;
    arr[1]=1;
    for(i=2; i*i<=X; i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(j=i; i*j<=X; j++)
            {
                arr[i*j]=1;
            }
        }
    }
    for(;i<=X;i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}

int segmentedsieve(int low,int high)
{
    int counter=0,i;
    long long j;
    if(low==1)
    {
        low++;
    }
    if(low>high)
    {
        return counter;
    }
    memset(mark,0,sizeof mark);
    for(i=0;i<length&&prime[i]<=high;i++)
    {
        j=(low/prime[i])*prime[i];
        if(j<low)
        {
            j+=prime[i];
        }
        if(j<X&&arr[j]==0)
        {
            //cerr<<"JJ "<<j<<" "<<prime[i]<<endl;
            j+=prime[i];
        }
        for(;j<=high;j+=prime[i])
        {
            if(j<low)
            {
                break;
            }
            mark[j-low]=1;
            //cerr<<"marking "<<j<<" "<<low<<" "<<j-low<<endl;
        }
    }
    for(i=low;i<=high;i++)
    {
        if(i<low)
        {
            break;
        }
        if(mark[i-low]==0)
        {
            //cerr<<"HEY "<<i<<" "<<low<<" "<<i-low<<endl;
            counter++;
        }
    }
    return counter;
}


int main()
{
    sieve();
    length=prime.size();
    int test,low,high,i,j;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&low,&high);
        printf("Case %d: %d\n",i+1,segmentedsieve(low,high));

    }
    return 0;
}