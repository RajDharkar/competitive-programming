#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[1000001];

int main(){
    ll n;
    cin >> n;
    fill(dp, dp + 1000001, 1e9);
    dp[n] = 0;
    for(ll i = n; i >= 0; i--){
        ll num = i;
        while(num != 0){
            if(i - (num % 10) >= 0)
                dp[i - (num % 10)] = min(dp[i - (num % 10)], dp[i]+1);
            num /= 10;
        }
    }

    cout << dp[0] << '\n';
}