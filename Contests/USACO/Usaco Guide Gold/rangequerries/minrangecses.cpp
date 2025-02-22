#include<bits/stdc++.h>

using namespace std;

template<class T> class MinSegTreeRecursive {
    private:
        const T DEFAULT = numeric_limits<T>::max();

        int len;
        vector<T> tree;

        T combine(const T &a, const T &b){
            return min(a, b);
        }

        void build(const vector<T> &arr, int node, int node_left, int node_right){
            if(node_left == node_right){
                tree[node] = arr[node_left]; 
                return;
            }
            int mid = (node_left + node_right) / 2;
            build(arr, 2 * node, node_left, mid);
            build(arr, 2 * node + 1, mid + 1, node_right);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }

        void update(int index, T val, int node, int node_left, int node_right){
            if(node_left == node_right){
                tree[node] = val;
                return;
            }
            int mid = (node_left + node_right) / 2;
            if(index <= mid){
                update(index, val, 2 * node, node_left, mid);
            }
            else{
                update(index, val, 2 * node + 1, mid + 1, node_right);
            }

            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }

        T range_min(int start, int end, int node, int node_left, int node_right){
            if(node_right < start || end < node_left){
                return DEFAULT; 
            }

            if(start <= node_left && node_right <= end){
                return tree[node]; 
            }

            int mid = (node_left + node_right) / 2;

            T left_min = range_min(start, end, 2 * node, node_left, mid);
            T right_min = range_min(start, end, 2 * node + 1, mid + 1, node_right);
            return combine(left_min, right_min);
        }

    public:
        MinSegTreeRecursive(int len) : len(len) {
            tree = vector<T>(len * 4, DEFAULT);
        }

        MinSegTreeRecursive(const vector<T> &arr) : len(arr.size()){
            tree = vector<T>(len * 4, DEFAULT);
            build(arr, 1, 0, len - 1);
        }

        void set(int index, T val){
            update(index, val, 1, 0, len - 1);
        }

        T range_min(int start, int end){
            return range_min(start, end, 1, 0, len - 1);
        }
};

typedef long long ll;

int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    MinSegTreeRecursive<ll> tree(arr);
    for(int i = 0; i < q; i++){
        int a;
        cin >> a;
        int x, y;
        cin >> x >> y;
        if(a == 2){
            cout << tree.range_min(x - 1, y - 1) << "\n"; 
        }
        else{
            tree.set(x - 1, y); 
        }
    }
}
