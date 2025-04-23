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

    int n,x;
    cin>>n>>x;

    vector<int> A(n+1);

    for(int i=1;i<=n;i++)
        cin>>A[i];

    int ans=0,sum=0;
    int r=1;
    for(int l=1;l<=n;l++)
    {
        while(r<=n&&sum<x)
        {

            sum+=A[r];
            r++;
        }
        if(sum==x) ans++;
        sum-=A[l];
    }

    cout<<ans<<endl;







    return 0;
}