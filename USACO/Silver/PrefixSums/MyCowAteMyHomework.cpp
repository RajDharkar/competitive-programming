#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()




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
    vector<int> t_vector(size, 0);
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        t_vector[i] = a;
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
    setIO("homework");
    int n = readInt(); 
    vector<int> arr = readVector(n); 
    vector<int> indexOfMins(n, 0); //index == k
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << '\n';
    int minValue = 10001;
    int minIndex = n-1;
    for(int i = n-1; i >=0; i--){
        if(arr[i] < minValue){
            minValue = arr[i];
            minIndex = i;   
        }
        indexOfMins[i] = minIndex;
    }
    
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for(int i = 1; i < n+1; i++){
        prefix[i] = arr[i-1] + prefix[i-1];
    }
    // for(int i = 0; i < 1+n; i++){
    //     cout << prefix[i] << " ";
    // }
    double curMax = 0;
    set<int> ans;
    for(int k = 1; k < n - 1; k++){
        double total = (prefix[indexOfMins[k]] - prefix[k] + prefix[n] -  prefix[indexOfMins[k]+1])/(double)(n-k - 1);
        // cout << k << " ";
        // cout << total << '\n';
        if(total > curMax){
            curMax = total;
            ans.clear();
            ans.insert(k);
        }
        if(total == curMax){
            ans.insert(k);
        }
    }
    //cout << '\n';
    for(int i : ans){
        cout << i << '\n';
    }



    return 0;
}
