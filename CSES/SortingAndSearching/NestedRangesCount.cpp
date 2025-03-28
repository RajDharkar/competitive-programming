#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

struct Range{
    ll l, r, ind;
};


bool cmp(Range a, Range b){
    if(a.l == b.l)return a.r > b.r;
    return a.l < b.l;
}

int main(){
    ll n;
    cin >> n;
    vector<Range> ranges(n);
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        ranges[i] = {a, b, i};
    }

    sort(ranges.begin(), ranges.end(), cmp);

    ll minr = 2e9;

    ordered_set<pair<ll, ll>> prevEnds;
    vector<ll> one(n);


    for(ll i = n - 1; i >= 0; i--){
        one[ranges[i].ind] = prevEnds.order_of_key({ranges[i].r, n});
        prevEnds.insert({ranges[i].r, ranges[i].ind});
    }

    ll maxr = 0;                   
    vector<ll> two(n);

    prevEnds.clear();
    for(ll i = 0; i < n; i++){
        two[ranges[i].ind] = sz(prevEnds) - prevEnds.order_of_key({ranges[i].r, -1});
        prevEnds.insert({ranges[i].r, ranges[i].ind});
    }

    for(auto a : one){
        cout << a << " ";
    }
    cout << '\n';
    for(auto a : two){
        cout << a << " ";
    }
}


// // struct Line{
// //     ll x, ind;
// //     bool isLeft;
// // };

// // bool cmp(Line a, Line b){
// //     return a.x < b.x;

// // }

// // ll main(){
// //     ll n;
// //     cin >> n;
// //     vector<Line> lines;
// //     for(ll i = 0; i < n; i++){
// //         ll a, b;
// //         cin >> a >> b;
// //         Line left;
// //         left.x = a;
// //         left.ind = i;
// //         left.isLeft = 1;
// //         Line right;
// //         right.x = b;
// //         right.ind = i;
// //         right.isLeft = 0;
// //         lines.pb(left);
// //         lines.pb(right); 
// //    }
// // //    for(Line a : lines){
// // //        cout << a.isLeft << endl;
// // //    }
// //     sort(all(lines), cmp);

// //     vector<ll> one(n);
// //     vector<ll> two(n);
// //     set<pair<ll, ll>> sofar; 
// //     map<ll, ll> start_pos;   

// //     for(auto &a : lines){
// //         if(a.isLeft){
// //             sofar.insert({a.x, a.ind});
// //             start_pos[a.ind] = a.x;
// //         } else {
// //             if(!sofar.empty() && sofar.begin()->second != a.ind){
// //                 auto earliest = *sofar.begin();
// //                 one[earliest.second] = 1;
// //                 two[a.ind] = 1;
// //             }
// //             sofar.erase({start_pos[a.ind], a.ind});
// //         }
// //     }
// //     for(auto x : one){
// //         cout << x << " ";
// //     }
// //     cout << endl;
// //     for(auto x : two){
// //         cout << x << " ";
// //     }
// // }


