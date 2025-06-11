#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n = 0) { init(n); }

    void init(int n) {
        this->n = n;
        a.assign(n + 1, T());
    }

    void add(int x, T v) {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    }

    T sum(int x) {
        T ans = T();
        for(int i = x; i; i -= i & -i)
            ans += a[i];
        return ans;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    int geq(int k) {
        int pos = 0;
        for(int i = 1 << __lg(n); i; i /= 2) {
            if(pos + i <= n && sum(pos + i) < k) {
                pos += i;
            }
        }
        return pos + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, k;
    cin >> n >> k;
    k++;

    Fenwick<int> f(n);

    for(int i = 1; i <= n; i++) {
        f.add(i, 1);
    }

    int cur = 1;
    for(int i = 1; i <= n; i++) {
        int curk = k % (n - i + 1);
        if(curk == 0) curk = n - i + 1;

        if(f.sum(cur, n) >= curk) {
            cur = f.geq(f.sum(cur - 1) + curk);
        } else {
            cur = f.geq(curk - f.sum(cur, n));
        }

        f.add(cur, -1);
        cout << cur;
        if(i != n) cout << " ";
    }
    cout << endl;

    return 0;
}
