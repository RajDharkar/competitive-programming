#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
vector<pair<ll, ll>> arr;


ll compute(ll a, ll b){
    // if(a<b)swap(a,b);
    ll dist = arr[b].f - arr[a].f;
    ll speedsum = arr[b].s + arr[a].s;
    
    return 2 * ((dist + speedsum - 1) / speedsum) - (a % 2 == 0);

}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        arr.clear();
        arr.resize(n);
        for(ll i = 0; i < n; i++){
            cin >> arr[i].f;
        }

        for(ll i = 0; i < n; i++){
            cin >> arr[i].s;
        }
            // sort(all(arr));

        map<ll, ll> mp;
        for(ll i = 0; i < n; i++){
            mp[arr[i].f]=i;
        }
        
        vector<ll> ans(n);
        // cout << ans[890] << endl;
        // cout << compute(0, 1) << endl;
        while(!arr.empty()) { 
            ll minTime = 1e18;
            ll ind = -1;
            for(int i = 1; i < sz(arr); i++){
                ll comp = compute(i-1,i);
                // cout << comp << endl;
                if(comp < minTime){
                    minTime = comp;
                    ind = i;
                }
            }
            ans[mp[arr[ind].f]] = ans[mp[arr[ind-1].f]] = minTime;

            arr.erase(find(all(arr), arr[ind]));
            arr.erase(find(all(arr), arr[ind-1]));
            // cout << ind << " " << ind-1 << endl;
            // cout << arr[ind].f << " " << mp[arr[ind].f] << endl;
            // cout << arr[ind-1].f << " " << mp[arr[ind-1].f] << endl;

            // cout << ind << endl;
        }

        for(int i = 0; i < n; i++){
            cout << ans[i] << " \n"[i == n- 1];
        }
    }
}  

