#include<bits/stdc++.h>

using namespace std;



int main()
{

    int n,m;
    cin>>n>>m;
    multiset<int> M;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        M.insert(num);
    }

    for(int i=0;i<m;i++)
    {
        if(M.empty())
        {
            cout<<"-1"<<endl;
            continue;
        }
        int val;
        cin>>val;
        auto it=M.upper_bound(val);
        if(it!=M.begin())
        {
            it--;
            cout<<*it<<endl;
            M.erase(it);
        }
        else cout<<"-1"<<endl;
    }


    return 0;
}



