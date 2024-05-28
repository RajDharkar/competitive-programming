#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        bool works = true;
        for (int i = 2; i < n; i++) {
            if (arr[i] % arr[0] != 0 && arr[i] % arr[1] != 0) {
                works = false;
                break;
            }
        }
        
        if (!works) {
            cout << "No";
        } else {
            cout << "Yes";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
