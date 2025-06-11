#include<bits/stdc++.h>
using namespace std;

string text;
vector<int> SA;

void buildSA() {
    int n = text.length();
    vector<int> rank(n), tmp(n);

    SA.clear();
    for(int i = 0; i < n; i++) {
        SA.push_back(i);
        rank[i] = text[i];
    }

    for(int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if(rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };

        sort(SA.begin(), SA.end(), cmp);

        tmp[SA[0]] = 0;
        for(int i = 1; i < n; i++) {
            tmp[SA[i]] = tmp[SA[i-1]] + (cmp(SA[i-1], SA[i]) ? 1 : 0);
        }
        rank = tmp;
    }
}

bool search(const string& pattern) {
    int n = SA.size();
    int left = 0, right = n;

    while(left < right) {
        int mid = (left + right) / 2;
        string suffix = text.substr(SA[mid], min((int)pattern.length(), (int)text.length() - SA[mid]));

        if(suffix >= pattern) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if(left < n) {
        string suffix = text.substr(SA[left], min((int)pattern.length(), (int)text.length() - SA[left]));
        return suffix == pattern;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> text;

    buildSA();

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        string pattern;
        cin >> pattern;

        if(search(pattern)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
