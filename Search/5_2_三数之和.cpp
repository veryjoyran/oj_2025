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


    bool g_flag=false;
    bool flag=false;

    for(int i=1;i<=n;i++)
    {
        int new_k=k-A[i].first;
        int l=1,r=n;
        while(l<r)
        {
            
            if(l==i) l++;
            if(r==i) r--;
            
            if(l==r) break;
        
            
            int ans=A[l].first+A[r].first;

            if(ans<new_k) l++;
            else if(ans>new_k) r--;
            else
            {
                cout<<A[l].second<<" "<<A[r].second<<" "<<A[i].second<<endl;

                g_flag=true;
                flag=true;
                break;
            }
        }
        if(flag)
            break;


    }

    if(!g_flag)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }







    return 0;
}