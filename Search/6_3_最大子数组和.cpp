#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PIL;
struct PILCpmpare{
    bool operator () (const PIL&p1,const PIL&p2) const{
        return p1.first<p2.first;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;


    vector<long long> A(n+1);

    for(int i=1;i<=n;i++)
        cin>>A[i];


    vector<long long> dp(n+1,0);

    long long ans=-1e18;

    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i-1]+A[i],A[i]);
        ans=max(ans,dp[i]);

    }

    cout<<ans<<endl;




    return 0;
}