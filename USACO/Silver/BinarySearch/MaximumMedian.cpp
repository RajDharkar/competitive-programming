#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
int n;
int m;
vector<int> arr;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
bool possible(int mid){
    int sum = 0;
    for(int i = n/2; i < n; i++){
        sum += max(0, (mid - arr[i]));
    }
    if(sum <= m){
        return true;
    }
    return false;
}
int last_true(int lo, int hi) {
	// if none of the values in the range work, return lo - 1
	lo--;
	while (lo < hi) {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
		if (possible(mid)) {
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
    int size = 5; //change when utilizing method
    vector<vector<int>> adj(size); //change when utilizing method
    vector<bool> visited(size); //change when utilizing method
	if (visited[current_node]) { return; }
	visited[current_node] = true;

	for (int neighbor : adj[current_node]) { dfs(neighbor); }
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    arr = readVector(n); 
    sort(arr.begin(), arr.end());
    cout << last_true(0, 2e9);
}
