#include<bits/stdc++.h>

using namespace std;


int main()
{

    int n,m,k;
    cin>>n>>m>>k;
    vector<int> A(n+1);
    vector<int> M(m+1);
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=m;i++)
        cin>>M[i];

    sort(A.begin(),A.end());
    sort(M.begin(),M.end());

    int id=1;
    int sum=0;

    for(int i=1;i<=n;i++)
    {
        while(id<=m&&A[i]-k>M[id])
            id++;

        if(abs(A[i]-M[id])<=k)
        {
            sum++;
            id++;
        }
    }

    cout<<sum<<endl;
    return 0;
}