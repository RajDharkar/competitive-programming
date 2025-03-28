#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

ll lower_bound_unsorted(const vector<ll>& arr, ll val) {
    for(ll i = 0; i < sz(arr); i++) {
        if(arr[i] >= val) return i;
    }
    return sz(arr); 
}

ll upper_bound_unsorted(const vector<ll>& arr, ll val) {
    for(ll i = 0; i < sz(arr); i++) {
        if(arr[i] > val) return i;
    }
    return sz(arr); 
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &x:arr)cin >> x;
        ll ans = 0;
        // while(i <= sz(arr)) {
        //     ll left = (i-1+n)%n;
        //     ll right = (i+1)%n;
        //     if(arr[i] <= arr[right]){
        //         i++;
        //     }
        //     else{
        //         // cout << "HERE" << " " << arr[i] << endl;
        //         // arr.pb(arr[i], ) //add this to the proper sorted position
        //         // ans++
        //         auto it = lower_bound(all(arr), arr[i]);
        //         arr.insert(it, arr[i]);
        //         arr.erase(arr.begin()+i);
        //         break;
        //     }
        // }
        ll curprev = 1e9;
        ll curmax = 0;
        ll i = 0;
        while(i < sz(arr)) {
            if(arr[i] > curprev && arr[i] < curmax) {
                cout << "TRUE " << arr[i] << endl;
                ll temp = arr[i];          
                arr.erase(arr.begin() + i); 
                ll pos = upper_bound_unsorted(arr, temp);
                if(pos == 0)
                    pos = lower_bound_unsorted(arr, temp);

                arr.insert(arr.begin() + pos, temp);
                break;
            } else {
                if(arr[i] <=curprev){
                    curprev = arr[i];
                }
                if(arr[i] >= curmax){
                    curmax = arr[i];
                }
                i++;
            }
        }
        for(auto x : arr){
            cout << x << endl;
        }
        curprev = 1e9;
        curmax = 0;
        for(ll i = 0; i < n; i++){
            if(arr[i] > curprev && arr[i] < curmax){
                ans++;
                break;
            }
            else{
                if(arr[i] <=curprev){
                    curprev = arr[i];
                }
                if(arr[i] >= curmax){
                    curmax = arr[i];
                }
            }
            // cout << curprev << " " << curmax << " " << arr[i] << endl;
        }
        cout << (ans < 1 ? "YES" : "NO") << endl;
    }
}

