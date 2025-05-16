#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second

ll n;
ll x, y;

int main(){
    ios::sync_with_stdio(false); //makes streams have independant buffers or smth 
    cin.tie(nullptr); //unties stream, doesn't automatically flush output
    cin >> n;
    cin >> x >> y;
    vector<pii> moves(n);
    for(ll i = 0; i < n; i++){
        cin >> moves[i].f >> moves[i].s;
    }
    unordered_map<string, unordered_map<ll, ll>> xytoks;
    ll half = n/2;
    for(ll mask = 0; mask < 1LL << half; mask++){
        ll xpos = 0, ypos = 0;
        ll cnt = 0;
        for(ll i = 0; i < half; i++){
            if(mask & (1 << i)){
                xpos += moves[i].f;
                ypos += moves[i].s;
                cnt++;
            }
        }
        string key = "";
        key.append(to_string(xpos));
        key.append("|");
        key.append(to_string(ypos));
        xytoks[key][cnt]++;
    }
    vector<ll> ans(n+1);
    for(ll mask = 0; mask < 1LL << (n-half); mask++){
        ll xpos = 0, ypos = 0;
        ll cnt = 0;
        for(ll i = 0; i < n-half; i++){
            if(mask & (1 << i)){
                xpos += moves[i+half].f;
                ypos += moves[i+half].s;
                cnt++;
            }
        }
        xpos = x-xpos; ypos = y-ypos;
        string key = "";
        key.append(to_string(xpos));
        key.append("|");
        key.append(to_string(ypos));
        for(auto &[a, b] : xytoks[key]){
            ans[cnt+a]+=b;
        }
    }
    for(ll i = 1; i <= n; i++){
        cout << ans[i] << '\n';
    }
}

