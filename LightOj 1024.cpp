/*
 Problem name : 1024-Eid
 Algorithm : BigInt + LCM
 Contest/Practice :
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 01-Apr-15
 Last Update : 27-Feb-2015
*/

/*
"   নয়ন তোমারে পায় না দেখিতে, রয়েছ নয়নে নয়নে।
     হৃদয় তোমারে পায় না জানিতে, হৃদয়ে রয়েছ গোপনে ॥
বাসনার বশে মন অবিরত         ধায় দশ দিশে পাগলের মতো,
     স্থির-আঁখি তুমি মরমে সতত জাগিছ শয়নে স্বপনে ॥
সবাই ছেড়েছে, নাই যার কেহ,  তুমি আছ তার আছে তব স্নেহ--
     নিরাশ্রয় জন, পথ যার গেহ, সেও আছে তব ভবনে।
তুমি ছাড়া কেহ সাথি নাই আর,সমুখে অনন্ত জীবনবিস্তার--
     কালপারাবার করিতেছ পার কেহ নাহি জানে কেমনে ॥
জানি শুধু তুমি আছ তাই আছি,    তুমি প্রাণময় তাই আমি বাঁচি,
     যত পাই তোমায় আরো তত যাচি, যত জানি তত জানি নে।
জানি আমি তোমায় পাব নিরন্তর      লোকলোকান্তরে যুগযুগান্তর--
     তুমি আর আমি মাঝে কেহ নাই, কোনো বাধা নাই ভুবনে ॥ "

*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

typedef long long ll;
typedef unsigned long long llu;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    return num;
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}

template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}

template<class T>
inline void debug(string S1,T S2,string S3)
{
    cout<<S1<<S2<<S3;
}

template<class T>
inline T in()
{
    register char c=0;
    register T num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    return n?-num:num;
}

/*...... ! Code start from here ! ......*/





#define MAX 10000

int isprime[MAX/32 + 5];
vector<int>prime;

#define on1(x,w)  isprime[x]=isprime[x]|(1<<w)
#define check1(x,w) (isprime[x]&(1<<w))

int p,q,cnt;
string multiply( string a, int b ) {
    // a contains the biginteger in reversed form
    int carry = 0;
    reverse(all(a) );
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    reverse(all(a) );
    return a;
}

inline void bit_mask_sieve()
{

    memset(isprime,0,sizeof(isprime) );
    cnt=0;
    prime.pb(2);
    int ls=sqrt(MAX);
    for(int i=3;i<=MAX;i+=2)
    {
        p=i/32;
        q=i%32;
        if(!check1(p,q))
        {
            prime.pb(i);
            for(ll j=(ll) i*(ll)i;i<=ls && j<=(ll) MAX;j+=(2*(ll) i) )
            {
                p=(j)/32;
                q=(j)%32;
                on1(p,q);
            }
        }
    }

}

string tos(int x)
{
    string s;

    while(x>0)
    {
        s.pb(x%10+'0');
        x/=10;
    }

    reverse(all(s) );

    return s;
}

int sot(string x)
{
    int v=0;

    for(int i=0;i<sz(x);i++ )
    {
        v=v*10+(x[i]-'0' );
    }

    return v;
}


int main()
{
 //    std::ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif



    bit_mask_sieve();

    int t,tcase=1,n,num;
    char ch;

    t=in<int>();

    string x,res,z;
    int a,v;
    int fac[10008];
    while(t--)
    {
        cin>>n;

        reset(fac,0);

        res="1";

        for(int i=1;i<=n;i++)
        {   scanf("%d",&num);

            a=num;

            int j=0;


            int c=0;


            int ls=sqrt(a);
            v=prime[j];

            while( j<sz(prime) && a>1 && prime[j]<=ls)
            {
              //  printf("a= %d prime[j]= %d c= %d\n",a,prime[j],c );

                if(a%v==0)
                {
                    c++;
                    a=a/v;
                }
                else
                {
                    if(c>fac[prime[j]])
                    {
                        int k=fast_pow(prime[j],c-fac[prime[j]] );

                        res=multiply(res,k) ;
                        fac[prime[j]]=max(fac[prime[j]],c);
                    }
//printf("Res: "),cout<<res<<endl;
                    fac[prime[j]]=max(fac[prime[j]],c);
                    c=0;
                    j++;
                    v=prime[j];
                    ls=sqrt(a );
                }
            }
//what_is("********")
            if(c>fac[prime[j]])
            {
                int k=fast_pow(prime[j],c-fac[prime[j]] );
                res=multiply(res,k) ;
                fac[prime[j]]=max(fac[prime[j]],c);
            }


            if(fac[a ]==0)
            {
                fac[a]=1;
                res=multiply(res,a);//what_is(a)printf("Res: "),cout<<res<<endl;
            }
        }

        cout<<"Case "<<tcase++<<": "<<res<<"\n";

    }

    return 0;
}


