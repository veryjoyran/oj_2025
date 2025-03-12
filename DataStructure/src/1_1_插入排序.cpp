#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertSort(vector<int> &arr)
{
  int n=arr.size();
  for(int i=1;i<n;i++)
  {
    int key=arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>key)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
    for(auto i:arr)
      cout<<i<<" ";
    cout<<endl;

  }

}

int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  insertSort(arr);



  return 0;
}