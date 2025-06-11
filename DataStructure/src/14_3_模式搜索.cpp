#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> text(H);
    for(int i = 0; i < H; i++) {
        cin >> text[i];
    }

    int R, C;
    cin >> R >> C;

    vector<string> pattern(R);
    for(int i = 0; i < R; i++) {
        cin >> pattern[i];
    }

    vector<pair<int, int>> result;

    for(int i = 0; i <= H - R; i++) {
        for(int j = 0; j <= W - C; j++) {
            bool match = true;

            for(int r = 0; r < R && match; r++) {
                for(int c = 0; c < C && match; c++) {
                    if(text[i + r][j + c] != pattern[r][c]) {
                        match = false;
                    }
                }
            }

            if(match) {
                result.push_back({i, j});
            }
        }
    }

    for(auto& pos : result) {
        cout << pos.first << " " << pos.second << endl;
    }

    return 0;
}
