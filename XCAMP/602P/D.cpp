#include<bits/stdc++.h>

 
//order_of_key(k) :Number of items strictly smaller than k.
//find_by_order : K-th smallest element. (0-index)
//for multiset erase with ost.erase(ost.upper_bound(x));

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


int main(){
    ll n;
    cin >> n;

    //im literally so sorry but im so tired rn and I PrOmise ill do the segtree search way after my flight
    ordered_set<ll> ost;
    while(n--){
        char a;
        ll k;
        cin >> a >> k;
        if(a == 'I'){
            ost.insert(k);
        } else if(a == 'D'){
            auto i = ost.find(k);
            if(i != ost.end())
                ost.erase(i);
        } else if(a == 'C'){
            cout << ost.order_of_key(k) << '\n';
        } else{
            k--;
            if(k >= sz(ost)){
                cout << "invalid" << '\n';
                continue;
            }
            cout << *ost.find_by_order(k) << '\n';
        }
    }
}


