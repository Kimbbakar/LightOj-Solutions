#include<stdio.h>
#include<math.h>

int main()
{
    long long a,b,c;
    long long num;
    scanf("%lld",&num);
    long long i;
    if(num<=200){
        for(i=0;i<num;i++){
            scanf("%lld%lld%lld",&a,&b,&c);
            if(c>=a && c>=b){
                int X=(a*a)+(b*b);
                int Z=(c*c);
                if(X==Z){
                    printf("Case %lld: yes\n",(i+1));
                }
                else{
                    printf("Case %lld: no\n",(i+1));
                }
            }
            else if(b>=a && b>=c){
                int X=(a*a)+(c*c);
                int Z=(b*b);
                if(X==Z){
                    printf("Case %lld: yes\n",(i+1));
                }
                else{
                    printf("Case %lld: no\n",(i+1));
                }
            }
            else if(a>=b && a>=c){
                int X=(c*c)+(b*b);
                int Z=(a*a);
                if(X==Z){
                    printf("Case %lld: yes\n",(i+1));
                }
                else{
                    printf("Case %lld: no\n",(i+1));
                }
            }
        }
    }
    return 0;
}
