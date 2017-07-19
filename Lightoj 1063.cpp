#include<bits/stdc++.h>
using namespace std;
#define mx 10005
vector<int>g[mx];
int visited[mx];
bool articulation[mx];
int low[mx],d[mx],parent[mx];
int t;
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
      //  if(v==parent[s]) continue;
        if(visited[v])
        {
            low[s]=min(low[s],d[v]);
        }
        if(!visited[v])
        {
            parent[s]=v;
            articulating(v,false);

            if(d[s]<=low[v]&&!root)
            {
                articulation[s]=true;
            } low[s]=min(low[s],low[v]);
            child++;
        }
        if(child>1&&root)
        {
            articulation[s]=true;
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
            t=0;
        }
        int n,m;
        scanf("%d%d",&n,&m);
        int u,v;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1; i<=n; i++)
        {
            if(visited[i]==0) articulating(i,true);

        }
        int co=0;
        for(int i=1; i<=n; i++)
        {
            if(articulation[i])
            {
                co++;
            }
        }
        cout<<"Case "<<cs<<": "<<co<<endl;
    }
}
