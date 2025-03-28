#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

//too lazy to precompute powers of 2
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    ll k = 0;

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto &x : a)cin >> x;
    for(auto &x : b)cin >> x;

    ll dp[n+1][2];
    for(ll i = 0; i < n+1; i++){
       dp[i][0] = dp[i][1] = 1e9;
    }

    dp[0][0] = 0; //no cost for nothing
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            
        }
    }

}