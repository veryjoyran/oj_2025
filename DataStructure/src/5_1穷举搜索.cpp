#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<int> GetSet(const vector<int>& A,int n){
    set<int> mySet;
    for(int i=0;i<(1<<n);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                sum+=A[j];
            }
            mySet.insert(sum);
        }
    }
    return mySet;
}

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    set<int> mySet=GetSet(A,n);
    //    for(auto &i:mySet)
    //        cout<<i<<" "<<endl;
    //    cout<<"start"<<endl;

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int temp;
        cin>>temp;
        if(find(mySet.begin(),mySet.end(),temp)!=mySet.end())
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;


    }


    return 0;
}
