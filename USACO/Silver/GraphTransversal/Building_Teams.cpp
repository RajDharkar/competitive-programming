#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;
bool dfs(int node) {
	int curr = ans[node];
	int nColor = curr == 1 ? 2 : 1;  // The color the neighbors should be
	for (int n : adj[node]) {
		if (ans[n] != 0) {
			// Check if the already existing color lines up
			if (ans[n] != nColor) { return false; }
		} else {
			ans[n] = nColor;
			if (!dfs(n)) {
				return false;  // We stop as soon as we hit a contradiction
			}
		}
	}
	return true;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    ans = vector<int>(n);
    for(int i = 0; i < m; i++) {
        int cow1, cow2;
        cin >> cow1 >> cow2;
        adj[--cow1].push_back(--cow2); // No need to subtract 1 here
        adj[cow2].push_back(cow1); // No need to subtract 1 here
    }

    // for(int i = 0; i < n+1; i++){
    //     cout << "Node " << i << ": ";
    //     for(int j : adj[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    bool good = true;
    for(int i = 0; i < n; i++){
        if(ans[i] == 0){
            ans[i] = 1;
            if(!dfs(i)){
                good = false;
                break;
            }
        }
    }
    if(good){
        for(int i = 0; i < n-1; i++){
            cout << ans[i] << " ";
        }
        cout << ans[n-1];
    }
    else{
        cout << "IMPOSSIBLE";
    }
}
