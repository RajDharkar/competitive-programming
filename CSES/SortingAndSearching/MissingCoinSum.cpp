#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr)cin >> x;
    sort(all(arr));
    //1 2 2 7 9
    ll ans = 0; 
    for(int i = 0; i < n; i++){
        ll x = arr[i];
        if(x > ans + 1){
            break;
        }
        ans += arr[i];
    }        
    cout << ans+1 << endl;
}

