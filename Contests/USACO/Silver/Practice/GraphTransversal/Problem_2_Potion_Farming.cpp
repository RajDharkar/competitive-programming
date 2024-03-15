#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()




void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
vector<int> readVector(int size){
    vector<int> t_vector(size);
    for(int i = 0; i < size; i++){
        cin >> t_vector[i];
    }
    return t_vector;
}


void floodfill(int r, int c, int color) {
    //change when utilizing method
    const int MAX_N = 1000;

    int grid[MAX_N][MAX_N];  // the grid itself
    int row_num;
    int col_num;
    bool visited[MAX_N][MAX_N];  // keeps track of which nodes have been visited
    int curr_size = 0;           // reset to 0 each time we start a new component
	if ((r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
	    || grid[r][c] != color                            // wrong color
	    || visited[r][c]  // already visited this square
	)
		return;

	visited[r][c] = true;  // mark current square as visited
	curr_size++;           // increment the size for each square we visit

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}


int n; //change when utilizing method
vector<vector<int>> adj(n); //change when utilizing method
vector<bool> visited(n); //change when utilizing method
vector<int> potions(n);
int leafNodes = 0;
void dfs(int current_node) {
	if (visited[current_node]) { return; }
	    visited[current_node] = true;
    bool leafNode = true;
	for (int neighbor : adj[current_node]) { 
        if(!visited[neighbor]){
            leafNode = false;
            dfs(neighbor);
        }
    }
    if(leafNode){
        leafNodes++;
    }

}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int hold;
        cin >> hold;
        potions.push_back(--hold); 
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        cout << a << " " << b << '\n';
        a-=1;
        b-=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    //dfs(0);
    cout << leafNodes << '\n';
}
