#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> visited;
vector<int> works;
vector<int> a;
vector<vector<int>> allcomponents;

void dfs(int node) {
    vector<int> s;
    while (true) {
        int color = visited[node];
        if (!color) {
            visited[node] = 1; 
            s.push_back(node);
            node = a[node]; 
        } 
        else {
            if (color == 1) { 
                vector<int> cycle;
                int index = find(s.begin(), s.end(), node) - s.begin();
                for (int i = index; i < s.size(); i++) {
                    cycle.push_back(s[i]);
                    works[s[i]] = 1;
                }
                allcomponents.push_back(cycle);
            }
            for (int i = 0; i < s.size(); i++) visited[s[i]] = 2;  
            break;
        }
    }
}

ll dfs2(int i, vector<vector<int>> adj){

}

int main() {
    cin >> n;
    a.resize(n);
    works.resize(n);
    visited.resize(n);

    for (auto &x : a) {
        cin >> x;
        x--;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {  
            dfs(i);
        }
    }

    vector<int> cost(n);
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    // for (const auto &cycle : allcomponents) {
    //     for (int node : cycle) {
    //         cout << node + 1 << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<int>> backwardsadj(n);
    for(int i = 0; i < n; i++){
        backwardsadj[a[i]].push_back(i);
    }
    vector<ll> lonely(n);
    for(int i = 0; i < n; i++){
        // if(!works[i])
    }
}
