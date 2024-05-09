#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int n, l;
    cin >> n >> l;
    int arr[n]; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }                                                           
    sort(arr, arr + n);
    int sum = arr[n-1];
    int ans = 1;
    for(int i = 0; i < n; i++){
        int score = i + 1;
        if(score * i - sum <= l){
            ans = score;
        }
        sum+=arr[n-i-1];
    }
    cout << ans << endl;
}
