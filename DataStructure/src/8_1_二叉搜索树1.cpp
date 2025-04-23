#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l=-1;
    int r=-1;
    int p=-1;
    int value=0;
};

void Preorder(const vector<Node>& T,int u)
{
    if(u==-1)
        return;

    cout<<T[u].value<<" ";
    Preorder(T,T[u].l);
    Preorder(T,T[u].r);
}

void Inorder(const vector<Node>& T,int u)
{
    if(u==-1)
        return;

    Inorder(T,T[u].l);
    cout<<T[u].value<<" ";
    Inorder(T,T[u].r);
}

void Insert(vector<Node> & T,const Node& z,int& root)
{

    T.push_back(z);
    int n=T.size()-1;
    int y=-1;
    int x=root;
    while(x!=-1)
    {
        y=x;
        if(z.value<T[x].value)
            x=T[x].l;
        else
            x=T[x].r;
    }

    T[n].p=y;

    if(y==-1)
    {
        root=n;
    }
    else if(z.value<T[y].value)
    {
        T[y].l=n;
    }
    else
    {
        T[y].r=n;
    }
}

int main()
{

    int n;
    cin>>n;




    vector<Node> T;

    int root=-1;

    for(int i=0;i<n;i++)
    {
        string op;
        cin>>op;
        if(op=="insert")
        {
            Node z;
            cin>>z.value;
            Insert(T,z,root);
        }
        else
        {
            Inorder(T,root);
            cout<<endl;
            Preorder(T,root);
        }
    }





    return 0;
}
