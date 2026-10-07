#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<char> chars(n + 1);
        for(ll i = 1; i <= n; i++){
            chars[i] = s[i - 1];
        }
        
        vector<ll> edges(n + 1);
ll zeros=0;
        for(ll i = 1; i < n; i++){
            edges[i] = chars[i] != chars[i + 1];
            if(chars[i] == '0') zeros++;
        }
        zeros += chars[n] == '0';
        ll ans = 0; 
        for(ll i= 1; i< n; i++){
            if(edges[i]) ans += (n-i)*i;
        }
        ll ones = n - zeros;
        // ans += (zeros * (n - zeros));
        cout << (((zeros * (n - zeros))) + ans) / 2;

        while(q--){
            ll k; cin >> k;
            if(k - 1>=1 && k - 1 < n){
                if(edges[k - 1]){
                    ans -= (n - (k - 1))* (k - 1);
                }
            }
            if(k >=1 && k < n){
                if(edges[k]){
                    ans -= (n - (k))* k;
                }
            }

            if(chars[k] == '0'){
                chars[k] = '1';
                ones++;zeros--;
            } else{
                chars[k] = '0'; ones--;zeros++;
            }
    //recomp
            if(k - 1>=1 && k - 1 < n){
                edges[k - 1] = chars[k - 1] != chars[k - 1 + 1];
                if(edges[k - 1]) ans += (n - (k - 1)) * (k - 1);
            }
            if(k>=1 && k < n){
                edges[k] = chars[k] != chars[k + 1];
                if(edges[k]) ans += (n - (k)) * (k);
            }
            cout << " " << (ans + (zeros) * (ones)) / 2;
        }
        cout<<'\n';
    }
}