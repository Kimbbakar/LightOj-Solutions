 /*
 Problem name : 1427 - Substring Frequency (II)
 Algorithm : Aho-Corasick
 Contest/Practice :
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 27-Mar-18
 Last Update : 25-Mar-2015
*/

#include<bits/stdc++.h>

#define pause           system("pause"); 
#define mod             1000000007
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())//vector must be sorted
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
#define sf              scanf
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
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}
template<class T>
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);

    while(b) b ^= a ^= b ^= a %= b;
    return a;
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
 

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}

#define debug(args...) {dbg,args; cerr<<endl;}

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int nextInt() { int n; scanf("%d", &n); return n; }
long long nextLong() { long long n; scanf("%lld", &n); return n; }
void print(int n){ printf("%d", n); }
void println(int n){ printf("%d\n", n); }
void println(long long n){ printf("%lld\n", n); }



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
#define vlong ll

#define SZ sz
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR reset

const int Size = 1000005; /// Maximum Text Length
const int NODE = 250005; /// Maximum Nodes
const int MXQ = 505; /// Maximum Patterns
const int MXL = 505; /// Maximum Length Of Pattern
const int MXCHR = 26; /// Maximum Characters

struct node{
    int val;
    vector<int> endList; /// List of patterns ends here
    int endCnt; /// Number of times the prefix match with text
    int child[MXCHR];
    void clear(){
        CLR(child, 0);
        val = endCnt = 0;
        endList.clear();
    }
}trie[NODE];

int qfound[MXQ]; /// How many times i'th pattern matched
vector<int> lvlNodes; /// List of nodes sorted by level

struct AhoCorasick{
    int curNodeId, root, fail[NODE], par[NODE];

    void clear(){
        trie[root].clear();
        root = curNodeId = 0;
        lvlNodes.clear();
        CLR(qfound,0);
    }

    int getname(char ch){
        return (ch-'a');
    }

    void addTrie(string s, int id){
        /// Add string s to the trie in general way
        int len = SZ(s);
        int cur = root;
        FOR(i,0,len-1){
            int c = getname(s[i]);
            if(trie[cur].child[c] == 0){
                curNodeId++;
                trie[curNodeId].clear();
                trie[curNodeId].val = c;
                trie[cur].child[c] = curNodeId;
            }
            cur = trie[cur].child[c];
        }
        trie[cur].endList.pb(id);
    }

    void calcFailFunction(){
        queue<int> Q;
        Q.push(root);
        while(!Q.empty()){
            int s = Q.front();
            Q.pop();
            lvlNodes.pb(s);
            /// Add all the child to the queue:
            FOR(i,0,MXCHR-1){
                int t = trie[s].child[i];
                if(t != 0){
                    Q.push(t);
                    par[t] = s;
                }
            }

            if(s == 0){ /// Handle special case when s is root
                fail[s] = 0;
                par[s] = 0;
                continue;
            }

            /// Find fall back of s:
            int p = par[s];
            int val = trie[s].val;
            int f = fail[p];
            /// Fall back till you found a node who has got val as a child
            while(f != 0 && trie[f].child[val] == 0){
                f = fail[f];
            }
            fail[s] = trie[f].child[val];
            if(s == fail[s]) fail[s] = 0; /// Self fall back not allowed
        }
    }

    /// Returns the next state
    int goTo(int state, int c){
        if(trie[state].child[c] != 0){ /// No need to fall back
            return trie[state].child[c];
        }

        /// Fall back now:
        int f = fail[state];
        while(f != 0 && trie[f].child[c] == 0){
            f = fail[f];
        }
        return trie[f].child[c];
    }

    void pushUp(){ 
        int len = SZ(lvlNodes);
        ROF(i,0,len-1){
            int u = lvlNodes[i];
            int f = fail[u];  
            /// The prefix of my fall back node matches with my suffix
            /// So every time i match with text, my fall back node also match
            trie[f].endCnt += trie[u].endCnt;
            FOR(j,0,SZ(trie[u].endList)-1){
                int qid = trie[u].endList[j]; 
                qfound[qid] += trie[u].endCnt;
            }
        }
    }

    /// Iterate through the whole text and find all the matchings
    void findmatching(string s){
        int cur = root, idx = 0;
        int len = SZ(s);
        while(idx<len){
            int c = getname(s[idx]);
            int prv = cur;
            cur = goTo(cur, c);
            trie[cur].endCnt++;  
            idx++;
        }
        pushUp();
    }
}acorasick;



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
//        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int t,tcase=1,q;
    string s,k;
    AhoCorasick solve;

    in(t);

    while(t--){
        in(q);
        cin>>s;
        solve.clear();

        for(int i=1;i<=q;i++){
            cin>>k;  
            solve.addTrie(k,i);
        }

        solve.calcFailFunction();
        solve.findmatching(s);
        pf("Case %d:\n",tcase++);
        for(int i=1;i<=q;i++)
            pf("%d\n",qfound[i] );  

    }


    return 0;
}



