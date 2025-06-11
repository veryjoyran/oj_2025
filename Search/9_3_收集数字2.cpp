#include<bits/stdc++.h>
using namespace std;

int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

    int n, m;
      cin >> n >> m;

      vector<int> a(n + 1);
      vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
          cin >> a[i];
        pos[a[i]] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) {
            ans++;
        }
    }

    for (int op_count = 0; op_count < m; op_count++) {
        int p1, p2;
          cin >> p1 >> p2;

        if (p1 == p2) {
              cout << ans << "\n";
            continue;
        }

        int val1 = a[p1];
        int val2 = a[p2];

          set<int> critical_k_values;

        if (val1 >= 2) critical_k_values.insert(val1);
        if (val1 + 1 <= n) critical_k_values.insert(val1 + 1);

        if (val2 >= 2) critical_k_values.insert(val2);
        if (val2 + 1 <= n) critical_k_values.insert(val2 + 1);

        for (int k : critical_k_values) {
            if (pos[k] < pos[k - 1]) {
                ans--;
            }
        }

          swap(a[p1], a[p2]);
        pos[val1] = p2;
        pos[val2] = p1;

        for (int k : critical_k_values) {
            if (pos[k] < pos[k - 1]) {
                ans++;
            }
        }
          cout << ans << "\n";
    }

    return 0;
}
