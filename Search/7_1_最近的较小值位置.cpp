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

    for(int i=1;i<=n;i++)
    {
        cin>>A[i].first;
        A[i].second=i;
    }

    stack<PIL> Ans;

    for(int i=1;i<=n;i++)
    {

        while(!Ans.empty()&&Ans.top().first>=A[i].first)
        {
            Ans.pop();
        }
        if(Ans.empty())
        {
            cout<<"0 ";

        }
        else
        {
            int t=Ans.top().second;
            cout<<t<<" ";
        }

        Ans.push(A[i]);


    }







    return 0;
}