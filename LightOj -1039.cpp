//light oj toy company

#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<cstdlib>
#include<iostream>
#define MAX 30000
#define hash_v 31
using namespace std;


//.....
int avoid_num;
string s,d;
vector<int>block(MAX);
vector<int>step(MAX);


void clr()
{
    for(int i=0;i<MAX;i++)
    {
        block[i]=0;
        step[i]=0;
    }
}

void input1()
{
    cin>>s;
    cin>>d;
}

void input2()
{
    scanf("%d",&avoid_num);
    string a,b,c;
    for(int t=1;t<=avoid_num;t++)
    {
        cin>>a>>b>>c;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                for(int k=0;k<c.size();k++)
                {
                    int value=(a[i]-'a')+(b[j]-'a')*hash_v+(c[k]-'a')*hash_v*hash_v;
                    block[value]=1;
                }
            }
        }
    }
}

string new_string(string nw,int pos,int direction)
{
    if(direction==1)
        nw[pos]=(nw[pos]+1)<=122?(nw[pos]+1):97;
    else
        nw[pos]=(nw[pos]-1)>=97?(nw[pos]-1):122;
    return nw;
}


int get_value(string nw)
{
    int value=(nw[0]-'a')+(nw[1]-'a')*hash_v+(nw[2]-'a')*hash_v*hash_v;
    return value;
}


int bfs()
{
    if(block[get_value(s)]==1)
        return -1;
    if(s==d)
        return 0;
    queue<string>q;
    string nw;
    q.push(s);
    step[get_value(s)]=1;
    while(!q.empty())
    {
        nw=q.front();
        q.pop();//cout<<"** "<<nw<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=1;j<=2;j++)
            {
                string get=new_string(nw,i,j);
                int value=get_value(get);

                if(block[value]==1)
                    continue;
                if(get==d)
                    return step[get_value(nw)];
                if(step[value]==0)
                {//cout<<get<<endl;system("pause");
                    step[value]=step[get_value(nw)]+1;
                    q.push(get);
                }
            }
        }
    }
    return -1;
}

void print(int c)
{
    printf("Case %d: %d\n",c,bfs());
}


int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            clr();
            input1();
            input2();
            print(tcase++);
        }
    }
    return 0;
}
