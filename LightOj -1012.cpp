#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int x_axe[]={0,1,0,-1};
int y_axe[]={1,0,-1,0};

int main()
{
    int flag_1[25][25];
    char grap[25][25];
    int i,j,count,flag,n,m,a,b,t,tcase=1,w,h,p,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&w,&h);
        queue<int>x;
        queue<int>y;
        count=flag=0;
        //printf("%d %d\n",w,h);
        for(i=0;i<h;i++){
            scanf("%s",grap[i]);
            for(j=0;j<w;j++){
                //printf("What\n");
                flag_1[i][j]=0;
                if(grap[i][j]=='@'){
                     m=j;
                     n=i;
                }
            }
        }
        x.push(m);
        y.push(n);
        count++;
        flag_1[n][m]=1;
        while(!x.empty()){
            m=x.front();
            n=y.front();
            //printf("<%d %d>\n",n+1,m+1);
            for(i=0;i<4;i++){
                if((m+x_axe[i]>=0 && m+x_axe[i]<w) && (n+y_axe[i]>=0 && n+y_axe[i]<h) && flag_1[n+y_axe[i]][m+x_axe[i]]==0 && grap[n+y_axe[i]][m+x_axe[i]]!='#'){
                    x.push(m+x_axe[i]);
                    y.push(n+y_axe[i]);
                    flag_1[n+y_axe[i]][m+x_axe[i]]=1;
                    //printf("%d %d\n",n+y_axe[i]+1,m+x_axe[i]+1);
                    count++;
                }
            }
            x.pop();
            y.pop();
        }
        printf("Case %d: %d\n",tcase++,count);
    }
    return 0;
}
