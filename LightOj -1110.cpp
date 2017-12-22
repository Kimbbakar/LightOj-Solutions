#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

string N1,N2;
//string ans;

string MAX(string a,string b)
{
    if(a.size()==b.size())
        return a<=b? a:b;
    else
        return a.size()>=b.size()? a:b;
}

vector<string>dp[110];
int sz1,sz2;
string LCS(int i,int j)
{
    if(N1[i]=='\0' || N2[j]=='\0')return "";
    if(dp[i][j].size()!=0)return dp[i][j];
    string ans="";
    if(N1[i]==N2[j])
    {

        ans=N1[i]+LCS(i+1,j+1);
    }
    else
    {
        string r1=LCS(i+1,j);
        string r2=LCS(i,j+1);
        ans=MAX(r1,r2);
    }
    dp[i][j]=ans;
    return dp[i][j];
}

vector<string>v;

int main()
{
    int t,tcase;
    while(scanf("%d",&t)==1)
    {
        tcase=1;
        while(t--)
        {
            cin>>N1>>N2;
            v.clear();
            for(int i=0;i<=105;i++)
            {
                dp[i].clear();
                for(int j=0;j<=105;j++)
                    dp[i].push_back("");
            }


            cout<<"Case "<<tcase++<<": ";
            string a=LCS(0,0);
            if(a=="")
                printf(":(\n");
            else
                cout<<a<<endl;
        }
    }
    return 0;
}
