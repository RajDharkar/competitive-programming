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
    string a, b;
    cin >> a >> b;

    ll eventop = 0;
    ll evenbottom = 0;
    ll oddbottom = 0;
    ll oddtop = 0;
    ll ttlodd= 0;
    ll ttleven = 0;
    for(ll i = 0; i < n; i+=2){
        eventop += a[i] == '1';
        evenbottom += b[i] == '1';
        ttleven++;
    }
    // bool ans2 = 1;
    for(ll i = 1; i < n; i += 2){
        oddtop+= a[i] == '1';
        oddbottom += b[i] == '1';
        ttlodd++;
        // if(a[i]=='1')found=1;
        // if(b[i]=='0')ans2=0;
    }
    bool realans = eventop + oddbottom <= ttlodd;
    // cout << eventop << " " << oddbottom << " " << ttlodd;
    realans &= oddtop + evenbottom <= ttleven;
    // bool realans = (ans && found) || (ans2 && found2);
    cout << (realans ? "YES" : "NO") << '\n';  
}  

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

