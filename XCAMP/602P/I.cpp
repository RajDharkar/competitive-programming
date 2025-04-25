#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

struct Friend{
    ll p, c, x; 
};

const ll MAX = 2001;
ll dp[MAX][MAX+MAX]; //current index, money spent, k cones = maximum popularity

bool cmp(Friend a, Friend b){
    return a.x < b.x;
}

//i wish i understood this solution more but i don't :( i'll watch lecture recording after //
int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    vector<Friend> vf(n);
    for(ll i = 0; i < n; i++){
        cin >> vf[i].p >> vf[i].c >> vf[i].x;
    }
    sort(all(vf), cmp);

    memset(dp, -1, sizeof dp);
    dp[0][a+b]=0;
    for(ll i = 0; i < n; i++){
        ll cost = vf[i].c;
        ll discount = vf[i].x;
        ll pop = vf[i].p;
        
        for(ll j = 0; j <= a + b; j++){ //money left + discounts left, discounts = min(a, )
            if(dp[i][j] == -1)continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            //cost * discount = money required to fully discount a freidn
            if(j >= a + cost * discount){ //PAY FULLY
                dp[i + 1][j - cost * discount] = max(dp[i+1][j-cost*discount], dp[i][j] + pop);
            } else if(j > a){ //use ase many discounts as possible, then switch to cash
                ll remaining = cost - (j - a) / discount;
                if(a - remaining >= 0) //i dont really understand why we need this?
                    dp[i+1][a - remaining] = max(dp[i+1][a - remaining], dp[i][j]+pop);
            } else if(j <= a && j >= cost){ //pay ALL in discounts, no cash
                dp[i+1][j-cost] = max(dp[i+1][j-cost], dp[i][j]+pop); //j = cost + discounts, so j - cost = discounts :)
            } 
        }
    }
    ll mx = 0;
    for(ll i = 0; i <= a+b; i++){
        mx = max(dp[n][i], mx);
    }
    cout << mx;
}

              