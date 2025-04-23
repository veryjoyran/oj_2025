#include<bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin>>n;
    vector<vector<int>> A(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        int u,k;
        cin>>u>>k;
        for(int j=1;j<=k;j++)
        {
            int col;
            cin>>col;
            A[i][col]=1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }





    return 0;
}