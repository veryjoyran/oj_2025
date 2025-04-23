#include<bits/stdc++.h>

using namespace std;


typedef pair<int,int> PIL;

struct PILCompare{
    bool operator ()(const PIL& p1,const PIL& p2) const
    {
        return p1.first<p2.first;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<PIL> A(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>A[i].first;
        A[i].second=i;
    }


    sort(A.begin()+1,A.end(),PILCompare());


    bool g_flag=false;
    bool flag=false;

    //    if ((A[1].first + A[2].first + A[3].first + A[4].first > k)||((A[n].first+A[n-1].first+A[n-2].first+A[n-3].first)<k)) {
    //    cout << "IMPOSSIBLE";
    //    return 0;
    //}

    for(int j=1;j<=n;j++)
    {
        if (j > 1 && A[j].first == A[j-1].first) continue;
        //        int new_new_k=k-A[j].first;


        for(int i=1;i<=n;i++)
        {


            if(i==j) continue;

            int res=k-A[i].first-A[j].first;

            int l=1,r=n;
            while(l<r)
            {



                int ans=A[l].first+A[r].first;

                if(ans<res) l++;
                else if(ans>res) r--;
                else
                {
                    if(i==l || j==l) l++;
                    else if(i==r||j==r) r--;
                    else
                    {
                        cout<<A[l].second<<" "<<A[r].second<<" "<<A[i].second<<" "<<A[j].second<<endl;
                        g_flag=true;
                        flag=true;
                        break;
                    }

                }
            }
            if(flag)
                break;

        }
        if(flag)
            break;

    }

    if(!g_flag)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }







    return 0;
}