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
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>=i+1;j--){
            if(arr[j]<arr[j-1])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                swap_num++;
            }
        }
    }
    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;
    cout<<swap_num<<endl;
    return 0;
}
