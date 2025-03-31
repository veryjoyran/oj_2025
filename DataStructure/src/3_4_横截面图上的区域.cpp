#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include<string>
#include<stack>

using namespace std;

typedef pair<int,int> p;

stack<p> getPair(const string &s)
{
    stack<p> pairStack;
    stack<int> numStack;
    int sum_area=0;
    int s_size=s.size();
    for(int i=0; i<s_size; i++)
    {
        if(s[i]=='_')
            continue;
        else if(s[i]=='\\')
            numStack.push(i);
        else
        {
            if(!numStack.empty())
            {
                int first=numStack.top();
                sum_area+=i-first;
                pairStack.push(p(first,i));
                numStack.pop();
            }

        }
    }
    cout<<sum_area<<endl;

    return pairStack;
}


int main()
{
    string str;
    cin>>str;
    stack<p> pairStack=getPair(str);

    vector<int> area;

    if(pairStack.empty())
        cout<<"0"<<endl;
    else
    {
        int current_area=0;
        int current_l=pairStack.top().first;


        while(!pairStack.empty())
        {
            if(pairStack.top().first<current_l)
            {
                current_l=pairStack.top().first;
                area.push_back(current_area);
                current_area=0;
            }

            current_area+=pairStack.top().second-pairStack.top().first;
            pairStack.pop();
        }

        if(current_area!=0)
            area.push_back(current_area);

        int area_size=area.size();
        cout<<area_size<<" ";

        reverse(area.begin(),area.end());
        for(auto i:area)
            cout<<i<<" ";
        cout<<endl;

    }




    return 0;
}
