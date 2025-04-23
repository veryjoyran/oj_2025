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

    vector<int> A(n+1);
    for(int i=1;i<=n;i++)
        cin>>A[i];

    sort(A.begin()+1,A.end());

    long long sum=0;
    for(int i=1;i<=n-1;i++)
        sum+=A[i];

    if(sum<A[n]) cout<<2*A[n]<<endl;
    else cout<<sum+A[n]<<endl;




    return 0;
}