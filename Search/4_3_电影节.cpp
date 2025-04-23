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

    int n;
    cin>>n;

    vector<PIL> p(n+1);

    for(int i=1;i<=n;i++)
        cin>>p[i].first>>p[i].second;

    sort(p.begin()+1,p.end(),PILCompare());

    int sum=0,cur=0;

    for(int i=1;i<=n;i++)
    {

        if(cur<=p[i].first)
        {
            sum++;
            cur=p[i].second;
        }
        else continue;
    }

    cout<<sum<<endl;




    return 0;
}