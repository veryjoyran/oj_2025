#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    long long sum = 0, ans = 0, a;
    map<long long, long long> mp;
    mp[0] = 1;

    for(int i = 1; i <= n; i++) {
        cin >> a;
        sum += a;
        ans += mp[sum - target];
        mp[sum]++;
    }
    
    cout << ans;
    return 0;
}