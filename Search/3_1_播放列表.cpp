#include<bits/stdc++.h>

using namespace std;



int main()
{

    int n;
    cin>>n;
    vector<int> A(n+1);
    for(int i=1;i<=n;i++)
        cin>>A[i];

    set<int> s;

    int ans=0;
    for(int i=1,j=1;i<=n;i++)
    {
        while(s.count(A[i])>0)
        {
            s.erase(A[j]);
            j++;
        }
        s.insert(A[i]);
        ans=max(ans,int(s.size()));
    }
    cout<<ans<<endl;



    return 0;
}



