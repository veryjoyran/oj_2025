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

    vector<PIL> A(n+1);

    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i].first>>A[i].second;
        sum+=A[i].second;
    }

    sort(A.begin()+1,A.end(),PILCpmpare());

    long long cur=0;
    long long f_sum=0;

    for(int i=1;i<=n;i++)
    {
        cur+=A[i].first;
        f_sum+=cur;
    }

    cout<<sum-f_sum<<endl;




    return 0;
}