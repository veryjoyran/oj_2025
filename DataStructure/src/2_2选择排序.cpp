#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int swap_num=0;

    for(int i=0;i<n;i++)
    {

        int mini=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini])
                mini=j;
        }
        if(mini!=i)
        {
            int temp=arr[mini];
            arr[mini]=arr[i];
            arr[i]=temp;
            swap_num++;
        }

    }

    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;
    cout<<swap_num<<endl;
    return 0;
}
