#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime_number(int num)
{
    if(num==2||num==3||num==5||num==7)
        return true;
    else{

        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }

}

int main() {

    int n;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(is_prime_number(num))
            sum++;
    }
    cout<<sum;



    return 0;
}
