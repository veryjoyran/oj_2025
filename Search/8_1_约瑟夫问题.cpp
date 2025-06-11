#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    queue<int> q;

    for(int i=1;i<=n;i++)
        q.push(i);

    while(!q.empty())
    {

        if(!q.empty())
        {
            int t=q.front();
            q.pop();
            q.push(t);
        }
        cout<<q.front()<<" ";
        q.pop();

    }



    return 0;
}
