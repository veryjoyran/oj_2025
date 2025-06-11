#include<bits/stdc++.h>
using namespace std;

vector<int> buildNext(const string& pattern) {
    int m = pattern.length();
    vector<int> next(m, 0);

    for(int i = 1, j = 0; i < m; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if(pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }

    return next;
}

vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.length();
    int m = pattern.length();

    if(m == 0) return result;

    vector<int> next = buildNext(pattern);

    for(int i = 0, j = 0; i < n; i++) {
        while(j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if(text[i] == pattern[j]) {
            j++;
        }
        if(j == m) {
            result.push_back(i - m + 1);
            j = next[j - 1];
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;

    vector<int> matches = kmpSearch(text, pattern);

    for(int pos : matches) {
        cout << pos << endl;
    }

    return 0;
}