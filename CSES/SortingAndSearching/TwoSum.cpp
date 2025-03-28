#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(auto &x:arr)cin >> x;
    map<ll, vector<ll>> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]].push_back(i+1);
    }
    // cout << mp[500000000] << endl;
    // cout << mp[1] << endl;
    for (int i = 0; i < n; i++) {
        if (mp[x - arr[i]].size()) {
            if (arr[i] == x - arr[i]) { 
                if (mp[arr[i]].size() > 1) {
                    cout << mp[arr[i]][0] << " " << mp[arr[i]][1] << endl;
                    return 0;
                }
            } else {
                cout << mp[arr[i]][0] << " " << mp[x - arr[i]][0] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
}


