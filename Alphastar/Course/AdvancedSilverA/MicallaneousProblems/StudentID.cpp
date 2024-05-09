#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("div7");
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> pref;
    pref.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pref.push_back((pref[i] + arr[i]) % 7);
    }
    // for(int i = 0; i < n+1; i++){
    //     cout << pref[i] << endl;
    // }
    ll ans = 0;
    for(int rem = 0; rem < 7; rem++){
        bool first = false;
        ll firstPart = 0;
        for(int i = 0; i < n; i++){
            if(pref[i] == rem){
                first = true;
                firstPart = i;
                break;
            }
        }
        bool end = false;
        ll lastPart = 0;
        for(int i = n-1; i >= 0; i--){
            if(pref[i] == rem){
                end = true;
                lastPart = i;
                break;
            }
        }
        if(first && end){
            //cout << lastPart << " " << firstPart << endl;
            ans = max((lastPart - firstPart), ans);
        }
    }
    cout << ans << endl;
}
