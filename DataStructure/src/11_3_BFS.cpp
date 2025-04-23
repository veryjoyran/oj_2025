#include<bits/stdc++.h>

using namespace std;



vector<vector<int>> adj;
queue<int> q;


vector<int> dis;




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    adj.resize(n+1);
    dis.resize(n+1,-1);


    for(int i=1;i<=n;i++)
    {
        int u,k;
        cin>>u>>k;

        adj[u].resize(k);
        for(int j=0;j<k;j++)
            cin>>adj[u][j];

        sort(adj[u].begin(),adj[u].end());
    }


    dis[1]=0;
    q.push(1);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(dis[v]==-1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout<<i<<" "<<dis[i]<<endl;










    return 0;
}