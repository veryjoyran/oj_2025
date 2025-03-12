#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool BubbleSort(vector<string> &arr){
    bool flag=true;
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i+1;j--){
            if(int(arr[j][1])<int(arr[j-1][1]))
            {
                if(int(arr[j][1])==int(arr[j-1][1]))
                    flag=false;
                string temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    return flag;
}

int SelectionSort(vector<string>& arr){
    bool flag=true;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {

        int mini=i;
        for(int j=i;j<n;j++){
            if(int(arr[j][1])<int(arr[mini][1]))
                mini=j;
        }
        if(mini!=i)
        {
            for(int j=i+1;j<mini;j++)
            {
                if(int(arr[j][1])==int(arr[i][1]))
                    flag=false;
            }
            string temp=arr[mini];
            arr[mini]=arr[i];
            arr[i]=temp;
        }

    }
    return flag;
}

string ifstable(bool flag)
{
    if(!flag)
        return "Not stable";
    else
        return "Stable";
}


int main() {
    int n;
    cin>>n;
    vector<string> arr_bubble(n);
    vector<string> arr_select(n);
    vector<string> arr_bubble_finished(n);
    vector<string> arr_select_finished(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr_bubble[i];
        arr_select[i]=arr_bubble[i];
        arr_bubble_finished[i]=arr_bubble[i];
        arr_select_finished[i]=arr_bubble[i];
    }
    bool flag_bubble=BubbleSort(arr_bubble_finished);
    bool flag_select=SelectionSort(arr_select_finished);
    for(auto i:arr_bubble_finished)
        cout<<i<<" ";
    cout<<endl;

    cout<<ifstable(flag_bubble)<<endl;

    for(auto i:arr_select_finished)
        cout<<i<<" ";
    cout<<endl;

    cout<<ifstable(flag_select)<<endl;


    return 0;
}

