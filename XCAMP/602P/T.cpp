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

const ll MOD = 1e9+7;

ll n, a, b;
vector<ll> digits, x;

void fillx(ll k){
    ll temp = k;
    x.clear();
    if(k == 0)x.pb(0);
    while(temp > 0){
        x.pb(temp % 10);
        temp /= 10;
    }
    reverse(all(x));
}

ll compare(ll x, ll y){
    if(x == y)return 1;
    if(x > y)return 2;
    return 0;
}

ll dp[300][19][19][3];
vector<vector<ll>> calcdp(){
    vector<vector<ll>> ret(n, vector<ll>(n));
    for(ll i = 0; i < n; i++){
        memset(dp, 0, sizeof(dp));
        for(ll j = i; j < n; j++){
            for(ll k = 0; k < sz(x); k++){
                dp[j][k][k][compare(digits[j], x[k])]+=2;
            }
            if(i==j)continue;
            for(ll l = sz(x)-1; l >= 0; l--){
                for(ll z = 0; z < 3; z++)dp[j][l][l][z] += dp[j-1][l][l][z];
                for(ll r = l+1; r < sz(x); r++){
                    //ignore paper
                    for(ll z = 0; z < 3; z++)dp[j][l][r][z] += dp[j-1][l][r][z];

                    //place the paper on top
                    ll val = compare(digits[j], x[l]);
                    if(val == 0){
                        //all values must be less than
                        for(ll z = 0; z < 3; z++)dp[j][l][r][0] += dp[j-1][l+1][r][z];
                    }
                    if(val == 1){
                        //equal to, we place it as the first digit but assume it won't change <, >, ==
                        for(ll z = 0; z < 3; z++)dp[j][l][r][z] += dp[j-1][l+1][r][z];
                    }
                    if(val == 2){
                        //should make sense lookinga t the others
                        for(ll z = 0; z < 3; z++)dp[j][l][r][2] += dp[j-1][l+1][r][z];
                    }

                    //place paper on the bottom
                    val = compare(digits[j], x[r]);
                    for(ll z = 0; z < 3; z += 2)//0 and 2
                        dp[j][l][r][z] += dp[j-1][l][r-1][z];
                    
                    //now placing on bottom
                    dp[j][l][r][val] += dp[j-1][l][r-1][1];
                    
                    for(ll z = 0; z < 3; z++)dp[j][l][r][z] %= MOD;
                }
            }
            for (ll k = 0; k < sz(x); ++k) {
                if (k == 0) {
                    ret[i][j] = (ret[i][j] + dp[j][0][sz(x)-1][0]) % MOD;
                    ret[i][j] = (ret[i][j] + dp[j][0][sz(x)-1][1]) % MOD;
                } else {
                    for (ll z = 0; z < 3; ++z)ret[i][j] = (ret[i][j] + dp[j][k][sz(x)-1][z]) % MOD;  
                }
            }
        }
    }
    return ret;
}

int main(){
    cin >> n >> a >> b;
    digits.resize(n);
    for(auto &x : digits)cin >> x;
    fillx(a-1);
    vector<vector<ll>> a1 = calcdp();
    x.clear();
    fillx(b);
    vector<vector<ll>> b1 = calcdp(); 
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        --l;--r;
        cout << ((b1[l][r] - a1[l][r] + MOD) % MOD) << '\n';
    }
}