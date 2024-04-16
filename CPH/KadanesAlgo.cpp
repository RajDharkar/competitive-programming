#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int arr[] = {1, -3, 2, 5, -4, 6, 2};
    int n = 7;
    int ans = arr[0];
    int curSum = 0;
    for(int i = 0; i < n; i++){
        curSum = max(arr[i], arr[i] + curSum);
        ans = max(curSum, ans);
    }
    cout << ans;



}
