#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

void update(vector<int>& tree, int idx, int delta) {
    while (idx < tree.size()) {
        tree[idx] += delta;
        idx += lowbit(idx);
    }
}

int query(const vector<int>& tree, int idx) {
    int res = 0;
    while (idx > 0) {
        res += tree[idx];
        idx -= lowbit(idx);
    }
    return res;
}

int main() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    auto last = unique(sorted_A.begin(), sorted_A.end());
    sorted_A.erase(last, sorted_A.end());
    int max_rank = sorted_A.size();

    vector<int> tree(max_rank + 1, 0);

    long long ans = 0;

    for (int i = n - 1; i >= 0;i--) {
        int val = A[i];
        auto it = lower_bound(sorted_A.begin(), sorted_A.end(), val);
        int rank = (it - sorted_A.begin()) + 1;

        ans += query(tree, rank - 1);

        update(tree, rank, 1);
    }

    cout << ans << endl;
    return 0;
}
