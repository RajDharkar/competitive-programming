#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
int n, q;
vector<int> arr;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int upNumber(int low, int high, int lookFor){ //lastTrue
    while(low < high){
        int mid = (low + high)/2;
        //2 3 5 7
        if(arr[mid] <= lookFor){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return low;
}
// int lowNumber(int low, int high, int lookFor){ //firstTrue

//     while(low < high){
//         int mid = low + (high + low + 1)/2;
//         //2 3 5 7
//         if(arr[mid] >= lookFor){
//             high = mid;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return high;
// }
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
    setIO("haybales");
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> q;
    // cout << q;
    arr = readVector(n); 
    sort(arr.begin(), arr.end());
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        // cout << 7 << endl;
        // vector<int>::iterator lower, upper;
        // upper = upper_bound(arr.begin(), arr.end(), b);
        // int index = upper - arr.begin();
        // lower = lower_bound(arr.begin(), arr.end(), a);
        // int index2 = lower - arr.begin();
        // cout << index << " " << index2 << '\n';
        // cout << index2 - index + 1 << '\n';
        int s = upNumber(0, n, --a);
        int g = upNumber(0, n, b);
        // int ans = greatestSmallThan - smallestGreaterThan + 1;
        cout << g - s<< '\n';
        // cout << ans << " " << smallestGreaterThan << " " << greatestSmallThan << '\n';
    }
}
