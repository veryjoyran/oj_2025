#include<bits/stdc++.h>

using namespace std;



vector<vector<int>> adj;
vector<int> d;
vector<int> f;
vector<bool> visited;

int currentTime=1;

void dfs(int u)
{
    d[u]=currentTime;
    currentTime++;

    visited[u]=true;
    for(auto v:adj[u])
    {
        if(!visited[v])dfs(v);
    }

    f[u]=currentTime;
    currentTime++;



}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    adj.resize(n+1);
    d.resize(n+1,0);
    f.resize(n+1,0);
    visited.resize(n+1,false);

    for(int i=1;i<=n;i++)
    {
        int u,k;
        cin>>u>>k;

        adj[u].resize(k);
        for(int j=0;j<k;j++)
            cin>>adj[u][j];

        sort(adj[u].begin(),adj[u].end());
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i]) dfs(i);
    }

    for(int i=1;i<=n;i++)
        cout<<i<<" "<<d[i]<<" "<<f[i]<<endl;






    return 0;
}