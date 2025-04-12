#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
    }
    set<ll> ans;
    ll q = n;
    while(q--){
        ll d;
        cin >> d;d--;
        ll orig = d;

        if(ans.count(d)){
            goto end;
        }

        ans.insert(d);
        do{
            d = arr[d];
            ans.insert(d);
        } while(arr[d] != orig);

        end:;
        arr[d]=0;
        cout << sz(ans) << " \n"[q == 0];
    }
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

