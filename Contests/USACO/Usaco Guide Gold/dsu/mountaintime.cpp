#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

struct Point{
    int x, y;
};

struct Edge{
    Point a, b;
    int weight;
};

bool cmp(Edge a, Edge b){
    return a.weight > b.weight;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr[1001][1001];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    vector<Edge> edges;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int a = 0; a < 4; a++){
                Point start = {i, j};
                int elevation = arr[i][j];
                int nx = dx[a] + i;
                int ny = dy[a] + j;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    Point end = {nx, ny};
                    int elevEnd = arr[nx][ny];
                    if(elevation > elevEnd || (elevation == elevEnd && (i < nx || j < ny))){
                        edges.push_back({start, end});
                    }
                }
            }
            
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu;
    dsu.init(n * m);
    for(Edge edge : edges){
        cout << edge.a.x << " " << edge.a.y << " " << edge.b.x << " " << edge.b.y << " " << edge.weight << endl;
        //dsu.unite(edge.a.x * n + edge.a.y, edge.b.x * n + edge.b.y);
    }


}