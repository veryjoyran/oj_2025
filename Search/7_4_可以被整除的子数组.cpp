#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n ;

    vector<long long> cnt(n+1);
    cnt[0]=1;
    long long a,sum =0,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        sum=(a%n+sum+n)%n;
        ans+=cnt[sum];
        cnt[sum]++;
    }
    cout<<ans;

    return 0;
}
