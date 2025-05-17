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
    return a.s - a.d < b.s - b.d;
}

// bool othercmp(Thing a, Thing b){
//     return a.s < b.s;
// }
array<ll, 3> dp[501][501];

int main(){
    ios::sync_with_stdio(false); //makes streams have independant buffers or smth 
    cin.tie(nullptr); //unties stream, doesn't automatically flush output

    ll n, c;
    cin >> n >> c;

    vector<Thing> asc, desc;
    for(ll i = 0; i < n; i++){
        ll d, s; cin >> d >> s;
        // if(d <= s){
            asc.pb({d, s, i});
        // } else{
            // desc.pb({d, s, i});
        // }
    }

    sort(all(asc), cmp);

    // vector<ll> ans;
    const ll Mx = 1e19;
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            dp[i][j] = array<ll, 3>{Mx, Mx, -1};
        }
    }
    for(ll i = 0; i <= n; i++)dp[i][0] = array<ll, 3>{0, 0, -1};
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= i; j++){
            dp[i][j] = dp[i-1][j];
            Thing item = asc[i-1];
            auto prev = dp[i-1][j-1];
            ll need = max(prev[1], prev[0] + max(item.d, item.s));
            if (need <= c) {
                array<ll, 3> ele = array<ll, 3>{prev[0] + item.s, need, i-1};
                if (ele < dp[i][j]) dp[i][j] = ele;   
                // if(ele[0] < dp[i][j][0]){
                //     works = 1;
                // } else if(ele[0] == dp[i][j][0]){
                //     if(ele[1] < dp[i][j][1]){
                //         works = 1;
                //     }
                //     else if(ele[1] == dp[i][j][1]){
                //         works = ele[2] < dp[i][j][2];   
                //     }
                // }
                // dp[i][j] = works ? ele : dp[i][j];
            }            
        }
    }
    ll i = n;
    for(; i >= 0; i--){
        if(dp[n][i][1] <= c)break;
    }

    cout << i << '\n';
    vector<ll> ret;
    ll item = n;
    while(i > 0){
        ret.pb(asc[dp[item][i][2]].in); item = dp[item][i][2]; i--; 
    }
    for(ll x = sz(ret)-1; x >= 0; x--){
        cout << (1+ret[x]) << " \n"[x==0];
    }
    // for(auto &[d, s, i] : asc){
    //     if(c >= max(s, d)){
    //         c -= s; ans.pb(i);
    //     }
    // }
    // for(auto &[d, s, i] : desc){
    //     if(c >= max(s, d)){
    //         c -= s; ans.pb(i);
    //     }
    // }
    // cout << sz(ans) << '\n';
    // for(ll i = 0; i < sz(ans); i++){
    //     cout << ans[i]+1 << " \n"[i==sz(ans)-1];
    // }
}



