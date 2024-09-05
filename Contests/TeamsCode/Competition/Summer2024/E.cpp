#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& data, bool isMaxTree) : n(data.size()), isMaxTree(isMaxTree) {
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

private:
    vector<int> tree;
    int n;
    bool isMaxTree;  // True for max tree, false for min tree

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            if (isMaxTree) {
                tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
            } else {
                tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
            }
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return isMaxTree ? INT_MIN : INT_MAX;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int leftQuery = query(2 * node + 1, start, mid, l, r);
        int rightQuery = query(2 * node + 2, mid + 1, end, l, r);
        return isMaxTree ? max(leftQuery, rightQuery) : min(leftQuery, rightQuery);
    }
};

class SegmentTreeExist {
public:
    SegmentTreeExist(const vector<int>& data, int K) : n(data.size()), K(K) {
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    bool query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

private:
    vector<bool> tree;
    int n;
    int K;

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = (data[start] == K);
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] || tree[2 * node + 2];
        }
    }

    bool query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return false;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) || query(2 * node + 2, mid + 1, end, l, r);
    }
};

int countGoodSubarrays(const vector<int>& A, int X, int Y, int K) {
    int N = A.size();
    SegmentTree maxTree(A, true);
    SegmentTree minTree(A, false);
    SegmentTreeExist existTree(A, K);
    int count = 0;

    for (int start = 0; start < N; ++start) {
        for (int end = start; end < N; ++end) {
            int maxVal = maxTree.query(start, end);
            int minVal = minTree.query(start, end);
            bool hasK = existTree.query(start, end);
            
            if (maxVal == X && minVal == Y && !hasK) {
                ++count;
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int N, X, Y, K;
        cin >> N >> X >> Y >> K;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        cout << countGoodSubarrays(A, X, Y, K) << '\n';
    }

    return 0;
}
