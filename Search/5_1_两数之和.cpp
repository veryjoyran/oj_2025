#include<bits/stdc++.h>

using namespace std;


typedef pair<int,int> PIL;

struct PILCompare{
    bool operator ()(const PIL& p1,const PIL& p2) const
    {
        return p1.first<p2.first;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<PIL> A(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>A[i].first;
        A[i].second=i;
    }


    sort(A.begin()+1,A.end(),PILCompare());

    int l=1,r=n;
    bool flag=true;

    while(l<r)
    {
        int ans=A[l].first+A[r].first;

        if(ans<k) l++;
        else if(ans>k) r--;
        else
        {
            cout<<A[l].second<<" "<<A[r].second<<endl;

            flag=false;
            break;
        }
    }

    if(flag)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }




    return 0;
}