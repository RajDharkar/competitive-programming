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
int n; //change when utilizing method
int leafNodes = 0;
vector<vector<int>> adj;
vector<int> potions;
vector<bool> visited;
vector<bool> isPotionPos;
vector<vector<int>> ppT;
vector<bool> isLeafNode;
int transversal = 0;
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
        isLeafNode[current_node] = true;
        leafNodes++;
    }

}
void otherdfs(int current_node) {
    if(isLeafNode[current_node]){
        transversal++;
    }
    if(transversal >= leafNodes){
        return;
    }
    cout << current_node << '\n';
    if(isPotionPos[current_node])
        ppT[transversal].push_back(current_node);
	if (visited[current_node]) { 
        return; 
    }
	visited[current_node] = true;
    
    //cout << current_node << '\n';
	for (int neighbor : adj[current_node]) { 
        otherdfs(neighbor);
    }
}
int main() {
    cin >> n;
    adj = vector<vector<int>>(n); //change when utilizing method
    visited = vector<bool>(n);
    potions = vector<int>(n);
    isLeafNode = vector<bool>(n);
    for(int i = 0; i < n; i++){
       int a;
       cin >> a;
       --a;
       potions[i] = a;
       //cout << potions[i] << '\n';
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        //cout << a << " " << b << '\n';
        a-=1;
        b-=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    cout << leafNodes << '\n';
    isPotionPos = vector<bool>(n);
    ppT = vector<vector<int>>(leafNodes);
    for(int i = 0; i < leafNodes; i++){
        isPotionPos[potions[i]] = true;
    }
    // for(bool i : isPotionPos){
    //     cout << i << '\n';
    // }
    // for(vector<int> a: adj){
    //     for(int i : a){
    //         cout << i << " ";
    //     }
    //     cout << '\n';
    // }
    for(int i = 0; i < n; i++)visited[i] = false;
    otherdfs(0);
    for(vector<int> a: ppT){
        for(int i : a){
            cout << i << " ";
        }
        cout << '\n';
    }
}
