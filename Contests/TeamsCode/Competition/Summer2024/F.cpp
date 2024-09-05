#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<string> matrix;

// Directions for moving right and down
vector<pair<int, int>> directions = {{1, 0}, {0, 1}};

// Function to check if a move is valid
bool isValid(int x, int y, const vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == '1' && !visited[x][y];
}

// Function to perform BFS and find the minimum XORgun uses
int minXORgunUsage() {
    // Queue for BFS: stores (x, y, toggles used)
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});

    // Visited array to track visited cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y, toggles] = q.front(); q.pop();

        // Check if we reached the bottom-right corner
        if (x == n - 1 && y == m - 1) {
            return toggles;
        }

        // Try moving to adjacent cells (right and down)
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny, visited)) {
                visited[nx][ny] = true;
                q.push({nx, ny, toggles});
            }
        }

        // Try toggling each row and see if it helps in reaching new valid cells
        for (int i = 0; i < n; ++i) {
            if (i != x) {  // Do not toggle the current row
                vector<string> toggledMatrix = matrix;
                for (int j = 0; j < m; ++j) {
                    toggledMatrix[i][j] = (toggledMatrix[i][j] == '0') ? '1' : '0';
                }

                // Check cells in the matrix after toggling the row
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && toggledMatrix[nx][ny] == '1' && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny, toggles + 1});
                    }
                }
            }
        }
    }

    return -1;  // No path found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        matrix.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> matrix[i];
        }

        if (matrix[0][0] != '1') {
            cout << -1 << '\n';
            continue;
        }

        cout << minXORgunUsage() << '\n';
    }

    return 0;
}
