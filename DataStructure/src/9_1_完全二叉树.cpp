#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key=0;
    int parent_key=-1;
    int left_key=-1;
    int right_key=-1;

};

bool isLegal(int key,int n)
{
    if(key>0&&key<=n) return true;
    return false;
}




int main()
{
    int n;
    cin>>n;
    vector<Node> T(n+1);
    for(int i=1;i<=n;i++) cin>>T[i].key;

    for(int i=1;i<=n;i++)
    {
        int parent=i/2;
        int left=2*i;
        int right=2*i+1;

        cout<<"node "<<i<<": key = "<<T[i].key<<", ";

        if(isLegal(parent,n)) cout<<"parent key = "<<T[parent].key<<", ";
        if(isLegal(left,n)) cout<<"left key = "<<T[left].key<<", ";
        if(isLegal(right,n)) cout<<"right key = "<<T[right].key<<", ";

        cout<<endl;
    }


    return 0;
}