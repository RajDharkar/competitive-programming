#include <bits/stdc++.h>
#include "C:\Users\rajve\Documents\GitHub\competitive-programming\debugging.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
vector<vector<pii>> adj;

ll found = 0;

ll brute_dfs(ll node, ll parent, ll k)
{
    vector<ll> edge_lengths;
    for (auto [lower, length] : adj[node])
    {
        if (lower == parent)
        {
            continue;
        }
        ll le = brute_dfs(lower, node, k);
        if (length + le >= k)
        {
            found++;
        }
        else
        {
            edge_lengths.push_back(length + le);
        }
    }
    sort(edge_lengths.begin(), edge_lengths.end());
    if (edge_lengths.empty())
        return 0;
    if (int(edge_lengths.size() == 1)){
        return edge_lengths[0];
    }
    ll lp = 0, rp = edge_lengths.size() - 1;
    int oldlp = 0, ret = 0;
    vector<pair<ll, ll>> pairs;
    while (lp < rp){
        oldlp = lp;
        if (lp != rp && edge_lengths[lp] + edge_lengths[rp] >= k){
            found++; // Pair found
            // cout << edge_lengths[lp] << " " << edge_lengths[rp] << endl;
            pairs.push_back({edge_lengths[lp], edge_lengths[rp]});
            rp--;
            lp++;
        }
        else{
            ret = lp;
            lp++;
        }
    }
    // cout << edge_lengths << endl;
    if((int)(pairs.size()) == 0){
        return *--edge_lengths.end();
    }
    if ((int)(pairs.size()) * 2 == (int)(edge_lengths.size())) {
        return 0;
    }
    if (lp == rp)
        ret=lp;
    ll highedge = edge_lengths[ret];
    for (int i = 0; i < (int)pairs.size(); i++)
    {
        if (k - pairs[i].first <= highedge && highedge < pairs[i].second)
        {
            swap(highedge, pairs[i].second);
        }
        else if (k - pairs[i].second <= highedge && highedge < pairs[i].first)
        {
            swap(highedge, pairs[i].first);
        }
        // cout << pairs[i] << endl;
    }
    //cout << highedge << endl;
    return highedge;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
        adj[b - 1].push_back({a - 1, c});
    }
    // for(int i = 1; i <= 20; i++){
    //     found = 0;
    //     brute_dfs(0, 0, i);
    //     cout << i << " " << found << endl;
    // }
    ll lo = 1, hi = 1e9;
    while (lo < hi)
    {
        ll mid = lo + (hi - lo + 1) / 2;
        found = 0;
        brute_dfs(0, 0, (mid));
        if (found >= m) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }       
    cout << lo;
}