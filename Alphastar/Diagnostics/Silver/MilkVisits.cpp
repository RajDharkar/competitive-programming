#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
int N;
int litRooms = 1;
const int MN = 100;
bool visited[MN][MN];
bool lit[MN][MN];
vector<pair<int, int>> switches[MN][MN];

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};
bool checkConnected(int x, int y) {
	// Iterate through neighbors
	for (int i = 0; i < 4; i++) {
		int newX = x + dirX[i];
		int newY = y + dirY[i];

		// Ignore neighbor if out of bounds
		if (newX < 0 || newY < 0 || newX > N - 1 || newY > N - 1) { continue; }

		// If a neighbor is visited, return true
		if (visited[newX][newY]) { return true; }
	}

	// If no neighbors have been visited, return false
	return false;
}

void floodfill(int r, int c) {
	if ((r < 0 || r >= N || c < 0 || c >= N || visited[r][c] || !lit[r][c])){
        return;
    } // if out of bounds       

    if(!checkConnected(r, c) && !(r == 0 && c == 0)){
        return;
    }

	visited[r][c] = true;  // mark current square as visited

	// recursively call flood fill for neighboring squares
	for (int i = 0; i < 4; i++) { floodfill(r + dirX[i], c + dirY[i]); }
    
	// litRooms++;           // increment the size for each square we visit
    for (int i = 0; i < switches[r][c].size(); i++) {
		int roomX = switches[r][c][i].first;
		int roomY = switches[r][c][i].second;

		/*
		 * If room hasn't been lit yet, add it to our count of rooms that have
		 * been lit
		 */
		if (!lit[roomX][roomY]) { litRooms++; }

		// Set room led to by switch to lit
		lit[roomX][roomY] = true;

		// Floodfill from new room that is lit
		floodfill(roomX, roomY);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int M; 
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        switches[a][b].push_back({c, d});
    }

    lit[0][0] = true;
    floodfill(0, 0);
    cout << litRooms << '\n';
    return 0;
}
