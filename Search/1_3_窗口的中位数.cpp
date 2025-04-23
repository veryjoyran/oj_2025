#include<bits/stdc++.h>

using namespace std;


void add(multiset<int>& down,multiset<int>& up,int x)
{
    if(down.size()==up.size()) down.insert(x);
    else up.insert(x);

    if(!down.empty()&&!up.empty())
    {
        auto it=down.end();
        auto itt=up.begin();
        it--;
        int mx=*it;
        int mi=*itt;
        if(mx>mi)
        {
            down.erase(it);
            up.erase(itt);
            down.insert(mi);
            up.insert(mx);
        }
    }
}

void del(multiset<int>& down,multiset<int>& up,int x)
{
    auto it=up.find(x);
    if(it!=up.end()) up.erase(it);
    else
    {
        it=down.find(x);
        down.erase(it);
    }
    if(down.size()<up.size())
    {
        int mi=*up.begin();
        up.erase(up.begin());
        down.insert(mi);
    }
}

int getMid(multiset <int>& down)
{
    auto it=down.rbegin();
    return *it;
}

int main()
{

    int n,k;
    cin>>n>>k;
    vector<int> A(n+1);
    multiset<int> up,down;

    for(int i=1;i<=n;i++)
        cin>>A[i];

    for(int i=1;i<=k-1;i++)
        add(down,up,A[i]);

    for(int i=k;i<=n;i++)
    {
        add(down,up,A[i]);
        int mid=getMid(down);
        cout<<mid<<" ";
        del(down,up,A[i-k+1]);
    }
    cout<<endl;

    return 0;
}



