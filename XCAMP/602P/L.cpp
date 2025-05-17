#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first

struct Thing{
    ll d, s, in;
};

bool cmp(Thing a, Thing b){
    return (a.s+a.d) > (b.s+b.d);
}

bool othercmp(Thing a, Thing b){
    return a.d < b.d;
}
const ll MN = -1e9;
// ll dp[101];

int main(){
    ios::sync_with_stdio(false); //makes streams have independant buffers or smth 
    cin.tie(nullptr); //unties stream, doesn't automatically flush output

    ll n, c;
    cin >> n >> c;

    vector<Thing> asc, desc;
    for(ll i = 0; i < n; i++){
        ll d, s; cin >> d >> s;
        if(s>=0){
            asc.pb({d, s, i});
        } else{
            desc.pb({d, s, i});
        }
    }
    sort(all(asc), othercmp);
    ll cnt = 0;
    for(ll i = 0; i < sz(asc); i++){
        if(c >= asc[i].d){
            cnt++;
            c+=asc[i].s;
        }
    }
    // fill(dp, dp+n, -1e9);
    sort(all(desc), cmp);
    // n = sz(desc);
    // dp[0] = c;
    int m = desc.size();
    vector<ll> dp(m+1, -1e9);
    dp[0] = c;
    for(ll i = 0; i < m; i++){
        for(ll j = i; j >= 0; j--){
            if(dp[j] >= desc[i].d && dp[j] + desc[i].s >= 0){ //if we can take {
                dp[j+1] = max(dp[j+1], dp[j] + desc[i].s);
            }
        }
    }

    for(ll i = m; i >= 0; i--){
        if(dp[i]>=0){
            cnt+=i;
            break;
        }
    }
    cout << cnt << '\n';
}



