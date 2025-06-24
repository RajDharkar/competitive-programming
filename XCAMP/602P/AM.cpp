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


int main(){
    fastio
    ll n;
    cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;

    if(n==1){
        cout << arr[0]; return 0;
    }

    stack<pii> m;
    m.push({0,0});
    vi ans(n), ans2(n);

    for(ll i = 0; i < n; i++){
        ll x = arr[i];
        while(!m.empty() && m.top().f > x){
            pii t = m.top();
            m.pop();
            ans[t.s] = max(ans[t.s], (i-t.s) * t.f);
        }
        m.push({x,i});
    }
    while(!m.empty()){
        pii t = m.top();
        m.pop();
        ans[t.s] = max(ans[t.s], (n-t.s) * t.f);
    }

    for(ll i = n-1; i >= 0; i--){
        ll x = arr[i];
        while(!m.empty() && m.top().f > x){
            pii t = m.top();
            m.pop();
            ans2[t.s] += (t.s-i) * t.f;
        }
        m.push({x,i});
    }
    while(!m.empty()){
        pii t = m.top();
        m.pop();
        ans2[t.s] += (t.s + 1) * t.f;
    }

    ll mx = 0;
    for(ll i=0;i<n;i++){
        ll sum = ans[i] + ans2[i] - arr[i];
        mx = max(mx, sum);
    }

    cout << mx << '\n';
}