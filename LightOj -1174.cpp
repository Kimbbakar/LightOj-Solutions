
    #include <iostream>
    #include <cstdio>
    #include <queue>
    #include <vector>

    using namespace std;

    vector <int > edge[105];

    queue <int > q;

    int BFS(int s, int d,int vr[]){


        int test[105]={0};

        test[s]=1;

        int dis[105];
        dis[s] = 0;
        q.push(s);

        while(!q.empty()){

            int u = q.front();

            for( int i = 0 ; i <  edge[u].size() ; i++ ){

                int v = edge[u][i];

                //vr.push_back();

                if( test[v] == 0 ){

                    dis[v] = dis[u] + 1;

                    test[v] = 1;

                    vr[v] += dis[v];
                    //cout<<vr[v]<<endl;

                    q.push(v);

                }

            }

            q.pop();

        }

        return 0;

    }

    int main()
    {
        int res,tc,n,r,s,d,j;
        cin>>tc;

        for(int i=0;i<tc;i++){
            cin>>n>>r;
            int vr[105];
            for(j=0;j<=n;j++){
                edge[j].clear();
            }
            for(j = 0 ;j < r; j++){
                int num1,num2;
                cin>>num1>>num2;
                edge[num1].push_back(num2);
                edge[num2].push_back(num1);

            }
            cin>>s>>d;
            //int ara[105];
            for (j = 0 ;j<105; j++) vr[j]=0;

            int sss = BFS(s,d,vr);

            int ddd = BFS(d,s,vr);

            //vector <int > ::iterator it;
            int max =  vr[0];
            for(j = 0; j < n ; j++){
                if(max<vr[j]) {
                    max = vr[j];
                    //sss = j;
                }
            }

            cout<<"Case "<<i+1<<": "<<max<<endl;

        }

        return 0;
    }

