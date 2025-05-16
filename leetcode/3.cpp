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
    vector<vector<ll>> adj;
    long long maxScore(int n, const vector<vector<int>>& edges) {
        if(n == 2)return 2;
        adj.resize(n);
        for(ll i = 0; i < sz(edges); i++){
            ll a = edges[i][0], b = edges[i][1];
            adj[a].pb(b);
            adj[b].pb(a);
        }
        ll sm = 0;
        ll m = sz(edges);
        // if(m == n-1){
        //line
        vector<ll> ans(n);
        ll mi = n/2;
        ll l = mi-1, r = mi+1;
        ans[mi]=n;
        ll cnt = n-1;
        while(cnt > 0){
            if(ans[l] == 0){
                ans[l] = cnt--;
            }
            if(ans[r] == 0){
                ans[r] = cnt--;
            } 
            l--;r++;
            if(l < 0 && r >= n)break;
            if(l < 0)l++; if(r >= n)r--;
        }
        ll ret = 0;
        // cout << ans[0] << " "; 
        for(ll i=1; i < n; i++){
            ret+=ans[i]*ans[i-1];
            // cout << ans[i] << " ";
        }
        if(m != n-1)ret += ans[0] * ans[n-1];
        return ret;
    }
};

int main(){
    Solution s;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> query;
    while(m--){
        vector<int> in(2);
        cin >> in[0] >> in[1];
        query.pb(in);
    }
    cout << s.maxScore(n, query); //ans
}