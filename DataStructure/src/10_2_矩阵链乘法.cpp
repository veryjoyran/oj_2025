#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);

    cin >> a[0] >> a[1];
    for (int i = 2; i <= n; ++i)
    {
        int r, c;
        cin >> r >> c;
        a[i] = c;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int cost = dp[i][k] + dp[k+1][j] + a[i] * a[k+1] * a[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][n-1] << endl;
    return 0;
}