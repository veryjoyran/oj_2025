#include<bits/stdc++.h>
using namespace std;

const string target = "123456780";

string matrixToString(vector<vector<int>>& matrix) {
    string result = "";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result += to_string(matrix[i][j]);
        }
    }
    return result;
}

vector<vector<int>> stringToMatrix(const string& s) {
    vector<vector<int>> matrix(3, vector<int>(3));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matrix[i][j] = s[i * 3 + j] - '0';
        }
    }
    return matrix;
}

pair<int, int> findZero(const string& s) {
    for(int i = 0; i < 9; i++) {
        if(s[i] == '0') {
            return {i / 3, i % 3};
        }
    }
    return {-1, -1};
}

vector<string> getNextStates(const string& current) {
    vector<string> nextStates;
    pair<int, int> zeroPos = findZero(current);
    int row = zeroPos.first;
    int col = zeroPos.second;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if(newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
            string nextState = current;
            swap(nextState[row * 3 + col], nextState[newRow * 3 + newCol]);
            nextStates.push_back(nextState);
        }
    }

    return nextStates;
}

int bfs(const string& start) {
    if(start == target) {
        return 0;
    }

    queue<pair<string, int>> q;
    unordered_set<string> visited;

    q.push({start, 0});
    visited.insert(start);

    while(!q.empty()) {
        auto current = q.front();
        q.pop();

        string state = current.first;
        int steps = current.second;

        vector<string> nextStates = getNextStates(state);

        for(const string& nextState : nextStates) {
            if(nextState == target) {
                return steps + 1;
            }

            if(visited.find(nextState) == visited.end()) {
                visited.insert(nextState);
                q.push({nextState, steps + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> matrix(3, vector<int>(3));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    string start = matrixToString(matrix);

    int result = bfs(start);

    cout << result << endl;

    return 0;
}