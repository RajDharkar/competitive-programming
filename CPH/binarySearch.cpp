#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
int n; //size of array
int arr[100001]; //the array of numbers
int bs(int x){
    int low = 0;
    int high = n-1; 
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int bj(int x){
    int position = 0;
    for(int jump = n/2; jump >= 1; jump/=2){
        while(arr[position] <= x - jump) position+=jump;
        if(arr[position] == x){
            return position;
        }
    }
    return -1;
}
int shortcut(int x){
    auto it = lower_bound(arr, arr + n, x);
    int position = it - arr;
    cout << position;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        // cout << arr[i] << " ";
    }
    // cout << endl;
    for(int i = 1; i <= n; i++){
        cout << i << ": " << bs(i) << " " << bj(i) << " " << shortcut(i) << endl;
    }
    
}
