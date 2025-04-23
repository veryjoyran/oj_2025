#include<bits/stdc++.h>

using namespace std;



void maxHeapify(vector<int> &A,int i,int n)
{
    int l=i*2;
    int r=i*2+1;
    int largest=-1;
    if(l<=n&&A[l]>A[i]) largest=l;
    else largest=i;

    if(r<=n&&A[r]>A[largest]) largest=r;

    if (largest!=i)
    {
        swap(A[largest],A[i]);
        maxHeapify(A,largest,n);
    }
}

void heapSort(vector<int> &A,int n)
{
    for(int i=n/2;i>0;i--)
        maxHeapify(A,i,n);

    int heapSize=n;
    while(heapSize>=2)
    {
        swap(A[1],A[heapSize]);
        heapSize--;
        maxHeapify(A,1,n);
    }
}

void update(vector<int>& A,int i)
{

    if(A[i/2]>A[i])
    {
        swap(A[i],A[i/2]);
        update(A,i/2);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> A(n+1);
    for(int i=1;i<=n;i++) cin>>A[i];

    sort(A.begin()+1,A.end());
    vector<int> H(n+1);
    for(int i=1;i<=n;i++)
    {
        update(H,i-1);
        H[i]=A[i];
        swap(H[1],H[i]);

    }
    for(int i=1;i<=n;i++) cout<<H[i]<<" ";
    cout<<endl;





    return 0;
}