#include<bits/stdc++.h>

using namespace std;

vector<int> parent;

int Find(int x)
{
    int root=x;
    while(parent[root]!=root)
    {
        root=parent[root];
    }

    while(x!=root)
    {
        int next=parent[x];
        parent[x]=root;
        x=next;
    }

    return root;
}

void unite(int x,int y)
{
    int rootX=Find(x);
    int rootY=Find(y);
    if(rootX!=rootY)
        parent[rootY]=rootX;
}
bool connected(int x,int y)
{
    return Find(x)==Find(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin>>n>>m;

    parent.resize(n,0);

    for(int i=0;i<n;i++)
        parent[i]=i;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        unite(x,y);
    }


    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int x,k;
        cin>>x>>k;
        cout<<(connected(x,k)?"yes":"no")<<endl;
    }













    return 0;
}