#include<cstdio>
#include<queue>
#include<vector>
#include<cctype>

using namespace std;
int xa[]={0,1,0,-1};
int ya[]={1,0,-1,0};

int main()
{
	int i,j,k,m,n,a,b,t,tcase=1,p,q;
	char graph[15][15];
	int taken[15][15];
	int keep[15][15];
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		queue<int>x;
		queue<int>y;
		int num=0;
		for(i=0;i<n;i++){
			scanf("%s",graph[i]);
			for(j=0;j<n;j++){
				taken[i][j]=0;
				if(graph[i][j]=='A'){
					x.push(i);
					y.push(j);
					taken[i][j]=1;
				}
				if(graph[i][j]>='A' && graph[i][j]<='Z') num++;
                keep[i][j]=0;
			}
		}
		int count='A',ans=0,flag=0,c=1;
//		printf("%d\n",num);
		while(!x.empty()){
            p=x.front();
            q=y.front();
           // printf("<<%c>>\n",graph[p][q]);
            x.pop();
			y.pop();
		    keep[p][q]=1;
			for(i=0;i<4;i++){
				a=p+xa[i];
				b=q+ya[i];
                if((graph[a][b]=='.' || graph[a][b]<=count+1) && graph[a][b]!='#' && keep[a][b]==0 && a>=0 && a<n && b>=0 && b<n){
                    keep[a][b]=1;
                    taken[a][b]=taken[p][q]+1;
                    //printf("%c %c \n",count,graph[a][b]);
                    if(graph[a][b]==count+1){
                        count++;
                        if(count==num+64){
                            ans=taken[a][b]-1;
                            flag=1;
                            break;
                        }
                        for(j=0;j<n;j++){
                            for(k=0;k<n;k++) keep[j][k]=0;
                        }
                        while(!x.empty()){
                            x.pop();
                            y.pop();
                        }
                        x.push(a);
                        y.push(b);
                        break;
                    }
                    x.push(a);
                    y.push(b);
                }
			}
			if(flag==1) break;
		}
		//printf("%d\n",count);
		printf("Case %d: ",tcase++);
		if(count==num+64) printf("%d\n",ans);
		else printf("Impossible\n");
	}
	return 0;
}
