#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll n;
    cin >> n;

    multiset<ll> towers;
    ll count = 0;
    for(ll i = 0; i < n; i++){
        ll x;  
        cin >> x;

        // auto it = upper_bound(all(towers), x); //WRONG 

        auto it = towers.upper_bound(x);
        if(it == towers.end()){
            
        }   
        else{
            towers.erase(it);
        }
        towers.insert(x);

        /*
        gotta find the tower that has like number > x but is the smallest that meets this condition
        //basically upper_bound(x) on the values(does this work on a map in log (n)?)
        //then replace that tower value with x, if that doesnt exist, then just create a new tower
        with value x
        */
    }
    cout << sz(towers);
}

