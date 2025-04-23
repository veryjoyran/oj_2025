#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PIL;

typedef long long ll;

bool judge(const vector<int>& A,ll x,int t,int n)
{
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=x/A[i];
        if(sum>=t) return true;
    }
    if(sum>= t) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,t;
    cin>>n>>t;

    vector<int> A(n+1);
    for(int i=1;i<=n;i++)
        cin>>A[i];

    ll l=0,r=1e18;


    while(l<r)
    {
        ll mid=(l+r)/2;

        if(judge(A,mid,t,n)) r=mid;
        else l=mid+1;

    }

    cout<<l<<endl;



    return 0;
}