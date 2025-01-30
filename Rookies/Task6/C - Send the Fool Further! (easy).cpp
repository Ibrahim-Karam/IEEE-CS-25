#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int current_cost, int& max_cost) {
    visited[node] = true;
    bool is_leaf = true;

    for (const auto& neighbor : adj[node]) {
        int next_node = neighbor.first;
        int cost = neighbor.second;

        if (!visited[next_node]) {
            is_leaf = false;
            dfs(next_node, adj, visited, current_cost + cost, max_cost);
        }
    }

    if (is_leaf) {
        max_cost = max(max_cost, current_cost);
    }

    visited[node] = false;
}

int main() {
    int n;
    cin>>n;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin>>u>>v>>c;

        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }


    vector<bool> visited(n, false);
    int max_cost = 0;

    dfs(0,adj,visited,0,max_cost);

    cout<<max_cost<<endl;

    return 0;
}
