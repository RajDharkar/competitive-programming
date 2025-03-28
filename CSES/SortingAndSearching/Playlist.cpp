#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll n;
    cin >> n;

    map<ll, ll> ind;
    vector<ll> a(n);
    for(auto &x : a)cin >> x;

    ll ans = 0;
    ll prev = 0;
    for(int i = 0; i < n; i++){
        if(ind.count(a[i])){
            prev = max(prev, ind[a[i]]);// if not seen yet ind[a[i]] = 0
        }

        ans = max(ans, i - prev + 1);

        ind[a[i]]=i+1;
    }

    cout << ans;
}

