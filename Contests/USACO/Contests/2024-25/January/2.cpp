#include <bits/stdc++.h>
using namespace std;

class DSU {
    private:
        vector<int> p;
        vector<int> s;
    public:
        DSU(int n) : p(n), s(n, 1){
            for(int i = 0; i < n; i++){
                p[i] = i;
            }
        }

        int f(int x) {return p[x] == x ? x : (p[x] = f(p[x]));}
        bool unite(int x, int y){
            int fx = f(x);
            int fy = f(y);
            if (fx == fy){
                return false;
            }

            if(s[fx] < s[fy]){
                swap(fx, fy); 
            }

            s[fx] += s[fy];
            p[fy] = fx;
            return true;
        }

        bool if_connected(int x, int y){
            return f(x) == f(y);
        } //actually use this one

        int sz(int node){
            return s[f(node)];
        }
};


/*
Consider an undirected graph with N
 nodes labeled 1…N
 and M
 edges (1≤N≤2⋅105,0≤M≤4⋅105
). You're given a binary string s1s2…sN
. At time t
 for each t∈[1,N]
,

If st=0
, node t
 is removed from the graph.
If st=1
, node t
 is removed from the graph, and edges are added between every pair of neighbors that node t
 had just before removal.
Note that in both cases, when a node is removed from the graph all of its incident edges are removed as well.

Count the number of pairs of nodes that can reach each other via some sequence of edges just before each of timesteps 1…N
.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains N
 and M
.
The second line contains the bit string s
 of length N
.

The next M
 lines each contain two integers denoting an edge of the graph.

OUTPUT FORMAT (print output to the terminal / stdout):
N
 lines, the number of pairs before each timestep.
SAMPLE INPUT:
3 2
111
1 2
1 3
SAMPLE OUTPUT:
3
1
0
Before any removals, all pairs of nodes are reachable from each other. After node 1
 is removed, an edge is added between 2
 and 3
, so they can still reach each other.

SAMPLE INPUT:
3 2
000
1 2
1 3
SAMPLE OUTPUT:
3
0
0
Before any removals, all pairs of nodes are reachable from each other. After node 1
 is removed, 2
 and 3
 can no longer reach each other.

SAMPLE INPUT:
7 8
1101101
6 2
1 2
2 3
6 3
1 3
1 7
4 5
2 7
SAMPLE OUTPUT:
11
7
4
2
1
1
0
SCORING:
Inputs 4-6: N≤100
Inputs 7-8: All si
 equal zero.
Inputs 9-11: All si
 equal one.
Inputs 12-23: No additional constraints.

Problem credits: Benjamin Qi
*/

typedef int ll; //CHANGE LATER

int chooseTwo(int n){
    return (n * (n - 1)) / 2; //lol forgot the aime days
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string bin;
    cin >> bin;
    DSU dsu(n);

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        dsu.unite(a-1, b-1);
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    vector<bool> used(n, 0);
    vector<ll> ans; 
    ll cans = 0;
    for(int i = n; i > 0; i--){ //build the graph in reverse maybe??
        i--; //0index
        if(bin[i] == '1'){
            used[i] = 1;
            for(int node : adj[i]){
                // n choose 2??
                cout <<  i << ": node " << node << used[node] << endl;
                int a = dsu.sz(i);
                int b = dsu.sz(node);
                if(used[node]){
                    // we gotta update our ans here
                    // dont wnat to loop through all nodes 
                    // we could try 

                    bool united = dsu.unite(i, node); 


                    cans -= chooseTwo(a); //fix with lost nodes of i connections
                    cans -= chooseTwo(b); //fix with lost nodes of "node" 
                    cans += chooseTwo(dsu.sz(i));//after adding what did we gain
                }
            }
        }
        cout<<i<<endl;
        for(auto a : used){
            cout << a << " ";
        }
        cout << '\n';
        ans.push_back(cans);
    }


    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }

    // int test_count = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         test_count += dsu.if_connected(i, j);
    //     }
    // }
    // cout << test_count;
}