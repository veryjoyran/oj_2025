#include<bits/stdc++.h>
using namespace std;

int h[4][4];
int ans = 50;

int dist() {
    int res = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int v = h[i][j];
            if(v == 0) continue;
            int ni = (v - 1) / 4;
            int nj = (v - 1) % 4;
            res += abs(i - ni) + abs(j - nj);
        }
    }
    return res;
}

bool dfs(int step, int lastDir, int zi, int zj) {
    int cd = dist();

    if(cd == 0) {
        ans = min(ans, step);
        return true;
    }

    if(step + cd >= ans) return false;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int k = 0; k < 4; k++) {
        if((k ^ 1) == lastDir) continue;

        int ni = zi + dx[k];
        int nj = zj + dy[k];

        if(ni < 0 || ni >= 4 || nj < 0 || nj >= 4) continue;

        swap(h[zi][zj], h[ni][nj]);

        if(dfs(step + 1, k, ni, nj)) return true;

        swap(h[zi][zj], h[ni][nj]);
    }

    return false;
}

void solve() {
    int zi = -1, zj = -1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(h[i][j] == 0) {
                zi = i;
                zj = j;
                break;
            }
        }
        if(zi != -1) break;
    }

    for(int depth = 0; depth <= 45; depth++) {
        ans = depth + 1;
        if(dfs(0, -1, zi, zj)) {
            cout << depth << endl;
            return;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> h[i][j];
        }
    }

    solve();

    return 0;
}
