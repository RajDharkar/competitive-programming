#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr)cin >> x;
    map<int, int> mp;
    
    for(auto x : arr){
        mp[x]++;
    }
//01.03.2025.
    if(mp[0] < 3 || mp[1] < 1 || mp[2] < 2 || mp[3] < 1 || mp[5] < 1){
        // cout << mp[3] << endl;
        cout << 0 << '\n';
        return;
    }
    mp.clear();
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
        if(mp[0] < 3 || mp[1] < 1 || mp[2] < 2 || mp[3] < 1 || mp[5] < 1){
            
        } else{
            cout << (i+1) << endl;
            return;
        }
    }
        
}

int main(){

    int t;
    cin >> t;
    while(t--)solve();
}


