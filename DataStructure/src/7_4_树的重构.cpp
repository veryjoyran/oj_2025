#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l=-1;
    int r=-1;
};

void Postorder(const vector<Node> & T,int u)
{
    if(u==-1)
        return;

    Postorder(T,T[u].l);
    Postorder(T,T[u].r);
    cout<<u<<" ";
}

int build(int l1,int r1,int l2,int r2,vector<Node>& T,const vector<int>& pre,const vector<int> &in)
{
    if(l1>r1)
        return -1;

    int root=pre[l1];
    int in_root=0;
    int n=pre.size();
    for(int i=0;i<n;i++)
    {
        if(in[i]==root)
        {
            in_root=i;
            break;
        }
    }

    T[root].l=build(l1+1,l1+in_root-l2,l2,in_root-1,T,pre,in);
    T[root].r=build(r1-(r2-in_root)+1,r1,in_root+1,r2,T,pre,in);
    return root;
}
int main()
{

    int n;
    cin>>n;

    vector<int> pre(n+1);
    vector<int> in(n+1);
    for(int i=1;i<n+1;i++)
        cin>>pre[i];
    for(int i=1;i<n+1;i++)
        cin>>in[i];

    vector<Node> T(n+1);

    int root=pre[1];

    build(1,n,1,n,T,pre,in);

    Postorder(T,root);

    return 0;
}
