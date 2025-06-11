#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string Template;
    string target;
    cin>>Template;
    cin>>target;
    int len=Template.size();
    int l=target.size();

    bool flag=true;
    for(int i=0;i<len-l+1;i++)
    {
        flag=true;

        for(int j=0;j<l;j++)
        {
            if(target[j]!=Template[i+j])
            {
                flag=false;
                break;
            }
        }

        if(flag)
            cout<<i<<endl;
    }

    return 0;
}
