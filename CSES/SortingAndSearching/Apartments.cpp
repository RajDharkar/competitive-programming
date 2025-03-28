#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> des(n);
    for(auto &x : des)cin >> x;
    vector<ll> apart(m);
    for(auto &x : apart)cin >> x;

    sort(des.begin(), des.end());
    sort(apart.begin(), apart.end());
    // cout << 1 << endl;
    vector<bool> used(m);
    int di = 0;
    int ai = 0;
    ll ans = 0;
    while(di < n && ai < m){
        if(abs(des[di]-apart[ai])<=k){
            di++;ai++;ans++;
        }
        else if(des[di]-apart[ai]>0){
            ai++;
        }
        else{
            di++;
        }
        // cout << di << " " << ai << endl;
    }
    cout << ans << endl;

}