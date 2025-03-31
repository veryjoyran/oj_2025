#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cmath>
#include <iomanip>

const double PI=3.1415926;

using namespace std;



vector<pair<double,double>> koch(pair<double,double>& p1,pair<double,double>& p2,int depth)
{
    if (depth == 0) {
        return {p1,p2};
    }

    double dx = (p2.first - p1.first) / 3;
    double dy = (p2.second - p1.second) / 3;
    auto s = make_pair(p1.first + dx, p1.second + dy);
    auto t = make_pair(p1.first + 2*dx, p1.second + 2*dy);
    auto u=make_pair(s.first+dx*cos(PI/3)-dy*sin(PI/3),s.second+dx*sin(PI/3)+dy*cos(PI/3));

    vector<pair<double,double>> part1=koch(p1,s,depth-1);
    vector<pair<double,double>> part2=koch(s,u,depth-1);
    vector<pair<double,double>> part3=koch(u,t,depth-1);
    vector<pair<double,double>> part4=koch(t,p2,depth-1);

    vector<pair<double,double>> result;
    result.insert(result.end(),part1.begin(),part1.end());
    result.insert(result.end(),part2.begin()+1,part2.end());
    result.insert(result.end(),part3.begin()+1,part3.end());
    result.insert(result.end(),part4.begin()+1,part4.end());

    return result;


}



int main()
{
    int n;
    cin>>n;


    //    auto p1=make_pair(3.2,1.6);
    //    auto p2=make_pair(2.1,4.8);
    //    auto s=make_pair((p1.first+p1.second)/2,2.2);
    //    cout<<s.first<<" "<<s.second;

    auto start_=make_pair(0.0,0.0);
    auto end_=make_pair(100.0,0.0);

    vector<pair<double,double>> arr;
    arr.push_back(start_);
    arr.push_back(end_);

    vector<pair<double,double>> result=koch(start_,end_,n);


    for (const auto& p : result) {
        cout << fixed << setprecision(8)<< p.first << " " << p.second << endl;
    }

    return 0;
}
