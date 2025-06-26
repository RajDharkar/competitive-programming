#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);  

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)

vi arr;
ll qsum(ll i, ll j){
    ll temp;
    cout << "or " << i << " " << j << endl;
    ll first = 0; cin >> temp; first += temp;
    // ll first = arr[i-1] | arr[j-1];
    cout << "and " << i << " " << j << endl;
    cin >> temp; first += temp;
    // first += arr[i-1] & arr[j-1];
    return first;
}

int main(){
    ll n, k;
    cin >> n >> k;
    // res(arr, n); for(auto &x : arr)cin >> x;
    vi known(n);
    ll first = qsum(1, 2);
    ll second = qsum(2, 3);
    ll third = qsum(1, 3);
    known[0] = (first + second + third) / 2 - second;
    known[1] = (first + second + third) / 2 - third;
    known[2] = (first + second + third) / 2 - first;
    for(ll i = 3; i < n; i++){
        known[i] = qsum(1, i + 1) - known[0];
    }
    sort(all(known));
    cout << "finish " << known[k - 1] << endl;
}

