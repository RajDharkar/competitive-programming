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
    low--;
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
    
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        // cout << arr[i] << " ";
    }
    // cout << endl;
    int number;
    cin >> number;
    cout << 1+bs(number) << endl;
    
}
