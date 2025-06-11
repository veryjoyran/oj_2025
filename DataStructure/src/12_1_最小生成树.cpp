#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int U,int V,int Weight){u=U;v=V;weight=Weight;}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

vector<int> parent, rank_arr;

void init(int n) {
    parent.resize(n);
    rank_arr.resize(n, 0);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX == rootY) {
        return false;
    }

    if(rank_arr[rootX] < rank_arr[rootY]) {
        parent[rootX] = rootY;
    } else if(rank_arr[rootX] > rank_arr[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank_arr[rootX]++;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    vector<Edge> edges;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if(i < j && adj[i][j] != -1) {
                edges.push_back(Edge(i, j, adj[i][j]));
            }
        }
    }

    sort(edges.begin(), edges.end());

    init(n);

    int mstWeight = 0;
    int edgesUsed = 0;

    for(const Edge& edge : edges) {
        if(unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            edgesUsed++;

            if(edgesUsed == n - 1) {
                break;
            }
        }
    }

    cout << mstWeight << endl;

    return 0;
}
