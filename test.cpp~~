#include <bits/stdc++.h>
using namespace std;

long long computeSegmentCost(const vector<long long>& circularArray, const vector<long long>& prefixSum, int start, int n) {
    int mid = (start + n / 2) % (2 * n); // Calculate the circular midpoint
    long long median = circularArray[mid];
    
    // Calculate left part
    long long leftPart = 0;
    if (mid >= start) {
        leftPart = median * (mid - start) - (prefixSum[mid] - prefixSum[start]);
    } else {
        leftPart = median * (mid + 2 * n - start) - (prefixSum[mid] + prefixSum[2 * n] - prefixSum[start]);
    }
    
    // Calculate right part
    int end = (start + n) % (2 * n);
    long long rightPart = 0;
    if (end >= mid + 1) {
        rightPart = (prefixSum[end] - prefixSum[mid + 1]) - median * (end - mid - 1);
    } else {
        rightPart = (prefixSum[end] + prefixSum[2 * n] - prefixSum[mid + 1]) - median * (end + 2 * n - mid - 1);
    }
    
    return leftPart + rightPart;
}

void processTestCase() {
    long long n, m;
    cin >> n >> m;

    vector<long long> original(n), mods(n);
    for (long long& value : original) {
        cin >> value;
    }
    for (int i = 0; i < n; ++i) {
        mods[i] = original[i] % m;
    }

    if (m == 1) {
        cout << 0 << "\n";
        return;
    }

    sort(mods.begin(), mods.end());

    // Create a circular array with 2n elements
    vector<long long> circularArray(2 * n);
    for (int i = 0; i < n; ++i) {
        circularArray[i] = mods[i];
        circularArray[i + n] = mods[i] + m;
    }

    // Calculate prefix sum for the circular array
    vector<long long> prefixSum(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + circularArray[i];
    }

    // Compute the minimum cost
    long long minCost = LLONG_MAX;
    for (int start = 0; start < 2*n; ++start) {
        long long cost = computeSegmentCost(circularArray, prefixSum, start, n);
        minCost = min(minCost, cost);
    }

    cout << minCost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        processTestCase();
    }

    return 0;
}
