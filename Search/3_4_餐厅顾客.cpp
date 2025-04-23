#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PIL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    vector<PIL> p(n+1);

    vector<int> A;

    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
        A.push_back(p[i].first);
        A.push_back(p[i].second);
    }

    sort(A.begin(),A.end());

    int A_size=A.size();

    vector<int> d(A_size+1,0);

    for(int i=1;i<=n;i++)
    {
        int start=p[i].first;
        int endd=p[i].second;

        int a=lower_bound(A.begin(),A.end(),start)-A.begin()+1;
        int b=lower_bound(A.begin(),A.end(),endd)-A.begin()+1;

        d[a]++;
        d[b+1]--;


    }

    int ans=0;
    for(int i=1;i<=A_size;i++)
    {
        d[i]+=d[i-1];
        ans=max(ans,d[i]);
    }

    cout<<ans<<endl;

    return 0;
}