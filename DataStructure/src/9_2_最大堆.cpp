#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key=0;
    int parent_key=-1;
    int left_key=-1;
    int right_key=-1;

};



void maxHeapify(vector<Node> &T,int i,int n)
{
    int l=2*i;
    int r=2*i+1;
    int largest=0;
    if(l<=n&&T[l].key>T[i].key) largest=l;
    else largest=i;

    if(r<=n&&T[r].key>T[largest].key) largest=r;

    if (largest!=i)
    {
        Node temp=T[largest];
        T[largest]=T[i];
        T[i]=temp;
        maxHeapify(T,largest,n);

    }
}

void buildMaxHeap(vector<Node> &T,int n)
{
    for(int i=n/2;i>0;i--) maxHeapify(T,i,n);
}


int main()
{
    int n;
    cin>>n;
    vector<Node> T(n+1);
    for(int i=1;i<=n;i++) cin>>T[i].key;

    buildMaxHeap(T,n);

    for(int i=1;i<=n;i++) cout<< T[i].key<<" ";
    cout<<endl;




    return 0;
}