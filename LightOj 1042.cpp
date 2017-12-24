#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

char s[10000000];
void rev()
{
    int i,len=strlen(s)-1;
    char a;
    for(i=0;i<=len/2;i++){
        a=s[i];
        s[i]=s[len-i];
        s[len-i]=a;
    }
}
void bin(unsigned long long n)
{
    unsigned long long i=0,j;

    while(n!=0){
        s[i++]=48+n%2;
        n=n/2;
    }
    s[i++]='0';
    s[i]='\0';
    rev();
}


unsigned long long dec()
{
    int i;
    unsigned long long n=0,a=1;
    for(i=strlen(s)-1;i>=0;i--){
        n+=((s[i]-48)*a);
        a*=2;
    }
    return n;
}

int main()
{
    int i,j,k,t,tcase=1,l;
    unsigned long long n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%llu",&n);
        bin(n);
        l=strlen(s);
        next_permutation(s,s+l);
        m=dec();
        printf("Case %d: %llu\n",tcase++,m);
    }
    return 0;
}

