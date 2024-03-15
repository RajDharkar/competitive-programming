#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
int n;
//int size = n; //change when utilizing method
vector<vector<int>> adj(n); //change when utilizing method
vector<bool> visited(n, false); //change when utilizing method
vector<pii> cows(n, {0, 0});
int maxX = 0;
int maxY = 0;
int minX = 0;
int minY = 0;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int last_true(int lo, int hi, function<bool(int)> f) {
	// if none of the values in the range work, return lo - 1
	lo--;
	while (lo < hi) {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) {
			// if mid works, then all numbers smaller than mid also work
			lo = mid;
		} else {
			// if mid does not work, greater values would not work either
			hi = mid - 1;
		}
	}
	return lo;
}
int first_true(int lo, int hi, function<bool(int)> f) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}
int readInt(){
    int integer;
    cin >> integer;
    return integer;
}
int* readArray(int size){
    int* t_array = new int[size];
    for(int i = 0; i < size; i++){
        cin >> t_array[i];
    }
    return t_array;
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

void dfs(int current_node) {
	if (visited[current_node]){ 
        return; 
    }
    minX = min(minX, cows[current_node].first);
    maxX = max(maxX, cows[current_node].first);
    minY = min(minY, cows[current_node].second);
    maxY = max(maxY, cows[current_node].second);
	visited[current_node] = true;
	for (int neighbor : adj[current_node]) { 
        dfs(neighbor); 
    }
}
int main() {
    setIO("fenceplan");
    int m;
    cin >> n >> m;
    
    visited.resize(n);
    cows.resize(n); //useful function

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        cows[i] = {x, y};
    }
    for(int i = 0; i < m; i++){
        int firstCow, secondCow;
        cin >> firstCow >> secondCow;
        adj[firstCow-1].push_back(secondCow-1);
        adj[secondCow-1].push_back(firstCow-1);
    }
    int minPerimeter = 1e9 + 7;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            minX = 1e9 + 7;
            minY = 1e9 + 7;
            maxX = 0;
            maxY = 0;
            dfs(i);
            minPerimeter = min(minPerimeter, 2*((maxY - minY) + (maxX - minX)));
        }
    }
    cout << minPerimeter;

}
