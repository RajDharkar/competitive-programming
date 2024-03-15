#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int ans = 0;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){cin >> arr[i];}
    int prev = 0;
    int currcount = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > prev){
            currcount++;
        }
        else{
            if(currcount >= 3){
                //cout << i << endl;
                ans++;
            }
            currcount = 1;
        }
        cout << currcount << " ";
        prev = arr[i];
    }
    cout << ans;
}
