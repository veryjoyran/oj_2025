#include<bits/stdc++.h>

using namespace std;

//并非等分
int Partition(vector<int> & A,int p, int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    int temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;

    return i+1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n+1);
    arr[0]=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int p=1;

    int target=Partition(arr,p,n);
    for(int i=1;i<target;i++)
        cout<<arr[i]<<" ";

    cout<<"["<<arr[target]<<"] ";
    for(int i=target+1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
