#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int length,n;
    cin>>length>>n;

    set<int> pos;
    multiset<int> road;

    pos.insert(0);
    pos.insert(length);

    road.insert(length);

    for(int i=0;i<n;i++)
    {
        int target;
        cin>>target;

        auto it=pos.upper_bound(target);

        int r=*it;
        it--;
        int l=*it;

        pos.insert(target);


        road.erase(road.find(r-l));
        road.insert(target-l);
        road.insert(r-target);

        cout<<*(road.rbegin())<<" ";

    }
    cout<<endl;


    return 0;
}



