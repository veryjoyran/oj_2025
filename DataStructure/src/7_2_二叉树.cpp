#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l=-1;
    int r=-1;
    int p=-1;
    int s=-1;
    int deg=0;
    int dep=0;
    int h=0;

};

int getHeight(vector<Node> &T,int u)
{
    if(u==-1)
    {
        return -1;
    }
    int left_h=getHeight(T,T[u].l);
    int right_h=getHeight(T,T[u].r);
    T[u].h=max(left_h,right_h)+1;

    return T[u].h;

}

int main()
{

    int n;
    cin>>n;
    vector<Node> T(n);
    int id;
    for(int i=0;i<n;i++)
    {
        cin>>id>>T[id].l>>T[id].r;

        if(T[id].l!=-1)
        {
            T[T[id].l].p=id;
        }
        if(T[id].r!=-1)
        {
            T[T[id].r].p=id;
        }
    }

    int root=-1;
    for(int i=0;i<n;i++)
    {
        if(T[i].p==-1)
        {
            root=i;
            break;
        }
    }

    getHeight(T,root);

    for(int i=0;i<n;i++)
    {
        int p=T[i].p;
        if(p!=-1)
        {
            T[i].s=(T[p].l==i)?T[p].r:T[p].l;
        }
        T[i].deg=(T[i].l!=-1)+(T[i].r!=-1);
    }

    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(T[u].l!=-1)
        {
            T[T[u].l].dep=T[u].dep+1;
            q.push(T[u].l);
        }
        if(T[u].r!=-1)
        {
            T[T[u].r].dep=T[u].dep+1;
            q.push(T[u].r);
        }
    }

    for(int i=0;i<n;i++)
    {
        string type;
        if(T[i].p==-1)
        {
            type="root";
        }
        else if(T[i].deg==0)
        {
            type="leaf";
        }
        else
        {
            type="internal node";
        }
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
               i, T[i].p, T[i].s, T[i].deg,
               T[i].dep, T[i].h);

        cout<<type<<endl;

    }



    return 0;
}
