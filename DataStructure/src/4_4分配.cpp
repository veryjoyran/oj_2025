#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool check(const vector<int> &arr,int n,int P,int k)
{
    int sum=0;
    int current_k=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>P) return false;

        if(sum+arr[i]>P)
        {
            current_k++;
            if(current_k>k) return false;
            else{
                sum=arr[i];
            }
        }
        else
            sum+=arr[i];

    }
    return true;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> package(n);
    for(int i=0;i<n;i++)
        cin>>package[i];

    int l=0;
    int r=n*10000;

    while(l<r)
    {
        int P=(l+r)/2;
        if(check(package,n,P,k))
            r=P;
        else l=P+1;
    }
    cout<<l<<endl;


    return 0;
}
