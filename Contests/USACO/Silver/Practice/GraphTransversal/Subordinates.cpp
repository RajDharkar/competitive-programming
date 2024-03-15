#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;
int dfs(int current_node) {
    if (visited[current_node]) {
        return 0; // Already visited, return 0
    }
    visited[current_node] = true;
    ans[current_node] = 1; // Initialize with 1 for the current node

    for (int neighbor : adj[current_node]) {
        ans[current_node] += dfs(neighbor); // Accumulate ans for neighbors
    }
    return ans[current_node];
}

int main() {
    int n;
    cin >> n;

    adj = vector<vector<int>>(n);
    visited.assign(n, false);
    ans.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        a--; // Adjust index to start from 0
        int b = i + 1; // Neighboring node
        adj[a].push_back(b);
        adj[b].push_back(a); // Since it's an undirected graph
    }
    dfs(0);
    for(int i = 0; i < n-1; i++){
        cout << --ans[i] << " ";
    }
    cout << --ans[n-1];
    return 0;
}
