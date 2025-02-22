#include <bits/stdc++.h>
#include "C:\Users\rajve\Documents\GitHub\competitive-programming\debugging.h"
using namespace std;


typedef long long ll;
ll dfs_found = 0;
namespace Solution1{
    ll solve(vector<ll> arr, ll k){
        multiset<ll> edge_lengths;
        for(int i = 0; i < int(arr.size()); i++){
            edge_lengths.insert(arr[i]);
        }
        while (!edge_lengths.empty()) {
            int len = *edge_lengths.rbegin();
            edge_lengths.erase(--edge_lengths.end());
            auto it = edge_lengths.lower_bound(k - len);
            //cout << len << " " << *it << endl;
            if (it == edge_lengths.end()) return len;
            else {
                dfs_found++;
                edge_lengths.erase(it);
            }            
        }
        return 0;
    }
}

namespace Solution2{
    ll solve(vector<ll> edge_lengths, ll k){
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
            if (lp != rp && edge_lengths[lp] + edge_lengths[rp] >= k){
                dfs_found++; 
                pairs.push_back({edge_lengths[lp], edge_lengths[rp]});
                rp--;
                lp++;
            }
            else{
                ret = lp;
                lp++;
            }
        }
        for(auto [a, b] : pairs){
            cout << a << " " << b << endl;
        }
        if((int)(pairs.size()) == 0){
            return *--edge_lengths.end();
        }
        if ((int)(pairs.size()) * 2 == (int)(edge_lengths.size())) {
            return 0;
        }
        if (lp == rp)
            ret=lp;
        cout<<ret<<endl;    
        ll highedge = edge_lengths[ret];
        for (int i = 0; i < (int)pairs.size(); i++){
            if ((k <= (highedge + pairs[i].first)) && (highedge < pairs[i].second)){
                cout<<1;
                swap(highedge, pairs[i].second);
            }
            if (k - pairs[i].second <= highedge && highedge < pairs[i].first){
                cout<<0<<endl;
                swap(highedge, pairs[i].first);
            }
        }
        return highedge;
    }
}

//im learning stress testing lol
int main(){
    mt19937 rng(0);
    ll t;
    cin >> t;
    
    // Custom test case
    vector<ll> custom_arr = {0, 1, 1, 2, 50, 50, 99};
    // ll n;
    // cin >> n;
    // vector<ll> custom_arr;
    // for(int i = 0; i < n; i++){
    //     cin >> custom_arr[i];
    // }
    ll custom_k = 14;
    
    dfs_found = 0;
    ll custom_out1 = Solution1::solve(custom_arr, custom_k);
    ll custom_dfs1 = dfs_found;
    
    dfs_found = 0;
    ll custom_out2 = Solution2::solve(custom_arr, custom_k);
    ll custom_dfs2 = dfs_found;
    
    cout << "Custom Test Case:\n";
    cout << "arr: ";
    for(ll x : custom_arr) cout << x << " ";
    cout << "\nk: " << custom_k << endl;
    cout << "out1: " << custom_out1 << ", out2: " << custom_out2 << endl;
    cout << "dfs1: " << custom_dfs1 << ", dfs2: " << custom_dfs2 << endl;
    
    if(custom_out1 != custom_out2 or custom_dfs1 != custom_dfs2){
        cout << "Mismatch FOUND in Custom Test!\n";
        return 1;
    }
    
    // Randomized stress test
    while(t--){
        ll n = rng() % 100;
        n++;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++){
            arr[i] = rng() % 100;
        }
        ll k = rng() % 100;
        dfs_found = 0;
        ll out1 = Solution1::solve(arr, k);
        ll dfs1 = dfs_found;
        dfs_found = 0;
        ll out2 = Solution2::solve(arr, k);
        ll dfs2 = dfs_found;
        
        if(out1 != out2 or dfs1 != dfs2){
            cout << "Mismatch FOUND in Stress Test!\n";
            cout << "n: " << n << endl;
            cout << "arr: ";
            sort(arr.begin(), arr.end());
            cout << arr << endl;
            cout << "k: " << k << endl;
            cout << "out1: " << out1 << ", out2: " << out2 << endl;
            cout << "dfs1: " << dfs1 << ", dfs2: " << dfs2 << endl;
            return 1;
        }
    }
}
