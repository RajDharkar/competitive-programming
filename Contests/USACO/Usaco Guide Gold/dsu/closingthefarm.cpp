#include <bits/stdc++.h>
using namespace std;

// struct DSU {
//     vector<int> fathers;
//     vector<int> heights;
//     void init(int n){
//         heights = vector<int>(n, 1);
//         fathers = vector<int>(n, 0);
//         for(int i = 0; i < n; i++){
//             fathers[i] = i;
//         }
//     }

//     int find(int node){
//         if(fathers[node] == node){
//             return node;
//         }
//         return fathers[node] = find(fathers[node]); //this is us flattening the tree
//     }

//     bool unite(int p, int q){
//         int fatherP = find(p);
//         int fatherQ = find(q);
//         if(fatherP == fatherQ){
//             return false;
//         } //already united

//         if(heights[fatherP] < heights[fatherQ]){
//             swap(fatherP, fatherQ); //a convenient but i feel as though weird way to minimize code
//         }
//         //now we know that fatherP has the greater height
//         heights[fatherP] += heights[fatherQ];
//         fathers[fatherQ] = fatherP;
//         return true;
//     }

//     bool connected(int p, int q){
//         return find(p) == find(q);
//     }
// };

struct DSU
{
    vector<int> tree;
    void init(int n)
    {
        tree = vector<int>(n, -1); // all nodes with a size of 1(if its -x its not a "father" and it has a size of x)
    }

    int find(int node)
    {
        return tree[node] < 0 ? node : tree[node] = find(tree[node]); // flattening the tree(path compression)
    }

    bool unite(int p, int q)
    {
        p = find(p);
        q = find(q);
        if (p == q)
        {
            return false; // nodes are already united
        }

        if (tree[p] < tree[q])
        {
            swap(p, q); // weird way to do this but now we know that the size of p is greater than the size of q
        }
        tree[p] += tree[q]; // append to the bottom of the node p
        tree[q] = p;        // p is now the father of q
        return true;
    }

    int size(int x)
    {
        return -tree[find(x)];
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
};

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, q;
    cin >> n >> q;
  //  cout << "n: " << n << ", q: " << q << endl;

    vector<vector<int>> adj(n);
    DSU dsu;
    dsu.init(n);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
       // dsu.unite(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
      //  cout << "Edge: " << a << " " << b << endl;
    }

    vector<int> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[n - i - 1];
        nodes[n - i - 1]--;
       // cout << "Reversed node: " << nodes[n - i - 1] << endl;
    }

    // for (int i = 0; i < n; i++)
    //     cout << nodes[i] << " ";
    // cout << endl;
    vector<int> closed(n, 1);
    vector<string> ans = {};
    int cc = 0;
    int i = 0;
    for (const auto &node : nodes){
        cc++;
        bool works = 1;
        closed[node] = 0;
        for (const auto &connected : adj[node]){
            if (!closed[connected]){
                if(dsu.unite(node, connected)){
                    cc--;
                }
            }
        }
        ans.push_back(cc == 1 ? "YES" : "NO");
    }

    reverse(ans.begin(), ans.end());
    for (const auto &res : ans){
        cout << res << endl;
    }
}