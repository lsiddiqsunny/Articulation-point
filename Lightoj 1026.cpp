#include<bits/stdc++.h>
using namespace std;
#define mx 10005
vector<int>g[mx];
int visited[mx];
bool articulation[mx];
int low[mx],d[mx],parent[mx];
int t;
vector<pair<int,int> > bridges;
void articulating(int s,bool root)
{
    t++;
    low[s]=d[s]=t;
    visited[s]=1;
    int child=0;
    //cout<<"here"<<endl;
    for(int i=0; i<g[s].size(); i++)
    {
        int v=g[s][i];
        if(v==parent[s]) continue;
        if(visited[v])
        {
            low[s]=min(low[s],d[v]);
        }
        if(!visited[v])
        {
            parent[v]=s;
            articulating(v,false);

            if(d[s]<low[v])
            {
                bridges.push_back(make_pair(min(s,v),max(s,v)));
            }
            low[s]=min(low[s],low[v]);

        }
        else
        {
            low[s] = min(low[s], d[v]);
        }


    }

}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        for(int i=0; i<mx; i++)
        {
            g[i].clear();
            visited[i]=articulation[i]=low[i]=d[i]=parent[i]=0;
            bridges.clear();
            t=0;
        }
        int n,m;
        scanf("%d",&n);
        cout<<"Case "<<cs<<":\n";
        if(n==0)
        {
            printf("0 critical links\n",cs);
            continue;
        }
        int u,v;
        for(int i=0;i<n;i++){
                   int node, deg;
            scanf("%d (%d)", &node, &deg);
            for (int k=0, x; k<deg; ++k){
                scanf("%d", &x);
                g[node].push_back(x); ;
            }
        }
        for(int i=0; i<n; i++)
        {


            if(visited[i]==0) articulating(i,true);

        }
       sort(bridges.begin(), bridges.end());
        printf("%d critical links\n", bridges.size());
        for(int i=0;i<bridges.size();i++){
            printf("%d - %d\n", bridges[i].first,bridges[i].second);
        }


    }
}

