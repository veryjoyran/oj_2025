#include <bits/stdc++.h>

using namespace std;

int getMaxSequence(const string &X,const string &Y)
{
    int n1=X.size();
    int n2=Y.size();


    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n1][n2];
}

int main()
{
    int n;
    cin >> n;

    string X,Y;


    for(int i=0;i<n;i++)
    {
        cin>>X>>Y;

        cout<<getMaxSequence(X,Y)<<endl;
    }

    return 0;
}