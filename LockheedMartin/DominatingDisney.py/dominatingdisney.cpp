#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

// Global adjacency list
unordered_map<string, vector<pair<string, int>>> adjacencyList;
int arr[7];  // Array to store the time for each path

// To store the path taken as path indices
vector<int> currentPath;
vector<int> bestPath;  // To store the best path found

// Mapping of attraction names to their corresponding numbers
unordered_map<string, int> attractionToNumber = {
    {"Splash Mountain", 1},
    {"Pirates of the Caribbean", 2},
    {"Seven Dwarfs", 3},
    {"Space Mountain", 4},
    {"START", 0}
};

// Minimum cost to visit all attractions
int minPathCost = INT_MAX;

void dfs(string node, int depth, bool seen1, bool seen2, bool seen3, bool seen4, int cost) {
    // Stop searching if depth exceeds 9
    if (depth > 20) return;

    // Mark attractions as seen if encountered
    if (node == "Splash Mountain") seen1 = true;
    else if (node == "Pirates of the Caribbean") seen2 = true;
    else if (node == "Seven Dwarfs") seen3 = true;
    else if (node == "Space Mountain") seen4 = true;

    // Base case: if all attractions are seen and cost is minimized
    if (seen1 && seen2 && seen3 && seen4) {
        if (cost < minPathCost) {
            minPathCost = cost;
            bestPath = currentPath;
        } else if (cost == minPathCost && currentPath < bestPath) {
            bestPath = currentPath;
        }
        return;
    }

    // Sort neighbors by cost and path index
    auto& neighbors = adjacencyList[node];
    sort(neighbors.begin(), neighbors.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (arr[a.second - 1] != arr[b.second - 1]) {
            return arr[a.second - 1] < arr[b.second - 1];
        }
        return a.second < b.second;
    });

    for (const auto& p : neighbors) {
        int pathIdx = p.second - 1;  // Path index in the `arr` array
        string nextNode = p.first;

        if (find(currentPath.begin(), currentPath.end(), pathIdx) == currentPath.end()) {  // Avoid revisiting
            currentPath.push_back(pathIdx);
            dfs(nextNode, depth + 1, seen1, seen2, seen3, seen4, cost + arr[pathIdx]);
            currentPath.pop_back();  // Backtrack
        }
    }
}

int main() {
    // Define adjacency list for the paths
    adjacencyList["START"] = {{"Splash Mountain", 3}, {"Pirates of the Caribbean", 1}, {"Seven Dwarfs", 5}, {"Space Mountain", 7}};
    adjacencyList["Splash Mountain"] = {{"START", 3}, {"Seven Dwarfs", 4}, {"Pirates of the Caribbean", 2}};
    adjacencyList["Pirates of the Caribbean"] = {{"START", 1}, {"Splash Mountain", 2}};
    adjacencyList["Seven Dwarfs"] = {{"START", 5}, {"Space Mountain", 6}, {"Splash Mountain", 4}};
    adjacencyList["Space Mountain"] = {{"START", 7}, {"Seven Dwarfs", 6}};

    int t;
    cin >> t;
    while (t--) {
        // Input the time for each path
        for (int i = 0; i < 7; i++) {
            cin >> arr[i];
        }

        // Clear the best path and current path for each test case
        bestPath.clear();
        currentPath.clear();
        minPathCost = INT_MAX;

        // Start DFS from "START" and find the minimum cost to visit all attractions within depth 9
        dfs("START", 0, false, false, false, false, 0);

        if (bestPath.empty() || minPathCost == INT_MAX) {
            cout << "WILL NOT FIT" << endl;
        } else {
            for (const int& pathIndex : bestPath) {
                cout << pathIndex + 1 << " ";  // Print the paths as numbers
            }
            cout << endl;
        }
    }

    return 0;
}
