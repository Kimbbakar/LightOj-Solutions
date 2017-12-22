 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 21-Dec-17
 Last Update : 25-Mar-2015
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#define pf              printf

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


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
//        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int t,n,tcase=1;
    int x[2];
    int y[2];
    int z[2];

    int ax,ay,az,bx,by,bz;

    in(t);

    while(t--){


        x[0]=y[0]=z[0] = 0;
        x[1]=y[1]=z[1] = 1<<29;
    
        in(n);

        while(n--){
            in(ax),in(ay),in(az);
            in(bx),in(by),in(bz);            

            x[0] = max(x[0],ax );
            x[1] = min(x[1],bx );

            y[0] = max(y[0],ay );
            y[1] = min(y[1],by );

            z[0] = max(z[0],az );
            z[1] = min(z[1],bz );
        }

        pf("Case %d: %d\n",tcase++,max(x[1]-x[0],0 ) * max(y[1]-y[0],0 ) * max(z[1]-z[0],0 ) );
    }


    return 0;
}



