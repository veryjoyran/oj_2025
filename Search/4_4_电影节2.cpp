#include<bits/stdc++.h>

using namespace std;


typedef pair<int,int> PIL;

struct PILCompare{
    bool operator ()(const PIL& p1,const PIL& p2) const
    {
        return p1.second<p2.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    cin>>n>>k;




    vector<PIL> p(n+1);

    for(int i=1;i<=n;i++)
        cin>>p[i].first>>p[i].second;


    sort(p.begin()+1,p.end(),PILCompare());



    int sum=0;

    multiset<int> cur;

    for(int i=1;i<=k;i++)
        cur.insert(0);

    for(int i=1;i<=n;i++)
    {
        auto it=cur.upper_bound(p[i].first);

        if(it==cur.begin()) continue;

        else
        {
            it--;
            cur.erase(it);
            cur.insert(p[i].second);
            sum++;

        }
    }

    cout<<sum<<endl;




    return 0;
}