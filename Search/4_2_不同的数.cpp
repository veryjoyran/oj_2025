#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PIL;

typedef long long ll;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;

    set<int> s;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);

    }

    cout<<s.size()<<endl;

    return 0;
}