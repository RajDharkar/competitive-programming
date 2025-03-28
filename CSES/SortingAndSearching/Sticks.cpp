#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr)cin >> x;
    sort(all(arr));
    ll med = arr[n/2];
    ll sum = 0;
    for(auto x : arr)sum += abs(med-x);
    cout << sum << endl;
}

