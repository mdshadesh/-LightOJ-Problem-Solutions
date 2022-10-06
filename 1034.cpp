
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

vector<int>adj[100010];
bool visited[10010];
stack<int>stk;

void dfs1(int node)
{
    visited[node]=true;

    for(int next:adj[node])
    {
        if(visited[next]==false)
            dfs1(next);
    }

    stk.push(node);
}

void dfs2(int node)
{
    visited[node]=true;

    for(int next:adj[node])
    {
        if(visited[next]==false)
            dfs2(next);
    }

    //stk.push(node);
}

void init()
{
    for(int i=0;i<100010;i++)
        adj[i].clear();

    fill(visited,visited+10010,false);

    while(!stk.empty())
        stk.pop();

}

int main()
{
    //freopen("LightOj1034.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        init();

        int nodes,edges;
        scanf("%d %d",&nodes,&edges);

        for(int j=1;j<=edges;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);

            adj[a].push_back(b);
        }

        fill(visited,visited+10010,false);

        for(int j=1;j<=nodes;j++)
            if(visited[j]==false)
                dfs1(j);

        fill(visited,visited+10010,false);

        int con_comp=0;
        int siz=stk.size();

        for(int j=0;j<siz;j++)
        {
            int now=stk.top();
            stk.pop();

            if(visited[now]==false)
            {
                con_comp++;
                dfs2(now);
            }
        }

        printf("Case %d: %d\n",i,con_comp);

    }

    return 0;
}


