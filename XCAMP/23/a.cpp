#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(0);  

    ll n, p;
    cin >> n >> p;

    vector<ll> arr(n);
    for (auto &a : arr) cin >> a;
    if (p==1){
        vector<ll> left_to_be(n);
        ordered_set left, right;
        for (ll i = 0; i < n; i++) {
            right.insert({arr[i] + i, i});
            left_to_be[i] = arr[n - i - 1] + i;  
        }

        reverse(left_to_be.begin(), left_to_be.end());

        vector<ll> ans;
        for (ll i = 0; i < n; i++) {
            ll left_count = 0, right_count = 0;
            if (!left.empty()) {
                left_count = left.order_of_key({left_to_be[i], 0}); 
            }
            right_count = right.order_of_key({arr[i] + i, 0});      
            // cout << left_count << " " << right_count << endl;
            ans.push_back(left_count + right_count);
            left.insert({left_to_be[i], i}); 
            right.erase(right.find({arr[i] + i, i})); 
        }

        for (auto x : ans) cout << x + 1 << '\n';
    }
    else{

        //1 2 4 2 5 3 9 
        vector<ll> normalans;
        ordered_set le;
        ordered_set ri;
        le.insert({arr[0], 0});
        for(int i = 1; i < n; i++)ri.insert({arr[i], i});
        for(int i = 1; i < n/2; i++){
            ri.erase(ri.find({arr[i], i}));
            ll left_count = 0, right_count = 0;
            right_count = ri.order_of_key({arr[i] + i, 0}); //remember to add 1
        }

        vector<ll> left;
        vector<ll> right;
        vector<ll> both;
        for(int i = 0; i < n; i++){
            right.push_back(arr[i]+i);
            left.push_back(arr[n-i-1]+i);
        }               
        reverse(left.begin(), left.end());
        for(int i =0;i<n;i++){
            both.push_back(min(right[i], left[i]));
        }
        vector<ll> origl(left);
        vector<ll> origr(right);
        vector<ll> origb(both);
        sort(both.begin(), both.end());
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        vector<ll> ans;
        for(ll i=0;i<n;i++){
            ll lb_both = lower_bound(both.begin(), both.end(), origb[i]) - both.begin();
            ll lb_left = lower_bound(left.begin(), left.end(), origl[i]) - left.begin();
            ll lb_right = lower_bound(right.begin(), right.end(), origr[i]) - right.begin();
            // cout << lb_left << " " << lb_right << endl;
            ans.push_back(max({lb_left, lb_right, lb_both}));
            if(lb_both > lb_right && lb_both > lb_left){
                cout << "HOEHWIOHERWE " << i << endl;
            }
        }   
        for(auto x : ans)cout << x+1 << '\n';
    }
}
