#include<bits/stdc++.h>

using namespace std;






int main()
{


    priority_queue<int> pq;
    string op;
    while(true)
    {
        cin>>op;
        if (op=="end") break;
        else if(op=="insert")
        {
            int key;
            cin>>key;
            pq.push(key);
        }
        else
        {
            cout<<pq.top()<<endl;
            pq.pop();
        }
    }





    return 0;
}