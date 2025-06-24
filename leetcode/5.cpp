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

class Solution {
public:
    vector<vector<ll>> minAbsDiff(vector<vector<int>>& grid, int k) {
        ll n = sz(grid);
        ll m = sz(grid[0]);
        ll realans = 2e9;
        pii ind = {0, 0};
        vvi ret(n - k + 1, vi(m - k + 1));
        for(ll i = 0; i <= n - k; i++){
            for(ll j = 0; j <= m - k; j++){
                vector<ll> nums;
                bool works = 0;
                for(ll z = i; z < i + k; z++){
                    for(ll w = j; w < j + k; w++){
                        if(z >= n || w >= m){
                            works = 1;
                            break;
                        }
                        nums.pb(grid[z][w]);
                    }
                    if(works) break;
                }
                if(works) continue;
                ll ans = 2e9;
                sort(all(nums));
                nums.erase(unique(nums.begin(), nums.end()), nums.end());
                for(ll t = 1; t < sz(nums); t++){
                    ans = min(ans, abs(nums[t] - nums[t-1]));
                }
                if(sz(nums) == 1)ans = 0;                  
                ret[i][j] = ans;
            }
        }
        return ret;
    }
};

// ll main(){
//     fastio
//     Solution s;
//     ll n, m, k;
//     cin >> n >> m >> k;

//     vvi test(n, vi(m));
//     for(ll i = 0; i < n; i++){
//         for(ll j = 0; j < m; j++){
//             cin >> test[i][j];
//         }
//     }

//     for(auto &x : s.minAbsDiff(test, k)){
//         for(auto &y : x){
//             cout << y << " ";
//         }
//         cout << '\n';
//     }
// }
