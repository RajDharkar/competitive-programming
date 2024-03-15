#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[5 * n];
    
    for (int i = 0; i < 5 * n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + 5 * n);
    
    int sum = 0;
    for (int i = n; i < 4 * n; i++) {
        sum += arr[i];
    }
    
    cout << double(double(sum) / (3 * n));
    
    return 0;
}
