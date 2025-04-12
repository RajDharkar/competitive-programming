#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;cin >> n;
        vector<ll> a(n), b(n);
        for(auto &x : a)cin >> x;
        for(auto &x : b)cin >> x;
        ll diff = accumulate(all(a),0LL) - accumulate(all(b),0LL);

        sort(all(b));
        if(diff<=0){
            sort(all(a));
            cout << ((a==b) ? (*max_element(all(b))+1) : -1) << '\n';   
            continue;
        }
        vector<ll> check;
        for(ll i=1; i*i<=abs(diff); i++){
            if(diff%i==0){
                check.push_back(i);
                if(diff/i!=i){
                    check.push_back(diff/i);
                }
            }
        }
        bool works = 0;
        for(auto x : check){
            //cout << x << endl;
            vector<ll> ret;
            for(ll i = 0; i < n; i++){
                ret.push_back(a[i]%x);
            }
            sort(all(ret));
            if(ret==b){
                cout << x << '\n';
                works = 1;
                break;
            }
        }
        if(!works)cout << -1 << '\n';
        // cout << ans << '\n';
    }
}