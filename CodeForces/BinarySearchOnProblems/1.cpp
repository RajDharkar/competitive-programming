#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
using db = double;
int main(){
    ll n, l;
    cin >> n >> l;
    vector<ll> lamps;
    for(int i = 0; i < n; i++){
        ll k;
        cin >> k;
        lamps.pb(k);
    }

    sort(all(lamps));

    db maxdistance = -1;
    for(int i = 1; i < n; i++){
        maxdistance = max(maxdistance, db((lamps[i]-lamps[i-1]) / 2.0));
    }

    maxdistance = max(maxdistance, (db)lamps[0]);
    maxdistance = max(maxdistance, (db)(l - lamps[n-1]));
    cout << setprecision(20) << maxdistance << endl;
}

