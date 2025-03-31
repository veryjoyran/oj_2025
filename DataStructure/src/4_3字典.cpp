#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;



int main()
{
    int n;
    map<string,int> myMap;
    cin>>n;
    while(n--)
    {
        string opt,s;
        cin>>opt>>s;
        if(opt=="insert")
        {
            myMap[s]=1;
        }
        else
            cout<<(myMap[s]?"yes":"no")<<endl;
    }






    return 0;
}
