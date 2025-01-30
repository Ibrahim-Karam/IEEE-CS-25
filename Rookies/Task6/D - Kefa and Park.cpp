#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> cats(100005);
int n, m, validRestaurants = 0;

void dfs(int node, int parent, int consecutiveCats) {
    if (cats[node - 1] == 1) {
        consecutiveCats++;
    }
    else {
        consecutiveCats = 0;
    }

    if (consecutiveCats > m) {
        return;
    }

    bool isLeaf = true;

    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            isLeaf = false;
            dfs(neighbor,node,consecutiveCats);
        }
    }

    if (isLeaf) {
        validRestaurants++;
    }
}

int main() {
    cin>>n>>m;

    for (int i = 0; i < n; i++) {
        cin>>cats[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    cout<<validRestaurants << endl;

    return 0;
}
