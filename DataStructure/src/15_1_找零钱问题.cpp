#include<bits/stdc++.h>
using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> coins({25,10,5,1});

    int n;
    cin>>n;

    int sum=0;
    for(int i=0;i<coins.size();i++)
    {
        sum+=n/coins[i];
        n%=coins[i];
        if(coins[i]==0) break;
    }
    cout<<sum;


    return 0;
}
