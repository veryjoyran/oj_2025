#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include<string>
#include<stack>

using namespace std;

typedef pair<int,int> p;

void CountingSore(vector<int> &A,vector<int> &B,int k)
{
    vector<int> C(k+1,0);


    int A_size=A.size();
    for(int j=0;j<A_size;j++)
    {
        C[A[j]]+=1;
    }

    for(int i=1;i<=k;i++)
    {
        C[i]+=C[i-1];
    }
    for(int j=A_size-1;j>=0;j--)
    {
        B[C[A[j]]-1]=A[j];
        C[A[j]]-=1;
    }

}


int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    int mmax=-1;
    while(n--)
    {
        cin>>A[n];
        if(A[n]>mmax)
            mmax=A[n];
    }

    CountingSore(A,B,mmax);


    for(auto i:B)
        cout<<i<<" ";
    cout<<endl;







    return 0;
}
