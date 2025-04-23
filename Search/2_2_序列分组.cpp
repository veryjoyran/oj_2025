#include<bits/stdc++.h>

using namespace std;

bool judge(const vector<int>& A,long long mid,int n,int k)
{

    int num=1;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(sum+A[i]>mid)
        {
            num++;
            sum=A[i];
        }
        else sum+=A[i];
    }
    if(num>k) return false;
    else return true;
}

int main()
{

    int n,k;
    cin>>n>>k;

    vector<int> A(n+1);
    long long sum=0;
    int mx=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        sum+=A[i];
        mx=(A[i]>mx)?A[i]:mx;
    }

    long long l=mx,r=sum;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(judge(A,mid,n,k))
        {
            r=mid;
        }
        else l=mid+1;
    }

    cout<<l<<endl;




    return 0;
}



