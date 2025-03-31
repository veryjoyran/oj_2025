#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void Merge(vector<int> &A,int &left,int &mid,int &right,int& sum)
{

    int n1=mid-left;
    int n2=right-mid;
    vector<int> L(n1+1),R(n2+1);
    for(int i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=A[mid+i];
    }

    L[n1]=2000000000;
    R[n2]=2000000000;

    int i=0,j=0;
    for(int k=left;k<right;k++)
    {
        sum++;
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }

}

void Merge_Sort(vector<int> &A,int &left,int &right,int &sum)
{
    if ((left+1)<right){
        int mid=(left+right)/2;
        Merge_Sort(A,left,mid,sum);
        Merge_Sort(A,mid,right,sum);
        Merge(A,left,mid,right,sum);
    }
}


int main()
{

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    int left=0;
    int right=n;
    Merge_Sort(arr,left,right,sum);
    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;
    cout<<sum<<endl;



    return 0;
}
