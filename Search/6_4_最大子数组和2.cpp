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

    int n,l,r;
    cin>>n>>l>>r;

    map<long long,int> mp;
    vector<long long> pre(n+1);

    long long ans=-1e18;

    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        pre[i]=pre[i-1]+a;

        if(i>=l) mp[pre[i-l]]++;

        if(i>r)
        {
            mp[pre[i-r-1]]--;
            if(mp[pre[i-r-1]]==0) mp.erase(pre[i-r-1]);
        }

        if(!mp.empty()) ans=max(ans,pre[i]-mp.begin()->first);
    }

    cout<<ans<<endl;




    return 0;
}