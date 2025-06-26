#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);  

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)


int main(){
    fastio
    ll q;
    cin >> q;
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c; 
        ll ta = a, tb = b, tc = c;
        ll dp[3][2][2]; 
        memset(dp, 0LL, sizeof(dp)); dp[1][0][0]=1;
        for(ll i = 0; i < 39; i++){
            ll dp2[3][2][2];
            // fill(dp2, dp2 + 3, 0LL);
            memset(dp2, 0LL, sizeof(dp2));
            ll dd = ta % 3, xd = tb % 3, yd = tc % 3;
            ta /= 3, tb /= 3, tc /= 3;
            for(ll j = 0; j < 3; j++){
                for(ll xc = 0; xc < 2; xc++){
                    for(ll yc = 0; yc < 2; yc++){
                        for(ll digit = 0; digit < 3; digit++){
                            ll nextx = xd + xc + digit;
                            ll nexty = yd + yc + digit;
                            ll xdig = nextx % 3;
                            ll ydig = nexty % 3;
                            ll xcar = nextx / 3;
                            ll ycar = nexty / 3;
                            if(xdig % 2 == ydig % 2){
                                int cmp = j;
                                if(digit < dd){
                                    cmp=0;
                                } 
                                if(digit > dd){
                                    cmp=2;
                                }
                                dp2[cmp][xcar][ycar] += dp[j][xc][yc];
                            }
                        }
                    }
                }
            }
            swap(dp, dp2);
        }
        ll sum = 0;
        for(ll i = 0; i < 2; i++)sum += dp[i][0][0]; cout << sum << '\n';
    }


    // ll grid[50][50];
    // ll n = 50;
    // for(ll i = 0; i < n; i++){
    //     for(ll j = 0; j < n; j++){
    //         ll temp = i, temp2 = j;
    //         bool w = 1;
    //         while(temp > 0 || temp2 > 0){
    //             w &= temp % 3 % 2 == temp2 % 3 % 2;
    //             temp /= 3;
    //             temp2 /= 3;
    //         }
    //         grid[i][j] = w;
    //     }
    // }

    // for(ll i = 0; i < n; i++){
    //     for(ll j = 0; j < n; j++){
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }
}