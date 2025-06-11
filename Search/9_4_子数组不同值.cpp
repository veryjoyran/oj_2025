#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    int cur = 0;
    map<int, int> cnt;

    for(int l = 1, r = 0; l <= n; l++) {
        while(r + 1 <= n && cur + !cnt.count(a[r + 1]) <= k) {
            r++;
            cur += !cnt[a[r]]++;
        }

        ans += r - l + 1;

        if(--cnt[a[l]] == 0) {
            cur--;
            cnt.erase(a[l]);
        }
    }

    cout << ans << endl;

    return 0;
}
