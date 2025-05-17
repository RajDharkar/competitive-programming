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

class Solution {
public:
    bool canPartitionGrid(const vector<vector<ll>>& grid) {
        ll n = sz(grid);
        ll m = sz(grid[0]);
        vector<vector<ll>> pref(n, vector<ll>(m));
        pref[0][0]=grid[0][0];
        for(ll i = 1; i < m; i++){pref[0][i] = grid[0][i]+pref[0][i-1];};
        for(ll i = 1; i < n; i++){
            pref[i][0] = pref[i-1][0]+grid[i][0];
            for(ll j = 1; j < m; j++){
                // cout << pref[i][j-1] << " " << pref[i-1][j] << " " << pref[i-1][j-1] << '\n';
                pref[i][j] = pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1] + grid[i][j];
            }
        } 
        // ll sum = 0;
        // for(ll i = 0; i < n; i++)  
            // sum += accumulate(all(grid[i]), 0LL);
        // cout << sum << " " << pref[n-1][m-1];
        ll sum = pref[n-1][m-1];
        for(ll i = 1; i < n; i++){
            if(pref[i-1][m-1] == sum - pref[i-1][m-1]){
                return true;
            }
        }
        for(ll i = 1; i < m; i++){
            if(pref[n-1][i-1] == sum - pref[n-1][i-1]){
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    cout << s.canPartitionGrid({{1, 3}, 
                                {2, 2}}); //ans
}