#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> monster_time, player_time;
vector<vector<char>> path;
pair<int, int> start;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
char dir[] = { 'U', 'D', 'L', 'R' };

void bfs_monsters(queue<pair<int, int>>& q) {
    while (!q.empty()) {
        pair<int, int> p = q.front();
        int x = p.first, y = p.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && monster_time[nx][ny] == -1) {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

bool bfs_player() {
    queue<pair<int, int>> q;
    q.push(start);
    player_time[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        int x = p.first, y = p.second;
        q.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            cout << "YES\n";
            string result;

            while (grid[x][y] != 'A') {
                result += path[x][y];
                int d = string("UDLR").find(path[x][y]);
                x -= dx[d];
                y -= dy[d];
            }
            reverse(result.begin(), result.end());
            cout << result.length() << "\n" << result << endl;
            return true;
        }


        for (int i=0;i<4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                if (player_time[nx][ny] == -1 && (monster_time[nx][ny] == -1 || player_time[x][y] + 1 < monster_time[nx][ny])) {
                    player_time[nx][ny] = player_time[x][y] + 1;
                    path[nx][ny] = dir[i];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    monster_time.assign(n, vector<int>(m, -1));
    player_time.assign(n, vector<int>(m, -1));
    path.assign(n, vector<char>(m, ' '));
    queue<pair<int, int>> monster_queue;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j]=='A') start = make_pair(i, j);
            if (grid[i][j]=='M'){
                monster_queue.push(make_pair(i, j));
                monster_time[i][j] = 0;
            }
        }
    }

    bfs_monsters(monster_queue);
    if (!bfs_player()) {
        cout << "NO\n";
    }

    return 0;
}
