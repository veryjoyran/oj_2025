#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> p(n + 1);
    vector<double> q(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for(int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0));
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0));

    for(int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for(int len = 1; len <= n; len++) {
        for(int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;

            w[i][j] = w[i][j - 1] + p[j] + q[j];

            e[i][j] = 1e9;

            for(int k = i; k <= j; k++) {
                double cost = e[i][k - 1] + e[k + 1][j] + w[i][j];
                e[i][j] = min(e[i][j], cost);
            }
        }
    }

    cout << fixed << setprecision(8) << e[1][n] << endl;

    return 0;
}
