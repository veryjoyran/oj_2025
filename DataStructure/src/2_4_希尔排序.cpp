#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int insertionSort(vector<int> &arr,int n,int g)
{
    int cnt=0;
    for(int i=g;i<n;i++)
    {
        int v=arr[i];
        int j=i-g;
        while(j>=0&&arr[j]>v){
            arr[j+g]=arr[j];
            j=j-g;
            cnt++;
        }
        arr[j+g]=v;
    }
    return cnt;
}


void shellSort(vector<int> &arr,int n)
{
    int cnt=0;
    int m=0;
    int k=1;
    int G_num=0;
    vector<int> G(100);
    while(k<=n){
        G[G_num]=k;
        k=k*3+1;
        G_num++;
    }
    G.resize(G_num);
    sort(G.begin(),G.end(),greater<int>());
    cout<<G_num<<endl;
    for(auto i:G)
        cout<<i<<" ";
    cout<<endl;

    int sum_cnt=0;
    for(auto i:G)
    {
        sum_cnt+=insertionSort(arr,n,i);
    }
    cout<<sum_cnt<<endl;

    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;


}


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    shellSort(arr,n);






    return 0;
}
