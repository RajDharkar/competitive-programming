#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll n;
    cin >> n;
    vector<ll> ans;
    while(n > 0){
        ans.pb(n%2);
        n/=2;
    }
    reverse(all(ans));
    for(auto x : ans){
        cout << x;
    }
}

