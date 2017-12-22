#include<bits/stdc++.h>

#define pf printf
#define sz(x) (x.size())
#define pb push_back

typedef long long ll;
typedef unsigned long long llu;

using namespace std;


template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

/******* ! Code start from here ! *******/

class nod
{
public:
    int F,S,P;

    bool operator <(const nod& a ) const
    {
        return (F==a.F)?(S<a.S ):(F<a.F);
    }
};

int pos[20][3*5004] ; // after every sort state of suffix
int sf_rank[3*5004]; // rank of i'th suffix
int suffix_array[3*5004]; // suffix position for i'th rank
int lcp[3*5004]; // lcp[i] = lcp(i,i+1)
nod taple[3*5004];
string s;
int n;

void build_suffix_array()
{
    for(int i=0;i<n;i++)
    {
        pos[0][i] =s[i]-'a';
    }

    for(int p=1,i=1;p<n;p*=2,i++)
    {
        for(int j=0;j<n;j++)
        {
            taple[j].F=pos[i-1][j];
            taple[j].S=(j+p<n?pos[i-1][j+p]:-1 );
            taple[j].P=j;
        }

        sort(taple,taple+n);

        for(int j=0;j<n;j++)
        {
            pos[i][ taple[j].P ]=(j>0 && taple[j].F==taple[j-1].F && taple[j].S==taple[j-1].S ) ?pos[i][taple[j-1].P] :j;

            suffix_array[pos[i][ taple[j].P ]]=taple[j].P;
        }

    }

   for(int j=0;j<n;j++)
        sf_rank[suffix_array[j] ]=j ;

//    for(int j=0;j<n;j++)
//    {
//        pf("%d ",suffix_array[j] );
//        cout<<s.substr(suffix_array[j],n);
//        cout<<endl;
//    }

}

void build_lcp()
{
    for(int i=0,k=0;i<n;i++,(k>0)?k--:k )
    {
        if(sf_rank[i]==n-1 )
        {
            lcp[i] =0;
            continue;
        }

        int j=suffix_array[sf_rank[i]+1 ];

        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;

        lcp[i]=k;
    }
}



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;
    int p,q;

    in(t);
    int a,b,c;
    string g;

    while(t--)
    {
        cin>>s;

        a=sz(s);
        s.pb('$');

        cin>>g;
        s+=g;
        b=sz(g);
        s.pb('*');

        cin>>g;
        s+=g;
        c=sz(g);
        s.pb('@');

        n=a+b+c+3;


        build_suffix_array();
        build_lcp();

        int res=0;
        bool x,y,z;

        for(int i=0;i<n-2;i++)
        {
            int l=min(lcp[suffix_array[i] ],lcp[suffix_array[i+1] ] );



            x=(suffix_array[i]<a || suffix_array[i+1]<a || suffix_array[i+2]<a );
            y=((suffix_array[i]<=b+a && suffix_array[i]>a ) || (suffix_array[i+1]<=b+a && suffix_array[i+1]>a ) || (suffix_array[i+2]<=b+a && suffix_array[i+2]>a ) );
            z=(suffix_array[i]>a+b+1   || suffix_array[i+1]>a+b+1  || suffix_array[i+2]>a+b+1  );

//            pf("%d %d %d (%d %d %d) %d\n",suffix_array[i],suffix_array[i+1],suffix_array[i+2],x,y,z,l );
            if(x && y && z)
            {
                res=max(res,l);
            }
        }


        pf("Case %d: %d\n",tcase++,res);

    }


    return 0;
}


