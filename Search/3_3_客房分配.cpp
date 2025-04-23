#include<bits/stdc++.h>

using namespace std;

struct Person{
    int id;
    int a;
    int b;
};

bool Pcomare(const Person& A,const Person& B)
{
    return A.a<B.a;
}

typedef pair<int,int> PIL;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    vector<Person> A(n+1);

    for(int i=1;i<=n;i++)
    {
        A[i].id=i;
        cin>>A[i].a>>A[i].b;
    }

    sort(A.begin()+1,A.end(),Pcomare);

    priority_queue<PIL,vector<PIL>,greater<PIL>> p;

    vector<int> ans(n+1);
    int cur=0;

    for(int i=1;i<=n;i++)
    {
        if(p.empty()||p.top().first>=A[i].a)
        {
            cur++;
            ans[A[i].id]=cur;
            p.push(make_pair(A[i].b,cur));

        }
        else
        {
            auto u=p.top();
            p.pop();
            ans[A[i].id]=u.second;
            p.push(make_pair(A[i].b,u.second));
        }
    }
    cout<<cur<<endl;

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;



    return 0;
}