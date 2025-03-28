#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &x : arr)cin >> x;

        map<ll, vector<ll>> mp; //prob can remove ltr now but its wtv
        vector<ll> ans;
        ll id=0;
        for(auto &x : arr){
            if(!sz(mp[x]))ans.pb(x);
            mp[x].pb(id);
            id++;
        }
        // for(auto x : ans)cout << x << endl;
        vector<ll> pos;
        for(ll a = 0; a < n; a++){
            if(arr[a] == ans[0])pos.pb(a);
        }
        map<ll, ll> cc;
        for(ll a = 0; a < sz(ans); a++){
            cc[ans[a]]=a;
        }
        if(sz(ans) <= 2){
            cout << sz(ans) << endl;
            continue;
        }
        ll acans = 1e9;
        for(ll z = 0; z < sz(pos); z++){
            vector<bool> sofar(sz(ans),0);
            sofar[0]=1;
            ll k = 1;
            ll i = pos[z];  
            ll ans2 = 1;
            for(ll j = i+1; j < n;j++){
                ans2++;
                if(sofar[cc[arr[j]]])continue;
                if(cc[arr[j]] == k){
                    sofar[cc[arr[j]]]=1;
                    k++;
                    if(k==sz(ans)){
                        acans = min(ans2, acans);break;
                    }
                } else{
                    break;
                    
                }
            }
        }
        if(acans == 1e9)acans = n;
        cout << acans << endl;
    }
}

