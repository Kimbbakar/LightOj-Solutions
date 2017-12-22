
    #include<stdio.h>
    int main() {
        long long n,caseno = 0,cases,fn[10005];
        scanf("%lld",&cases);
        while( cases-- ) {
            scanf("%lld%lld%lld%lld%lld%lld%lld",&fn[0],&fn[1],&fn[2],&fn[3],&fn[4],&fn[5],&n);
              for(int i=6;i<=n;i++)
              fn[i]=(fn[i-1]+fn[i-2]+fn[i-3]+fn[i-4]+fn[i-5]+fn[i-6])%10000007;
     
            printf("Case %lld: %lld\n", ++caseno, fn[n]% 10000007);
        }
        return 0;
    }
