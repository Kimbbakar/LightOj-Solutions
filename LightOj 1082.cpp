#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

int min_v=10000007;
vector<int>num(100010);
vector<int>pos(100010);
vector<int>mn(100010);
vector<pair<int,int> >p(1000);
void input(int m)
{
    int i,j=1,c=0,fst=1;
    int srt=sqrt(m);
    for(i=1;i<=m;i++){
        scanf("%d",&num[i]);
        pos[i]=j;
        c++;
        if(min_v>num[i])min_v=num[i];
        if(c==srt){
            c=0;
            mn[j]=min_v;
            p[j]=make_pair(fst,i);
            j++;
            min_v=10000007;
            fst=i+1;
        }
    }
    mn[j]=min_v;
    p[j]=make_pair(fst,m);
}
int result(int m,int a,int b)
{
    int i,j;
    min_v=10000007;
    if(a==b) return num[a];
    else if(pos[a]==pos[b]){
        for(i=a;i<=b;i++){
            if(num[i]<min_v){
               min_v=num[i];
            }
        }
        return min_v;
    }
    else{
        for(i=a;i<=p[pos[a]].second;i++){
            if(num[i]<min_v) min_v=num[i];
        }
        for(i=pos[a]+1;i<pos[b];i++){
            if(mn[i]<min_v){
                min_v=mn[i];
            }
        }
        for(i=p[pos[b]].first;i<=b;i++){
            if(num[i]<min_v) min_v=num[i];
        }
        return min_v;
    }
}
int main()
{
    int i,j,k,t,tcase=1,m,n,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        input(m);
        printf("Case %d:\n",tcase++);
        while(n--)
        {
           scanf("%d %d",&x,&y);
           printf("%d\n",result(m,x,y));
        }
    }
    return 0;
}
