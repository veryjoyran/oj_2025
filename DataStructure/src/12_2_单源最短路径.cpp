#include<bits/stdc++.h>
using namespace std;

#define N 100001

struct edge{
    int v,w;
};

struct Node{
    int u;
    int d;
    Node(int U=0,int D=0){u=U;d=D;}
    bool operator<(const Node& q)const{
        return d > q.d;
    }
};

void dijkstra(int n, vector<vector<edge>>& mp, vector<int>& dist) {
    priority_queue<Node> pq;
    vector<bool> vis(n, false);

    dist[0] = 0;
    pq.emplace(0, 0);

    while(!pq.empty()) {
        int now = pq.top().u;
        pq.pop();

        if(vis[now]) continue;
        vis[now] = true;

        for(int i = 0; i < mp[now].size(); i++) {
            int v = mp[now][i].v;
            int w = mp[now][i].w;

            if(dist[v] > dist[now] + w) {
                dist[v] = dist[now] + w;
                pq.emplace(v, dist[v]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<edge>> mp(n);
    vector<int> dist(n, INT_MAX);

    for(int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;

        for(int j = 0; j < k; j++) {
            int v, c;
            cin >> v >> c;
            mp[u].push_back({v, c});
        }
    }

    dijkstra(n, mp, dist);

    for(int i = 0; i < n; i++) {
        cout << i << " " << dist[i] << endl;
    }

    return 0;
}
