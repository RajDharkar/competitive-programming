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

struct DSU{
    vector<int> tree;
    void init(int n){
        tree = vector<int>(n, -1); //all nodes with a size of 1(if its -x its not a "father" and it has a size of x)
    }

    int find(int node){
        return tree[node] < 0 ? node : tree[node] = find(tree[node]); //flattening the tree(path compression)
    }

    bool unite(int p, int q){
        p = find(p);
        q = find(q);
        if(p == q){
            return false; //nodes are already united
        }

        if(tree[p] < tree[q]){
            swap(p, q); //weird way to do this but now we know that the size of p is greater than the size of q
        }
        tree[p] += tree[q]; //append to the bottom of the node p
        tree[q] = p; //p is now the father of q 
        return true;
    }

    int size(int x){
        return -tree[find(x)];
    }

    bool connected(int p, int q){
        return find(p) == find(q);
    }
};


int main(){
    int n, q;
    cin >> n >> q;
    DSU dsu;
    dsu.init(n);
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;

        if(a){
            //are b and c connected?
            cout << (dsu.connected(b, c)) << '\n';
        }
        else{
            //add vertices between b and c
            dsu.unite(b, c);
        }
    }
}