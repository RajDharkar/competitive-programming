#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1, 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i+1];
        ans += max(arr[i+1]-arr[i], 0);
    }
    cout << ans << endl;
}