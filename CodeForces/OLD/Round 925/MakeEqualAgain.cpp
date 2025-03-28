#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //leftside
    int same = arr[0];
    int left = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] != same){
            left = i;
            break;
        }
    }
    same = arr[n-1];
    int right = -1;
    for(int i = n-1; i >=0; i--){
        if(arr[i] != same){
            right = i;
            break;
        }
    }
    if(right < left){
        cout << 0 << '\n';
        return;
    }
    if(arr[0] == arr[n-1]){
        cout << right - left + 1 << '\n';
        return;
    }
    else{
        cout << max(n-1-left+1, right-0+1) << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    for(int test = 0; test < t; test++){
        solve();
    }
}
