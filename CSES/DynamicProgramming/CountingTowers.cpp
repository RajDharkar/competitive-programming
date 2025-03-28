#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

#define MOD 1000000007

//A / B = A * (MULTIPLICATIVE INVERSE OF B)

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;
    cin >> t;
    // cout << t << endl;
    while(t--){
        ll n;
        cin >> n;
        ll join[n+1];
        ll split[n+1];

        join[1] = 1;
        split[1] = 1;

        for(ll i = 2; i <= n; i++){
            join[i] = ((((join[i - 1])) * 2 ) % MOD + split[i-1]);
            split[i] = ((split[i-1] * 4) % MOD) + join[i-1];
        }

        cout << ((join[n] + split[n]) % MOD) << endl;

    }
}

