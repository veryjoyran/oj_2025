#include <bits/stdc++.h>

using namespace std;


struct Node
{
    int parent=-1;
    int left=-1;
    int right=-1;
};

void setDepth(vector<Node>& T,vector<int> &D,int u,int d)
{
    D[u]=d;
    if(T[u].left!=-1)
    {
        setDepth(T,D,T[u].left,d+1);
    }
    if(T[u].right!=-1)
    {
        setDepth(T,D,T[u].right,d);
    }
}

int main()
{

    int n;
    cin>>n;
    vector<Node> T(n);
    vector<int> D(n,0);

    int id,k,child;
    for(int i=0; i<n; i++)
    {
        int prev=-1;
        cin>>id>>k;
        for(int i=0; i<k; i++)
        {
            cin>>child;
            T[child].parent=id;
            if(i==0)
            {
                T[id].left=child;
            }
            else
            {
                T[prev].right=child;
            }
            prev=child;
        }
    }


    for(int i=0; i<n; i++)
    {
        if(T[i].parent==-1)
        {
            setDepth(T,D,i,0);
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<"node "<<i<<": parent = "<<T[i].parent<<", depth = "<<D[i]<<", ";
        if(T[i].parent==-1)
        {
            cout<<"root, ";
        }
        else if(T[i].left==-1)
        {
            cout<<"leaf, ";
        }
        else
        {
            cout<<"internal node, ";
        }
        cout<<"[";

        int next=T[i].left;
        if(next!=-1)
        {

            cout<<next;
            if(T[next].right!=-1)
                cout<<", ";

            while(T[next].right!=-1)
            {
                cout<<T[next].right;

                next=T[next].right;
                if(T[next].right!=-1)
                    cout<<", ";
            }
        }




        cout<<"]"<<endl;


    }

    return 0;
}
