#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

const int DX[4] = {0, 0, -1, 1};
const int DY[4] = {1, -1, 0, 0};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<char>> grid(n, vector<char>(n, '?'));
    vector<tuple<int, int, char>> fx;
    vector<vector<bool>> esc(n, vector<bool>(n, false));
    int ec = 0;
    deque<pair<int, int>> qx;

    for (int i = 0; i < q; i++) {
        int x, y;
        char d;
        cin >> x >> y >> d;
        fx.emplace_back(x - 1, y - 1, d);
        grid[x - 1][y - 1] = d;
    }

    auto mark = [&](int r, int c) {
        if (!esc[r][c]) {
            esc[r][c] = true;
            ec++;
            qx.emplace_back(r, c);
        }
    };

    auto rebuild = [&]() {
        vector<vector<vector<pair<int, int>>>> adj(n, vector<vector<pair<int, int>>>(n));
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                char d = grid[x][y];
                if (d == '?') {
                    for (int k = 0; k < 4; k++) {
                        int nx = x + DX[k], ny = y + DY[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            adj[nx][ny].emplace_back(x, y);
                        }
                    }
                } else {
                    int nx = x, ny = y;
                    if (d == 'R') ny++;
                    else if (d == 'L') ny--;
                    else if (d == 'U') nx--;
                    else if (d == 'D') nx++;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        adj[nx][ny].emplace_back(x, y);
                    }
                }
            }
        }
        return adj; //remember to rebuild
    };

    auto adj = rebuild(); //wait idk why this is working lol edit. oh wait nvm

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            char d = grid[x][y];
            if (d == '?') {
                if (x == 0 || x == n - 1 || y == 0 || y == n - 1) {
                    mark(x, y);
                }
            } else if ((d == 'R' && y == n - 1) || (d == 'L' && y == 0) ||
                       (d == 'U' && x == 0) || (d == 'D' && x == n - 1)) {
                mark(x, y); //so sigma(had to edit this function like four times)
            }
        }
    }

    while (!qx.empty()) {
        auto [cr, cc] = qx.front();
        qx.pop_front();
        for (auto [nx, ny] : adj[cr][cc]) {
            if (!esc[nx][ny]) {
                mark(nx, ny);
            }
        }
    }

    vector<int> res(q);
    res[q - 1] = n * n - ec;

    for (int d = q - 1; d > 0; d--) {
        auto [x, y, _] = fx[d];
        grid[x][y] = '?';
        adj = rebuild();
        if (!esc[x][y]) {
            if (x == 0 || x == n - 1 || y == 0 || y == n - 1) {
                mark(x, y);
            } else {
                for (int k = 0; k < 4; k++) {
                    int nx = x + DX[k], ny = y + DY[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && esc[nx][ny]) {
                        mark(x, y);
                    }
                }
            }
            while (!qx.empty()) {
                auto [cr, cc] = qx.front();
                qx.pop_front();
                for (auto [nx, ny] : adj[cr][cc]) {
                    if (!esc[nx][ny]) {
                        mark(nx, ny);
                    }
                }
            }
        }
        res[d - 1] = n * n - ec;
    }

    for (int ans : res) {
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
