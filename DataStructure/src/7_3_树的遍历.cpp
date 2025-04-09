#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l=-1;
    int r=-1;
    int p=-1;
};


void Preorder(const vector<Node>& T,int u)
{

    if(u==-1)
        return;

    cout<<u<<" ";
    Preorder(T,T[u].l);
    Preorder(T,T[u].r);

}

void Inorder(const vector<Node> &T,int u)
{
    if(u==-1)
        return;

    Inorder(T,T[u].l);
    cout<<u<<" ";


    Inorder(T,T[u].r);
}

void Postorder(const vector<Node> & T,int u)
{
    if(u==-1)
        return;

    Postorder(T,T[u].l);
    Postorder(T,T[u].r);
    cout<<u<<" ";
}

int main()
{

    int n;
    cin>>n;
    vector<Node> T(n);
    for(int i=0;i<n;i++)
    {
        int id;
        cin>>id;
        cin>>T[id].l>>T[id].r;
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

    cout<<"Preorder"<<endl;
    Preorder(T,root);
    cout<<endl;

    cout<<"Inorder"<<endl;
    Inorder(T,root);
    cout<<endl;


    cout<<"Postorder"<<endl;
    Postorder(T,root);
    cout<<endl;






    return 0;
}
