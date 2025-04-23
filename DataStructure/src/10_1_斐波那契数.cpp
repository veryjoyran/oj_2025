#include <bits/stdc++.h>

using namespace std;


int fib(int n)
{
    if(n==0||n==1)
        return 1;
    vector<int> res(n+1);
    res[0]=1;
    res[1]=1;
    for(int i=2;i<=n;i++)
        res[i]=res[i-1]+res[i-2];


    return res[n];

}



int main()
{

    int n;
    cin>>n;

    cout<<fib(n)<<endl;

}