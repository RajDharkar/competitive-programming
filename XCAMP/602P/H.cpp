#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

struct x{
    string s;
    ll a, b, c;
};

bool positiveA(x a, x b){
    return a.b < b.b;
}

bool negativeA(x a, x b){
    return a.c > b.c;
}

const ll MAX = 90005; //tspmo icl
ll dp[301][90005]; //index, open

int main(){
    ll n;
    cin >> n;
    vector<x> arr(n);

    auto getA = [](string st) -> ll {
        ll open = 0;
        for(ll i = 0; i < sz(st); i++){
            open += st[i] == '(';
        }
        return open - (sz(st) - open);
    };

    auto getB = [](string st) -> ll{
        ll ans = 0;
        ll open = 0;
        ll closed = 0;
        for(ll i = 0; i < sz(st); i++){
            open += st[i] == '(';
            closed += st[i] == ')';
            ans = max(ans, closed - open);
        }
        return ans;
    };

    auto getC = [](string st) -> ll{
        ll ans = 0;
        ll open = 0;
        ll closed = 0;
        for(ll i = sz(st)-1; i>=0; i--){
            open += st[i] == '(';
            closed += st[i] == ')';
            ans = max(ans, open - closed);
        }
        return ans;
    };

    for(auto &l : arr)cin >> l.s;
    for(ll i = 0; i < n; i++){
        arr[i].a = getA(arr[i].s);
        arr[i].b = getB(arr[i].s);
        arr[i].c = getC(arr[i].s);
    }

    vector<x> apos;
    vector<x> aneg;
    for(ll i = 0; i < n; i++){
        if(arr[i].a >= 0){
            apos.pb(arr[i]);
        } else{
            aneg.pb(arr[i]);
        }
    } 

    sort(all(apos), positiveA);
    sort(all(aneg), negativeA);

    for(ll i = 0; i < sz(aneg); i++){
        apos.pb(aneg[i]);
    }
    //?? HOLy JOHN I JUST IMPLEMENTED THAT WITHOUT ERRORS FIRST TRY
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(ll i = 1; i <= n; i++){
        //if u take it then
        //NET OPEN IS A  
        ll a = apos[i-1].a;
        ll b = apos[i-1].b;
        ll size = sz(apos[i-1].s);
        for(ll j = 0; j < MAX; j++){
            if(dp[i-1][j] == -1)continue;
            if(j + a >= MAX)cout << j << " " << a << endl; 
            if(j+a >= 0 && j + a < MAX && j >= b){ //j >= b makes sure ))(( is invalid
                dp[i][j+a] = max(dp[i][j+a], size+dp[i-1][j]); 
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[n][0];
}
