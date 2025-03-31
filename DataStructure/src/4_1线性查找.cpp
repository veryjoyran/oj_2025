#include <iostream>
#include <list>
#include <algorithm>
#include <vector>


using namespace std;



int main()
{
    int n;
    int sum=0;
    cin>>n;
    vector<int> S(n);
    for(int i=0;i<n;i++){
        cin>>S[i];
    }
    int q;
    cin>>q;
    vector<int> T(q);
    for(int i=0;i<q;i++){
        cin>>T[i];
        if(find(S.begin(),S.end(),T[i])!=S.end())
            sum++;
    }
    cout<<sum<<endl;






    return 0;
}
