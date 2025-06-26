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

void solve(){
    int n;
    cin >> n;
    vi arr(n);
    for(auto &x : arr)cin >> x;
    if(n == 1){
        cout << "YES" << '\n';
        return;
    }
    bool w=1;
    int equal = arr[1] - arr[0];
    for(int i = 1; i < n; i++){
        w &= (arr[i] - arr[i-1]) == equal;
        arr[i-1] -= equal * (equal > 0 ? i : n - i + 1);
    }
    arr[n-1] -= equal * (equal > 0 ? 1 : n);
    for(auto x : arr){
        cout << x << '\n';
    }

    cout << (w ? "YES" : "NO") << '\n';

}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

