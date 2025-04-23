#include<bits/stdc++.h>

using namespace std;



int main()
{

    int n,k;
    cin>>n>>k;

    vector<int> A(n+1);

    for(int i=1;i<=n;i++)
        cin>>A[i];

    sort(A.begin(),A.end());

    int l=1,r=n;
    int sum=0;
    while(l<=r)
    {
        if(l==r&&A[l]<=k)
        {
            sum++;
            break;
        }
        else if(A[r]+A[l]>k)
        {
            sum++;
            r--;
        }
        else
        {
            sum++;
            r--;
            l++;
        }
    }
    cout<<sum<<endl;




    return 0;
}



