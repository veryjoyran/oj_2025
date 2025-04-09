#include <bits/stdc++.h>

using namespace std;

int getValue(const vector<int>& A,int G_min)
{
    int n=A.size();
    int value=0;
    int mmin=1e5;
    for(int i=0; i<n; i++)
    {
        value+=A[i];
        if(A[i]<mmin)
            mmin=A[i];
    }


    value+=(n-2)*mmin;

    int cost=2*(mmin+G_min)-(n-1)*(mmin-G_min);

    return (cost>0?value:value+cost);


}

int main()
{

    int n;
    cin >> n;
    vector<int> A(n);
    int G_min=1e5;
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
        if(A[i]<G_min)
            G_min=A[i];
    }
    vector<int> A_sorted=A;
    sort(A_sorted.begin(),A_sorted.end());

    vector<bool> visited(n,false);

    vector<int> T(10001);

    for(int i=0; i<n; i++)
    {
        T[A_sorted[i]]=i;
    }

    int ans=0;

    for(int i=0; i<n; i++)
    {
        if(visited[i])
            continue;


        else
        {
            int cur=i;
            vector<int> temp;
            while(true)
            {
                visited[cur]=true;
                int val=A[cur];
                temp.push_back(val);
                cur=T[val];


                if(visited[cur])
                    break;

            }
            ans+=getValue(temp,G_min);

        }
    }
    cout<<ans<<endl;


    return 0;
}
