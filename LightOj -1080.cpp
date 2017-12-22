// Lazy Loading without Propagation

#include <bits/stdc++.h>

#define l(i,n) for(int i=0;i<n;i++)

#define pii pair<int,int>
#define DB()    cout<<"I'm in!"<<endl

typedef long long LL;

using namespace std;

int tree[1000100];
string n;

void build(int at,int L,int R){
    if(L==R){
        tree[at]=(n[L-1]-'0');
        return;
    }

    int mid = (L+R)/2;

    build(at*2,L,mid);
    build((at*2)+1,mid+1,R);
}

void update(int at,int L,int R,int l,int r){
    if(r<L || l>R) return;
    if(l<=L && r>=R){
        tree[at]^=1;    // updating lazy in every node until I get it
        return;
    }

    int mid= (L+R)/2;
    update(at*2,L,mid,l,r);
    update( (at*2)+1,mid+1,R,l,r);
}

int query(int at,int L,int R,int idx){
    if(idx<L || idx>R) return 0;
    if(L==R) return tree[at];

    int mid=(L+R)/2;
    if(idx<=mid) return query(at*2,L,mid,idx)^tree[at]; // considering all the lazy value in the way
    else return query( (at*2)+1,mid+1,R,idx)^tree[at];
}

int main(){
//std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t;
    cin>>t;
    l(p,t){
        memset(tree,0,sizeof(tree));
        int q;
        cin>>n>>q;

        build(1,1,n.size());

        printf("Case %d:\n",p+1);
        l(i,q){
            char op;
            scanf(" %c",&op);
            if(op=='I'){
                int l,r;
                scanf("%d %d",&l,&r);
                update(1,1,n.size(),l,r);
            }
            else{
                int idx;
                scanf("%d",&idx);
                int ans=query(1,1,n.size(),idx);
                printf("%d\n",ans);
            }
        }
    }
return 0;
}
