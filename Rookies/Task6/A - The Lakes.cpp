#include <bits/stdc++.h>
using namespace std;

int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>& visited) {
    int n=grid.size();
    int m=grid[0].size();
    if (i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || visited[i][j]){
        return 0;
    }
    visited[i][j]=true;
    int volume=grid[i][j];
    for (int k=0;k<4;k++){
        volume+=dfs(i+dx[k],j+dy[k],grid,visited);
    }
    return volume;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxVolume = 0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]>0 && !visited[i][j]) {
                    int currentVolume = dfs(i, j, grid, visited);
                    maxVolume = max(maxVolume, currentVolume);
                }
            }
        }
        cout << maxVolume << endl;
    }
    return 0;
}
