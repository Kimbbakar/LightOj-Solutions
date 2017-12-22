#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    int t,tcase,r,c;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            scanf("%d %d",&r,&c);
            printf("Case %d: ",tcase++);
            if(r==1 ||c==1)
                printf("%d\n",r*c);
            else if( (r==2 && c<=3) || (r<=3 && c==2) )
                printf("%d\n",4);
            else if(r==2)
            {
                if(c%4<=2)
                    printf("%d\n",(r*c)-4*(c/4 ));
                else
                    printf("%d\n",(r*c)-4*(c/4 )-2);

            }
            else if(c==2)
            {
                if(r%4<=2)
                    printf("%d\n",(r*c)-4*(r/4 ));
                else
                    printf("%d\n",(r*c)-4*(r/4 )-2);

            }
            else (r*c)%2==0?printf("%d\n",(r*c)/2):printf("%d\n",(r*c)/2+1);
        }
    }
    return 0;
}
